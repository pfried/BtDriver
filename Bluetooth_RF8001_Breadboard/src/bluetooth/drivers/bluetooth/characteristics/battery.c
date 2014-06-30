/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the battery characteristic
 */

#include "battery.h"

static uint16_t *oldBattery;
static uint8_t battery_value[PIPE_BATTERYLEVEL_BATTERYLEVEL_TX_MAX_SIZE];

void battery_init(uint16_t *battery) {
	oldBattery = battery;
}

void battery_update(aci_state_t *aci_state, uint16_t *battery) {
	
	uint16_t battery_difference = 0;
	
	if(*battery != *oldBattery) {
		if(*battery < *oldBattery) {
			battery_difference = *oldBattery - *battery;
		} else {
			battery_difference = *battery - *oldBattery;
		}
	}
	
	if(battery_difference >= BATTERY_LVL_THRESHOLD) {
		
		battery_value[0] = *battery;
		battery_value[1] = (*battery >> 8);
		
		lib_aci_set_local_data(PIPE_BATTERYLEVEL_BATTERYLEVEL_TX, battery_value, PIPE_BATTERYLEVEL_BATTERYLEVEL_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_BATTERYLEVEL_BATTERYLEVEL_TX)) {
			if (aci_state->data_credit_available > 0) {
				battery_send_update(aci_state, battery_value);
			}
		}
		
		*oldBattery = *battery;
	}
}

void battery_on_pipe_status(aci_state_t *aci_state, uint16_t *battery) {
	
	static bool subscribed_sent = false;
	
	if(lib_aci_is_pipe_available(aci_state, PIPE_BATTERYLEVEL_BATTERYLEVEL_TX)) {
		
		if(subscribed_sent == false) {
			battery_value[0] = *battery;
			battery_value[1] = (*battery >> 8);
			
			battery_send_update(aci_state, battery_value);
			subscribed_sent = true;
			*oldBattery = *battery;		
		}

	} else {
		subscribed_sent = false;
	}
}

void battery_send_update(aci_state_t *aci_state, uint8_t battery[PIPE_BATTERYLEVEL_BATTERYLEVEL_TX]) {
	if (lib_aci_send_data(PIPE_BATTERYLEVEL_BATTERYLEVEL_TX, battery, PIPE_BATTERYLEVEL_BATTERYLEVEL_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}