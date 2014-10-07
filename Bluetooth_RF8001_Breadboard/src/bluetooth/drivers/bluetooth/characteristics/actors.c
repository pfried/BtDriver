/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the actors characteristic
 */

#include "actors.h"

static uint8_t actors_value[PIPE_ACTORS_ACTORS_TX_MAX_SIZE];

static uint8_t *old_horn;
static uint8_t *old_lights;
static uint16_t *old_generic_actor_1;
static uint16_t *old_generic_actor_2;

void actors_init(uint8_t *horn, uint8_t *lights, uint16_t *generic_actor_1, uint16_t *generic_actor_2) {
	old_horn = horn;
	old_lights = lights;
	old_generic_actor_1 = generic_actor_1;
	old_generic_actor_2 = generic_actor_2;
}

void actors_update(aci_state_t *aci_state, uint8_t *horn, uint8_t *lights, uint16_t *generic_actor_1, uint16_t *generic_actor_2) {
	
	uint8_t horn_difference = *horn == *old_horn;
	uint8_t lights_difference = *lights != *old_lights;
	
	uint16_t generic_actor_1_difference = 0;
	uint16_t generic_actor_2_difference = 0;
	
	if(*generic_actor_1 != *old_generic_actor_1) {
		if(*generic_actor_1 < *old_generic_actor_1) {
			generic_actor_1_difference = *old_generic_actor_1 - *generic_actor_1;
			} else {
			generic_actor_1_difference = *generic_actor_1 - *old_generic_actor_1;
		}
	}
	
	if(*generic_actor_2 != *old_generic_actor_2) {
		if(*generic_actor_2 < *old_generic_actor_2) {
			generic_actor_2_difference = *old_generic_actor_2 - *generic_actor_2;
			} else {
			generic_actor_2_difference = *generic_actor_2 - *old_generic_actor_2;
		}
	}
	
	if(horn_difference || lights_difference|| generic_actor_1_difference >= GENERIC_ACTOR_1_LVL_THRESHOLD || generic_actor_2_difference >= GENERIC_ACTOR_2_LVL_THRESHOLD) {
		
		actors_value[0] = 0;
		actors_value[1] = *lights;
		actors_value[2] = *generic_actor_1;
		actors_value[3] = (*generic_actor_1 >> 8);
		actors_value[4] = *generic_actor_2;
		actors_value[5] = (*generic_actor_2 >> 8);
		
		lib_aci_set_local_data(PIPE_ACTORS_ACTORS_TX, actors_value, PIPE_ACTORS_ACTORS_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_ACTORS_ACTORS_TX)) {
			if (aci_state->data_credit_available > 0) {
				actors_send_update(aci_state, actors_value);
			}
		}
		
		*old_horn = *horn;
		*old_lights = *lights;
		*old_generic_actor_1 = *generic_actor_1;
		*old_generic_actor_2 = *generic_actor_2;
	}
}

void actors_on_pipe_status(aci_state_t *aci_state, uint8_t *horn, uint8_t *lights, uint16_t *generic_actor_1, uint16_t *generic_actor_2) {
	
	static bool subscribed_sent = false;
	
	if(lib_aci_is_pipe_available(aci_state, PIPE_ACTORS_ACTORS_TX)) {
		
		if(subscribed_sent == false) {
			
			actors_value[0] = *horn;
			actors_value[1] = *lights;
			actors_value[2] = *generic_actor_1;
			actors_value[3] = (*generic_actor_1 >> 8);
			actors_value[4] = *generic_actor_2;
			actors_value[5] = (*generic_actor_2 >> 8);
			
			actors_send_update(aci_state, actors_value);
			subscribed_sent = true;
			
			*old_horn = *horn;
			*old_lights = *lights;
			*old_generic_actor_1 = *generic_actor_1;
			*old_generic_actor_2 = *generic_actor_2;
		}
		
	} else {
		subscribed_sent = false;
	}
}

void actors_send_update(aci_state_t *aci_state, uint8_t actors[PIPE_ACTORS_ACTORS_TX_MAX_SIZE]) {
	if (lib_aci_send_data(PIPE_ACTORS_ACTORS_TX, actors, PIPE_ACTORS_ACTORS_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}