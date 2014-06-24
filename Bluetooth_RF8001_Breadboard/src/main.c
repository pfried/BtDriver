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
#include "btcar.h"

int main (void) {
	
	board_init();
	sysclk_init();
	car_bluetooth_setup();

	// Insert application code here, after the board has been initialized.
	LED_On(LED1);
	
	//deselect_bluetooth_spi();
	while(true) {
		car_bluetooth_process();
	}
	
}
