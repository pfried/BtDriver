/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the Infrared Distance Sensor Rear characteristic
 */

#include "distance_ir_rear.h"

static uint16_t *oldDistance;
static uint8_t distance_value[PIPE_DISTANCE_DISTANCEIRREAR_TX_MAX_SIZE];

void distance_ir_rear_init(uint16_t *distance) {
	oldDistance = distance;
}

void distance_ir_rear_update(aci_state_t *aci_state, uint16_t *distance) {
	
	uint16_t distance_difference = 0;
	
	if(*distance != *oldDistance) {
		if(*distance < *oldDistance) {
			distance_difference = *oldDistance - *distance;
		} else {
			distance_difference = *distance - *oldDistance;
		}
	}
	
	if(distance_difference >= DISTANCE_IR_REAR_LVL_THRESHOLD) {
		
		distance_value[0] = *distance;
		distance_value[1] = (*distance >> 8);
		
		lib_aci_set_local_data(PIPE_DISTANCE_DISTANCEIRREAR_TX, distance_value, PIPE_DISTANCE_DISTANCEIRREAR_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_DISTANCE_DISTANCEIRREAR_TX)) {
			if (aci_state->data_credit_available > 0) {
				distance_ir_rear_send_update(aci_state, distance_value);
			}
		}
		
		*oldDistance = *distance;
	}
}

void distance_ir_rear_on_pipe_status(aci_state_t *aci_state, uint16_t *distance) {
	if(lib_aci_is_pipe_available(aci_state, PIPE_DISTANCE_DISTANCEIRREAR_TX)) {

		distance_value[0] = *distance;
		distance_value[1] = (*distance >> 8);
		
		distance_ir_rear_send_update(aci_state, distance_value);
	}
}

void distance_ir_rear_send_update(aci_state_t *aci_state, uint8_t distance[PIPE_DISTANCE_DISTANCEIRREAR_TX_MAX_SIZE]) {
	if (lib_aci_send_data(PIPE_DISTANCE_DISTANCEIRREAR_TX, distance, PIPE_DISTANCE_DISTANCEIRREAR_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}