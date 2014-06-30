/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the Bluetooth Driver
 */ 

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <ioport.h>
#include <spi_master.h>
#include <stdint.h>
#include <delay.h>
#include "lib/lib_aci.h"
#include "lib/aci_setup.h"
#include "lib/services.h"
#include "../../services/btcar.h"


#define BLUETOOTH_DATA_RATE 1

#define BLUETOOTH_RX_BUFFER_SIZE 8
#define BLUETOOTH_TX_BUFFER_SIZE 8

// Defining missing statements for the driver
#define OUTPUT IOPORT_DIR_OUTPUT
#define INPUT IOPORT_DIR_INPUT
#define INPUT_PULLUP IOPORT_PULL_UP

#define LSBFIRST 1
#define MSBFIRST 0

#define SPI &SPIC

// Define PINS
#define REQN   IOPORT_CREATE_PIN(PORTC, 3)
#define RDYN   IOPORT_CREATE_PIN(PORTC, 2)
#define BT_RST IOPORT_CREATE_PIN(PORTC, 1)
#define MOSI   IOPORT_CREATE_PIN(PORTC, 5)
#define MISO   IOPORT_CREATE_PIN(PORTC, 6)
#define SCK    IOPORT_CREATE_PIN(PORTC, 7)
#define SS     IOPORT_CREATE_PIN(PORTC, 4)

#define TEMPERATURE_TIMER_RESOLUTION 1

/*! \brief Bluetooth driver struct
 *
 */
typedef struct bluetooth_config  {
	// The SPI to use
	SPI_t *spi;
	// The SPI Device, Slave Select
	port_pin_t rdyn_pin;
	port_pin_t reqn_pin;
} bluetooth_config_t;

// Interrupt callback type
typedef void (*bt_callback_t)(void);

void bluetooth_init(bluetooth_config_t *bluetooth_config, bluetooth_car_t *bluetooth_car);
void bluetooth_process(void);
void bluetooth_values_process(void);

bool digitalRead(port_pin_t pin);
void digitalWrite(port_pin_t pin, bool value);
void pinMode(port_pin_t pin,ioport_mode_t mode);
void delay(uint16_t ms);

void interrupts(void);
void noInterrupts(void);

void attachInterrupt(port_pin_t pin, void (*f)(void), bool level);
void detachInterrupt(port_pin_t pin);

void spi_init_pins(void);

void spi_lsb_first(SPI_t *spi);
void spi_msb_first(SPI_t *spi);

uint8_t spi_readwrite_xmega(uint8_t *aci_byte);

void bluetooth_get_config_defaults(bluetooth_config_t *bluetooth_config);

#endif /* BLUETOOTH_H_ */