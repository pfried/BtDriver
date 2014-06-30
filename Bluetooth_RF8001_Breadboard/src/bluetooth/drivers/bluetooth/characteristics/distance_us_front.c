/**
 * @author Friedrich M�ckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the Ultrasonic Distance Sensor Front characteristic
 */

#include "../lib/services.h"
#include "../lib/lib_aci.h"
#include "distance_us_front.h"

static uint16_t *oldDistance;
static uint8_t distance_value[PIPE_DISTANCE_DISTANCEUSFRONT_TX_MAX_SIZE];

void distance_us_front_init(uint16_t *distance) {
	oldDistance = distance;
}

void distance_us_front_update(aci_state_t *aci_state, uint16_t *distance) {
	
	uint16_t distance_difference = 0;
	
	if(*distance != *oldDistance) {
		if(*distance < *oldDistance) {
			distance_difference = *oldDistance - *distance;
		} else {
			distance_difference = *distance - *oldDistance;
		}
	}
	
	if(distance_difference >= DISTANCE_US_FRONT_LVL_THRESHOLD) {
		
		distance_value[0] = (*distance >> 8);
		distance_value[1] = *distance;
		
		lib_aci_set_local_data(PIPE_DISTANCE_DISTANCEUSFRONT_TX, distance_value, PIPE_DISTANCE_DISTANCEUSFRONT_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_DISTANCE_DISTANCEUSFRONT_TX)) {
			if (aci_state->data_credit_available > 0) {
				distance_us_front_send_update(aci_state, distance_value);
			}
		}
		
		*oldDistance = *distance;
	}
}

void distance_us_front_on_pipe_status(aci_state_t *aci_state, uint16_t *distance) {
	if(lib_aci_is_pipe_available(aci_state, PIPE_DISTANCE_DISTANCEUSFRONT_TX)) {
		distance_value[0] = (*distance >> 8);
		distance_value[1] = *distance;
		distance_us_front_send_update(aci_state, distance_value);
	}
}

void distance_us_front_send_update(aci_state_t *aci_state, uint8_t distance[PIPE_DISTANCE_DISTANCEUSFRONT_TX_MAX_SIZE]) {
	if (lib_aci_send_data(PIPE_DISTANCE_DISTANCEUSFRONT_TX, distance, PIPE_DISTANCE_DISTANCEUSFRONT_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}	
}