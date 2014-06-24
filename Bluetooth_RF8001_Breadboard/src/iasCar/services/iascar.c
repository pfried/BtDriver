/*
 * iascar.c
 *
 * Created: 22.05.2014 11:56:59
 *  Author: Friedrich Maeckle
 */

#include "bluetooth.h"



void iascar_setup(void) {
	
	bluetooth_config_t bluetooth_config;
	bluetooth_get_config_defaults(&bluetooth_config);
	bluetooth_init(&bluetooth_config);
	
	while(true) {
		bluetooth_process();
	}
	
	
}