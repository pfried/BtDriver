/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the generic actor 1 characteristic
 */

#include "generic_actor_1.h"

static uint16_t *old_generic_actor_1;
static uint8_t generic_actor_1_value[PIPE_GENERIC_GENERICACTOR1_TX_MAX_SIZE];

void generic_actor_1_init(uint16_t *generic_actor_1) {
	old_generic_actor_1 = generic_actor_1;
}

void generic_actor_1_update(aci_state_t *aci_state, uint16_t *generic_actor_1) {
	
	uint16_t generic_actor_1_difference = 0;
	
	if(*generic_actor_1 != *old_generic_actor_1) {
		if(*generic_actor_1 < *old_generic_actor_1) {
			generic_actor_1_difference = *old_generic_actor_1 - *generic_actor_1;
			} else {
			generic_actor_1_difference = *generic_actor_1 - *old_generic_actor_1;
		}
	}
	
	if(generic_actor_1_difference >= GENERIC_ACTOR_1_LVL_THRESHOLD) {
		
		generic_actor_1_value[0] = *generic_actor_1;
		generic_actor_1_value[1] = (*generic_actor_1 >> 8);
		
		lib_aci_set_local_data(PIPE_GENERIC_GENERICACTOR1_TX, generic_actor_1_value, PIPE_GENERIC_GENERICACTOR1_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_GENERIC_GENERICACTOR1_TX)) {
			if (aci_state->data_credit_available > 0) {
				generic_actor_1_send_update(aci_state, generic_actor_1_value);
			}
		}
		
		*old_generic_actor_1 = *generic_actor_1;
	}
}

void generic_actor_1_on_pipe_status(aci_state_t *aci_state, uint16_t *generic_actor_1) {
	if(lib_aci_is_pipe_available(aci_state, PIPE_GENERIC_GENERICACTOR1_TX)) {
		generic_actor_1_value[0] = *generic_actor_1;
		generic_actor_1_value[1] = (*generic_actor_1 >> 8);
		generic_actor_1_send_update(aci_state, generic_actor_1_value);
	}
}

void generic_actor_1_send_update(aci_state_t *aci_state, uint8_t generic_actor_1[PIPE_GENERIC_GENERICACTOR1_TX_MAX_SIZE]) {
	if (lib_aci_send_data(PIPE_GENERIC_GENERICACTOR1_TX, generic_actor_1, PIPE_GENERIC_GENERICACTOR1_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}