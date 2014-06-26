/*
 * active_led.h
 *
 * Created: 24.06.2014 08:55:49
 *  Author: fried_000
 */ 


#ifndef ACTIVE_LED_H_
#define ACTIVE_LED_H_

#define _LED_Off(led_gpio)     gpio_set_pin_high(led_gpio)

/**
 * \brief Turns on the specified LEDs.
 *
 * \param led_gpio LED to turn on (LEDx_GPIO).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_On(led_gpio)      gpio_set_pin_low(led_gpio)

/**
 * \brief Toggles the specified LEDs.
 *
 * \param led_gpio LED to toggle (LEDx_GPIO).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_Toggle(led_gpio)  gpio_toggle_pin(led_gpio)


#endif /* ACTIVE_LED_H_ */