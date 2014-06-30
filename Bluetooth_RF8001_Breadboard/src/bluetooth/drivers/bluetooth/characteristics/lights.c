/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the lights characteristic
 */

#include "../lib/services.h"
#include "../lib/lib_aci.h"
#include "lights.h"

static uint16_t *oldLights;

void lights_init(uint16_t *lights) {
	oldLights = lights;
}

void lights_update(aci_state_t *aci_state, uint16_t *lights) {
	
	uint16_t lights_difference = 0;
	
	if(*lights != *oldLights) {
		if(*lights < *oldLights) {
			lights_difference = *oldLights - *lights;
		} else {
			lights_difference = *lights - *oldLights;
		}
	}
	
	if(lights_difference >= LIGHTS_LVL_THRESHOLD) {
		
		lib_aci_set_local_data(PIPE_LIGHTS_LIGHTS_TX, *lights, PIPE_LIGHTS_LIGHTS_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_LIGHTS_LIGHTS_TX)) {
			if (aci_state->data_credit_available > 0) {
				lights_send_update(aci_state, *lights);
			}
		}
		
		*oldLights = *lights;
	}
}

void lights_on_pipe_status(aci_state_t *aci_state, uint16_t *lights) {
	if(lib_aci_is_pipe_available(aci_state, PIPE_LIGHTS_LIGHTS_TX)) {
		lights_send_update(aci_state, *lights);
	}
}

void lights_send_update(aci_state_t *aci_state, uint8_t lights[PIPE_LIGHTS_LIGHTS_TX]) {
	if (lib_aci_send_data(PIPE_LIGHTS_LIGHTS_TX, lights, PIPE_LIGHTS_LIGHTS_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}