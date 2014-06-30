/*
 * brightness.c
 *
 * Created: 29.06.2014 13:08:12
 *  Author: fried_000
 */

#include "../lib/services.h"
#include "../lib/lib_aci.h"
#include "brightness.h"

static uint16_t *oldBrightness;
static uint8_t brightness_value[PIPE_BRIGHTNESS_BRIGHTNESS_TX_MAX_SIZE];

brightness_init(uint16_t *brightness) {
	oldBrightness = brightness;
}

// We check if the new value is different from the old one +- a certain threshold
brightness_update(aci_state_t *aci_state, uint16_t *newBrightness) {
	
	uint16_t brightness_difference = 0;
	
	if (*newBrightness != *oldBrightness) {
		if (*newBrightness < *oldBrightness) {
			brightness_difference = *oldBrightness - *newBrightness;
		} else {
			brightness_difference = *newBrightness - *oldBrightness;
		}
	}
	
	if(brightness_difference >= BRIGHTNESS_LVL_CHANGE_THRESHOLD) {
		
		brightness_value[0] = (*newBrightness >> 8);
		brightness_value[1] = *newBrightness;
		
		lib_aci_set_local_data(PIPE_BRIGHTNESS_BRIGHTNESS_TX, brightness_value, PIPE_BRIGHTNESS_BRIGHTNESS_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_BRIGHTNESS_BRIGHTNESS_TX)) {
			if (aci_state->data_credit_available > 0) {
				brightness_send_update(aci_state, brightness_value);
			}
		}

		*oldBrightness = *newBrightness;
	}
}

brightness_on_pipe_status(aci_state_t *aci_state, uint16_t *brightness) {
	if(lib_aci_is_pipe_available(aci_state, PIPE_BRIGHTNESS_BRIGHTNESS_TX)) {
		brightness_value[0] = (*brightness >> 8);
		brightness_value[1] = *brightness;
		brightness_send_update(aci_state, brightness_value);
	}
}

// Send the update value over the air
brightness_send_update(aci_state_t *aci_state, uint8_t brightness[PIPE_BRIGHTNESS_BRIGHTNESS_TX_MAX_SIZE]) {
	//Sending battery level over the air
	if (lib_aci_send_data(PIPE_BRIGHTNESS_BRIGHTNESS_TX, brightness, PIPE_BRIGHTNESS_BRIGHTNESS_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}
