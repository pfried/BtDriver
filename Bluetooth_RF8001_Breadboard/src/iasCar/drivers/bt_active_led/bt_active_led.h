/*
 * bt_active_led.h
 *
 * Created: 24.06.2014 08:57:42
 *  Author: fried_000
 */ 

#include <gpio.h>

#ifndef BT_ACTIVE_LED_H_
#define BT_ACTIVE_LED_H_

#define BT_LED_GPIO IOPORT_CREATE_PIN(PORTD, 4)
#define BT_LED BT_LED_GPIO

/**
 * \brief Turns off the Bluetooth Active Indicator LED
 */
#define BT_LED_Off() gpio_set_pin_high(BT_LED)

/**
 * \brief Turns on the Bluetooth Active Indicator LED
 */
#define BT_LED_On() gpio_set_pin_low(BT_LED)

/**
 * \brief Toggles the Bluetooth Active Indicator LED
 */
#define BT_LED_Toggle() gpio_toggle_pin(BT_LED)

void bluetooth_led_setup(void);

#endif /* BT_ACTIVE_LED_H_ */