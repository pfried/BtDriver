/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the Bluetooth Active LED
 */

#include "bt_active_led.h"

void bluetooth_led_setup(void) {
	ioport_configure_pin(BT_LED_GPIO, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);
}
