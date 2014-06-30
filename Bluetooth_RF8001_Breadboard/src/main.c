/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include "bluetooth/BluetoothCar.h"

uint8_t hornState;
uint16_t button;
uint16_t button2;
uint16_t genericActor1State;

int main (void) {
	
	board_init();
	sysclk_init();
	// Max 10 chars
	carBluetoothSetup("BlaBlaCar");
	
	while(true) {
		carBluetoothProcess();
		
		hornState = bluetoothGetHorn();
		genericActor1State = bluetoothGetGenericActor1();
		
		button = ioport_get_pin_level(GPIO_PUSH_BUTTON_0);
		button2 = ioport_get_pin_level(GPIO_PUSH_BUTTON_1);
		
		bluetoothSetBrightness(button);
		bluetoothSetDistanceUSFront(button2);
		
		if(genericActor1State == 0x0001) {
			LED_On(LED1);
		} else {
			LED_Off(LED1);
		}
	}
	
}
