/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the sensors characteristic
 */
#include "sensors.h"

static uint16_t *oldBrightness;
static uint16_t *oldTemperature;
static uint16_t *oldBattery;
static uint8_t sensors_value[PIPE_SENSORS_SENSORS_TX_MAX_SIZE];

sensors_init(uint16_t *brightness, uint16_t *temperature, uint16_t *battery) {
	oldBrightness = brightness;
	oldTemperature = temperature;
	oldBattery = battery;
}

// We check if the new value is different from the old one +- a certain threshold
sensors_update(aci_state_t *aci_state, uint16_t *newBrightness, uint16_t *newTemperature, uint16_t *newBattery) {
	
	uint16_t brightness_difference = 0;
	uint16_t temperature_difference = 0;
	uint16_t battery_difference = 0;
	
	if (*newBrightness != *oldBrightness) {
		if (*newBrightness < *oldBrightness) {
			brightness_difference = *oldBrightness - *newBrightness;
		} else {
			brightness_difference = *newBrightness - *oldBrightness;
		}
	}
	
	if (*newTemperature!= *oldTemperature) {
		if (*newTemperature < *oldTemperature) {
			temperature_difference = *oldTemperature - *newTemperature;
			} else {
			temperature_difference = *newTemperature - *oldTemperature;
		}
	}
		
		if (*newBattery!= *oldBattery) {
			if (*newBattery < *oldBattery) {
				battery_difference = *oldBattery - *newBattery;
				} else {
				battery_difference = *newBattery - *oldBattery;
			}
		}
	
	if(brightness_difference >= BRIGHTNESS_LVL_CHANGE_THRESHOLD | temperature_difference >= TEMPERATURE_LVL_CHANGE_THRESHOLD | battery_difference >= BATTERY_LVL_CHANGE_THRESHOLD) {
		
		sensors_value[0] = *newBrightness;
		sensors_value[1] = (*newBrightness >> 8);
		sensors_value[2] = *newTemperature;
		sensors_value[3] = (*newTemperature >> 8);		
		sensors_value[4] = *newBattery;
		sensors_value[5] = (*newBattery >> 8);
		
		lib_aci_set_local_data(PIPE_SENSORS_SENSORS_TX, sensors_value, PIPE_SENSORS_SENSORS_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_SENSORS_SENSORS_TX)) {
			if (aci_state->data_credit_available > 0) {
				sensors_send_update(aci_state, sensors_value);
			}
		}

		*oldBrightness = *newBrightness;
		*oldTemperature = *newTemperature;
		*oldBattery = *newBattery;
	}
}

sensors_on_pipe_status(aci_state_t *aci_state, uint16_t *brightness, uint16_t *temperature, uint16_t *battery) {
	
	// If we dont keep track of this, all the characteristics fire at once if a pipe update occurs
	static bool subscribed_sent = false;
	
	if(lib_aci_is_pipe_available(aci_state, PIPE_SENSORS_SENSORS_TX)) {
		
		if(subscribed_sent == false) {
			sensors_value[0] = *brightness;
			sensors_value[1] = (*brightness >> 8);
			sensors_value[2] = *temperature;
			sensors_value[3] = (*temperature >> 8);
			sensors_value[4] = *battery;
			sensors_value[5] = (*battery >> 8);
			
			sensors_send_update(aci_state, sensors_value);
			subscribed_sent = true;
			
			*oldBrightness = *brightness;
			*oldTemperature = *temperature;
			*oldBattery = *battery;
		}
		
	} else {
		subscribed_sent = false;
	}
}

// Send the update value over the air
sensors_send_update(aci_state_t *aci_state, uint8_t sensors[PIPE_SENSORS_SENSORS_TX_MAX_SIZE]) {
	//Sending sensor levels over the air
	if (lib_aci_send_data(PIPE_SENSORS_SENSORS_TX, sensors, PIPE_SENSORS_SENSORS_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}
