/*
 * bt_active_led.c
 *
 * Created: 24.06.2014 09:03:38
 *  Author: fried_000
 */

#include "bt_active_led.h"

/************************************************************************/
/* Initialize the Bluetooth LED                                         */
/************************************************************************/
void bluetooth_led_setup(void) {
	ioport_configure_pin(BT_LED_GPIO, IOPORT_INIT_LOW | IOPORT_DIR_OUTPUT);
}
