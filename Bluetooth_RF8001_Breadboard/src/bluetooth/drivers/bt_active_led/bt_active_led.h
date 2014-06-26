/*
 * bt_active_led.h
 *
 * Created: 24.06.2014 08:57:42
 *  Author: fried_000
 */ 

#include <ioport.h>

#ifndef BT_ACTIVE_LED_H_
#define BT_ACTIVE_LED_H_

#define BT_LED_GPIO IOPORT_CREATE_PIN(PORTD, 4)
#define BT_LED BT_LED_GPIO

/**
 * \brief Turns off the Bluetooth Active Indicator LED
 */
#define BT_LED_Off() ioport_set_pin_level(BT_LED, HIGH);

/**
 * \brief Turns on the Bluetooth Active Indicator LED
 */
#define BT_LED_On() ioport_set_pin_level(BT_LED, LOW);

/**
 * \brief Toggles the Bluetooth Active Indicator LED
 */
#define BT_LED_Toggle() ioport_toggle_pin_level(BT_LED)

void bluetooth_led_setup(void);

#endif /* BT_ACTIVE_LED_H_ */