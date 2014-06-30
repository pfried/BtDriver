/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the temperature characteristic
 */

#include "temperature.h"

static uint16_t *old_temperature;
static uint8_t temperature_value[PIPE_THERMOMETER_TEMPERATURE_TX_MAX_SIZE];

temperature_init(uint16_t *temperature) {
	old_temperature = temperature;
}

// We check if the new value is different from the old one +- a certain threshold
temperature_update(aci_state_t *aci_state, uint16_t *temperature) {
	
	uint16_t temperature_difference = 0;
	
	if (*temperature != *old_temperature) {
		if (*temperature < *old_temperature) {
			temperature_difference = *old_temperature - *temperature;
		} else {
			temperature_difference = *temperature - *old_temperature;
		}
	}
	
	if(temperature_difference >= TEMPERATURE_LVL_CHANGE_THRESHOLD) {
		
		temperature_value[0] = *temperature;
		temperature_value[1] = (*temperature >> 8);
		
		lib_aci_set_local_data(PIPE_THERMOMETER_TEMPERATURE_TX, temperature_value, PIPE_THERMOMETER_TEMPERATURE_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_THERMOMETER_TEMPERATURE_TX)) {
			if (aci_state->data_credit_available > 0) {
				temperature_send_update(aci_state, temperature_value);
			}
		}

		*old_temperature = *temperature;
	}
}

temperature_on_pipe_status(aci_state_t *aci_state, uint16_t *temperature) {
	
	// If we dont keep track of this, all the characteristics fire at once if a pipe update occurs
	static bool subscribed_sent = false;
	
	if(lib_aci_is_pipe_available(aci_state, PIPE_THERMOMETER_TEMPERATURE_TX)) {
		
		if(subscribed_sent == false) {
			temperature_value[0] = *temperature;
			temperature_value[1] = (*temperature >> 8);
			
			temperature_send_update(aci_state, temperature_value);
			subscribed_sent = true;
			*old_temperature = *temperature;
		}
		
	} else {
		subscribed_sent = false;
	}
}

// Send the update value over the air
temperature_send_update(aci_state_t *aci_state, uint8_t temperature[PIPE_THERMOMETER_TEMPERATURE_TX_MAX_SIZE]) {
	//Sending battery level over the air
	if (lib_aci_send_data(PIPE_THERMOMETER_TEMPERATURE_TX, temperature, PIPE_THERMOMETER_TEMPERATURE_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}
