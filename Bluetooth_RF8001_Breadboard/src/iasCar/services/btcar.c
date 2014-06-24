/*
 * iascar.c
 *
 * Created: 22.05.2014 11:56:59
 *  Author: Friedrich Maeckle
 */

#include "btcar.h"
#include "bluetooth.h"
#include "bt_active_led.h"

void car_bluetooth_setup(void) {
	
	// Setup LED
	bluetooth_led_setup();
	
	// Setup BT Driver
	bluetooth_config_t bluetooth_config;
	bluetooth_get_config_defaults(&bluetooth_config);
	bluetooth_init(&bluetooth_config);
	
}

// Process the bluetooth data
void car_bluetooth_process(void) {
	bluetooth_process();
}