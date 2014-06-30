/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the generic actor 1 characteristic
 */

#include "generic_actor_2.h"

static uint16_t *old_generic_actor_2;
static uint8_t generic_actor_2_value[PIPE_GENERIC_GENERICACTOR2_TX_MAX_SIZE];

void generic_actor_2_init(uint16_t *generic_actor_2) {
	old_generic_actor_2 = generic_actor_2;
}

void generic_actor_2_update(aci_state_t *aci_state, uint16_t *generic_actor_2) {
	
	uint16_t generic_actor_2_difference = 0;
	
	if(*generic_actor_2 != *old_generic_actor_2) {
		if(*generic_actor_2 < *old_generic_actor_2) {
			generic_actor_2_difference = *old_generic_actor_2 - *generic_actor_2;
			} else {
			generic_actor_2_difference = *generic_actor_2 - *old_generic_actor_2;
		}
	}
	
	if(generic_actor_2_difference >= GENERIC_ACTOR_2_LVL_THRESHOLD) {
		
		generic_actor_2_value[0] = *generic_actor_2;
		generic_actor_2_value[1] = (*generic_actor_2 >> 8);
		
		lib_aci_set_local_data(PIPE_GENERIC_GENERICACTOR2_TX, generic_actor_2_value, PIPE_GENERIC_GENERICACTOR2_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_GENERIC_GENERICACTOR2_TX)) {
			if (aci_state->data_credit_available > 0) {
				generic_actor_2_send_update(aci_state, generic_actor_2_value);
			}
		}
		
		*old_generic_actor_2 = *generic_actor_2;
	}
}

void generic_actor_2_on_pipe_status(aci_state_t *aci_state, uint16_t *generic_actor_2) {
	
	static bool subscribed_sent = false;
	
	if(lib_aci_is_pipe_available(aci_state, PIPE_GENERIC_GENERICACTOR2_TX)) {
		
		if(subscribed_sent == false) {
			generic_actor_2_value[0] = *generic_actor_2;
			generic_actor_2_value[1] = (*generic_actor_2 >> 8);
			
			generic_actor_2_send_update(aci_state, generic_actor_2_value);
			subscribed_sent = true;
			*old_generic_actor_2 = *generic_actor_2;
		}
		
	} else {
		subscribed_sent = false;
	}
}

void generic_actor_2_send_update(aci_state_t *aci_state, uint8_t generic_actor_2[PIPE_GENERIC_GENERICACTOR2_TX_MAX_SIZE]) {
	if (lib_aci_send_data(PIPE_GENERIC_GENERICACTOR2_TX, generic_actor_2, PIPE_GENERIC_GENERICACTOR2_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}