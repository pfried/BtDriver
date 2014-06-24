/*
 * bluetooth.c
 *
 * Created: 21.05.2014 16:56:43
 *  Author: Friedrich Maeckle
 */

#include <asf.h>
#include "bluetooth.h"

#ifdef SERVICES_PIPE_TYPE_MAPPING_CONTENT
/* Services pipes generated by nRFGo Studio from Nordic Semiconductor */
static services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
#else
#define NUMBER_OF_PIPES 0
static services_pipe_type_mapping_t * services_pipe_type_mapping = NULL;
#endif

/* Setup for the nRF8001 bluetooth chip in flash */
static hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

static aci_state_t aci_state;

static hal_aci_evt_t aci_data;
static hal_aci_data_t aci_cmd;

static bool radio_ack_pending  = false;
static bool timing_change_done = false;

// Interrupt handler
static bt_callback_t bt_callback;

// Interrupt Vector PORTC
#if XMEGA_E5
ISR(PORTC_INT_vect) {
	if(bt_callback) {
		bt_callback();
		// Clear the Interrupt, no idea why it doesnt get cleared in ISR
		PORTC.INTFLAGS |= PORT_INT2IF_bm;
	}
}
#endif

#if XMEGA_A
ISR(PORTC_INT0_vect) {
	if(bt_callback) {
		bt_callback();
		// Clear the Interrupt, no idea why it doesnt get cleared in ISR
		PORTC.INTFLAGS |= PORT_INT2IF_bm;
	}
}
#endif

// Implementing missing functions from arduino port
bool digitalRead(port_pin_t pin) {
	return ioport_get_pin_level(pin);
}

void digitalWrite(port_pin_t pin, bool value) {
	ioport_set_pin_level(pin, value);
}

void pinMode(port_pin_t pin,ioport_mode_t mode) {
	ioport_set_pin_mode(pin, mode);
}

void delay(uint16_t ms) {
	delay_ms(ms);
}

void interrupts(void) {
	sei();
}

void noInterrupts(void) {
	cli();
}

void spi_lsb_first(SPI_t *spi) {
	spi->CTRL |= (1 << SPI_DORD_bm);
}

void spi_msb_first(SPI_t * spi) {
	spi->CTRL &= ~(1 << SPI_DORD_bm);
}

uint8_t spi_readwrite_xmega(uint8_t *aci_byte)
{
	uint8_t data;
	spi_write_single(&SPIC, aci_byte);
	while(spi_is_rx_ready(&SPIC) == false) {}
	spi_read_single(&SPIC, &data);
	return data;
}

void spi_init_pins(void) {
	ioport_configure_port_pin(&PORTC, PIN1_bm, IOPORT_PULL_DOWN | IOPORT_DIR_OUTPUT);   //PIN 1 RESET
	ioport_configure_port_pin(&PORTC, PIN2_bm, IOPORT_PULL_UP   | IOPORT_DIR_INPUT);    //PIN 2 RDYN
	ioport_configure_port_pin(&PORTC, PIN3_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);	//PIN 3 Slave Select / REQ
	ioport_configure_port_pin(&PORTC, PIN4_bm, IOPORT_PULL_UP | IOPORT_DIR_INPUT);		//PIN 4 Pull_Up (pull low -> slave mode)
	ioport_configure_port_pin(&PORTC, PIN5_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);	//PIN 5 MOSI out
	ioport_configure_port_pin(&PORTC, PIN6_bm, IOPORT_DIR_INPUT);						//PIN 6 MISO
	ioport_configure_port_pin(&PORTC, PIN7_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);	//PIN 7 SCL out
}

void attachInterrupt(port_pin_t pin, void (*f)(void), bool level) {
	// Attach the interrupt to our handler
	bt_callback = f;
	// Activate the interrupt on the pin
	#if XMEGA_E
	PORTC.INTMASK |= PIN2_bm;
	#endif
	
	#if XMEGA_A
	PORTC.INT0MASK |= PIN2_bm;
	#endif
}

void detachInterrupt(port_pin_t pin) {
	// Deactivate the interrupt on the pin
	#if XMEGA_E
	PORTC.INTMASK |= ~PIN2_bm;
	#endif
	
	#if XMEGA_A
	PORTC.INT0MASK |= ~PIN2_bm;
	#endif
}


void bluetooth_init(bluetooth_config_t *bluetooth_config) {
	
	spi_init_pins();

	/**
	Point ACI data structures to the the setup data that the nRFgo studio generated for the nRF8001
	*/
	if (NULL != services_pipe_type_mapping)
	{
	aci_state.aci_setup_info.services_pipe_type_mapping = &services_pipe_type_mapping[0];
	}
	else
	{
	aci_state.aci_setup_info.services_pipe_type_mapping = NULL;
	}
  
	aci_state.aci_setup_info.number_of_pipes    = NUMBER_OF_PIPES;
	aci_state.aci_setup_info.setup_msgs         = setup_msgs;
	aci_state.aci_setup_info.num_setup_msgs     = NB_SETUP_MESSAGES;
  
	/*
	Tell the ACI library, the MCU to nRF8001 pin connections.
	The Active pin is optional and can be marked UNUSED
	*/
	aci_state.aci_pins.board_name = BOARD_DEFAULT; // Set to default
	aci_state.aci_pins.reqn_pin   = bluetooth_config->reqn_pin;
	aci_state.aci_pins.rdyn_pin   = bluetooth_config->rdyn_pin;
	aci_state.aci_pins.mosi_pin   = MOSI;
	aci_state.aci_pins.miso_pin   = MISO;
	aci_state.aci_pins.sck_pin    = SCK;
  
	aci_state.aci_pins.spi = &SPIC;

	aci_state.aci_pins.reset_pin              = RST;
	aci_state.aci_pins.active_pin             = UNUSED;
	aci_state.aci_pins.optional_chip_sel_pin  = UNUSED;

	aci_state.aci_pins.interface_is_interrupt = true;
	aci_state.aci_pins.interrupt_number       = bluetooth_config->rdyn_pin;
	
	// Interrupt Config
	// Set the interrupt level on the port
	PORTC.PIN2CTRL |= PORT_ISC_FALLING_gc;
	
	// Set priority to low for PORTC
	#if XMEGA_E
	PORTC.INTCTRL |= PORT_INTLVL_LO_gc;
	#endif
	
	#if XMEGA_A
	PORTC.INTCTRL |= PORT_INT0LVL_LO_gc;
	#endif
	
	// Enable Low Level Interrupts on PMIC
	PMIC.CTRL |= PMIC_HILVLEN_bm | PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm;
	
	/** We reset the nRF8001 here by toggling the RESET line connected to the nRF8001
	*  and initialize the data structures required to setup the nRF8001
	*/
	//The second parameter is for turning debug printing on for the ACI Commands and Events so they be printed on the Serial
	lib_aci_init(&aci_state,false);
}

void bluetooth_process(void) {
	
	// The Setup needs to be transfered to the NRF8001 Chip on startup, flag indicates if we need to setup the device
	static bool setup_required = false;
	
	// Basically getting events from the event queue
	if(lib_aci_event_get(&aci_state, &aci_data)) {
		
		aci_evt_t * aci_evt;
		aci_evt = &aci_data.evt;
		
		switch(aci_evt->evt_opcode)
		{
			case ACI_EVT_DEVICE_STARTED:
			{
				aci_state.data_credit_total = aci_evt->params.device_started.credit_available;
				switch(aci_evt->params.device_started.device_mode)
				{
					case ACI_DEVICE_SETUP:
						/**
						When the device is in the setup mode
						*/
						setup_required = true;
						break;

					case ACI_DEVICE_STANDBY:
						//Looking for a Phone by sending radio advertisements
						//When an iPhone connects to us we will get an ACI_EVT_CONNECTED event from the nRF8001
						if (aci_evt->params.device_started.hw_error)
						{
							delay(20); //Handle the HW error event correctly.
						}
						else
						{
							lib_aci_connect(0/* in seconds : 0 means forever */, 0x0050 /* advertising interval 50ms*/);
						}

						break;
				}
				break; //ACI Device Started Event
			}
			
			case ACI_EVT_CONNECTED:
			{
				// Set the available credits
				aci_state.data_credit_available = aci_state.data_credit_total;
				timing_change_done = false;

				//Get the device version of the nRF8001 and store it in the Hardware Revision String
				lib_aci_device_version();
				LED_On(LED0);
				break;
			}
			
			case ACI_EVT_DISCONNECTED:
			{
				lib_aci_connect(0/* in seconds  : 0 means forever */, 0x0050 /* advertising interval 50ms*/);
				LED_Off(LED0);
				break;
			}
			
			// We receive data from the Central
			case ACI_EVT_DATA_RECEIVED:
			{
				LED_Toggle(LED1);
				switch(aci_evt->params.data_received.rx_data.pipe_number) {
					// Speed and Angle
					case PIPE_DRIVE_SPEEDANDANGLE_RX:
					{
						break;
					}
					
					// Speed Mode
					case PIPE_DRIVE_SPEEDMODE_RX_ACK_AUTO:
					{
						break;
					}
					
					// Sensor Sevo
					case PIPE_DISTANCE_SENSORSERVO_RX:
					{
						break;
					}
					// The Horn, m�p m�p
					case PIPE_HORN_HORN_RX:
					{
						break;
					}
					// The lights and blinkers
					case PIPE_LIGHTS_LIGHTS_RX_ACK_AUTO:
					{
						break;
					}
					// The Generic Actors
					case PIPE_GENERIC_GENERICACTOR1_RX_ACK_AUTO:
					{
						break;
					}
					case PIPE_GENERIC_GENERICACTOR2_RX_ACK_AUTO:
					{
						break;
					}
					
				}
				break;
			}
			
			// Central received data
			case ACI_EVT_DATA_ACK:
			{
				break;
			}
			
			case ACI_EVT_BOND_STATUS:
			{
				break;
			}
			
			case ACI_EVT_PIPE_STATUS:
			{
				/** check if the peer has subscribed to the Heart Rate Measurement Characteristic for Notifications
				*/
				LED_Toggle(LED0);
				if (lib_aci_is_pipe_available(&aci_state, PIPE_BRIGHTNESS_BRIGHTNESS_TX) && (false == timing_change_done) )
				{
					/*
					Request a change to the link timing as set in the GAP -> Preferred Peripheral Connection Parameters
					Change the setting in nRFgo studio -> nRF8001 configuration -> GAP Settings and recompile the xml file.
					*/
					lib_aci_change_timing_GAP_PPCP();
					timing_change_done = true;
				}
				break;
			}
			
			// Transmission Failure
			case ACI_EVT_PIPE_ERROR:
			{
				break;
			}
			
			
			// Credits limit the command buffer available on the nRF8001, if a command is executed we are notified by the return of a credit
			case ACI_EVT_DATA_CREDIT:
			{
				aci_state.data_credit_available = aci_state.data_credit_available + aci_evt->params.data_credit.credit;
				/**
				Bluetooth Radio ack received from the peer radio for the data packet sent.
				This also signals that the buffer used by the nRF8001 for the data packet is available again.
				*/
				radio_ack_pending = false;
				break;
			}

			case ACI_EVT_CMD_RSP:
			{
				//If an ACI command response event comes with an error -> stop
				if (ACI_STATUS_SUCCESS != aci_evt->params.cmd_rsp.cmd_status)
				{
					//ACI ReadDynamicData and ACI WriteDynamicData will have status codes of
					//TRANSACTION_CONTINUE and TRANSACTION_COMPLETE
					//all other ACI commands will have status code of ACI_STATUS_SCUCCESS for a successful command
				}
				break;
			}
			
			case ACI_EVT_ECHO:
			{
				break;
			}
			
			case ACI_EVT_TIMING:
			{
				break;
			}
			
			case ACI_EVT_HW_ERROR:
			{
				break;
			}
			
		}
	}
	
	if(setup_required)
	{
		if (SETUP_SUCCESS == do_aci_setup(&aci_state))
		{
			//LED_On(LED0);
			setup_required = false;
		}
	}		
	
}



void bluetooth_get_config_defaults(bluetooth_config_t *bluetooth_config) {
	bluetooth_config->spi = &SPIC;
	bluetooth_config->reqn_pin = REQN;
	bluetooth_config->rdyn_pin = RDYN;
}