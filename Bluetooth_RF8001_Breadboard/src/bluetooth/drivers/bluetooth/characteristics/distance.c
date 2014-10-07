/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the Infrared Distance characteristic
 */

#include "distance.h"

static uint16_t *old_distance_ir_front;
static uint16_t *old_distance_ir_rear;
static uint16_t *old_distance_us_front;
static uint16_t *old_distance_us_rear;

static uint8_t distance_value[PIPE_DISTANCE_DISTANCE_TX_MAX_SIZE];

void distance_init(uint16_t *distance_ir_front, uint16_t *distance_ir_rear, uint16_t *distance_us_front, uint16_t *distance_us_rear) {
	old_distance_ir_front = distance_ir_front;
	old_distance_ir_rear  = distance_ir_rear;
	old_distance_us_front = distance_us_front;
	old_distance_us_rear  = distance_us_rear;
}

void distance_update(aci_state_t *aci_state, uint16_t *distance_ir_front, uint16_t *distance_ir_rear, uint16_t *distance_us_front, uint16_t *distance_us_rear) {
	
	uint16_t distance_difference_ir_front = 0;
	uint16_t distance_difference_ir_rear  = 0;
	uint16_t distance_difference_us_front = 0;
	uint16_t distance_difference_us_rear  = 0;
		
	if(*distance_ir_front != *old_distance_ir_front) {
		if(*distance_ir_front < *old_distance_ir_front) {
			distance_difference_ir_front = *old_distance_ir_front - *distance_ir_front ;
		} else {
			distance_difference_ir_front = *distance_ir_front - *old_distance_ir_front;
		}
	}
	
	if(*distance_ir_rear != *old_distance_ir_rear) {
		if(*distance_ir_rear < *old_distance_ir_rear) {
			distance_difference_ir_rear = *old_distance_ir_rear - *distance_ir_rear;
			} else {
			distance_difference_ir_rear = *distance_ir_rear - *old_distance_ir_rear;
		}
	}
	
	if(*distance_us_front != *old_distance_us_front) {
		if(*distance_us_front < *old_distance_us_front) {
			distance_difference_us_front = *old_distance_us_front - *distance_us_front ;
			} else {
			distance_difference_us_front = *distance_us_front - *old_distance_us_front;
		}
	}
	
	if(*distance_us_rear != *old_distance_us_rear) {
		if(*distance_us_rear < *old_distance_us_rear) {
			distance_difference_us_rear = *old_distance_us_rear - *distance_us_rear;
			} else {
			distance_difference_us_rear = *distance_us_rear - *old_distance_us_rear;
		}
	}	
	
	if(distance_difference_ir_front >= DISTANCE_IR_FRONT_LVL_THRESHOLD || distance_difference_ir_rear >= DISTANCE_IR_REAR_LVL_THRESHOLD || distance_difference_us_front >= DISTANCE_US_FRONT_LVL_THRESHOLD || distance_difference_us_rear >= DISTANCE_US_REAR_LVL_THRESHOLD) {
		
		distance_value[0] = *distance_ir_front;
		distance_value[1] = (*distance_ir_front >> 8);
		distance_value[2] = *distance_ir_rear;
		distance_value[3] = (*distance_ir_rear >> 8);
		distance_value[4] = *distance_us_front;
		distance_value[5] = (*distance_us_front >> 8);
		distance_value[6] = *distance_us_rear;
		distance_value[7] = (*distance_us_rear >> 8);		
		
		lib_aci_set_local_data(PIPE_DISTANCE_DISTANCE_TX, distance_value, PIPE_DISTANCE_DISTANCE_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_DISTANCE_DISTANCE_TX)) {
			if (aci_state->data_credit_available > 0) {
				distance_send_update(aci_state, distance_value);
			}
		}
		
		*old_distance_ir_front = *distance_ir_front;
		*old_distance_ir_rear  = *distance_ir_rear;
		*old_distance_us_front = *distance_us_front;
		*old_distance_us_rear  = *distance_us_rear;
		
	}
}

void distance_on_pipe_status(aci_state_t *aci_state, uint16_t *distance_ir_front, uint16_t *distance_ir_rear, uint16_t *distance_us_front, uint16_t *distance_us_rear) {
	
	static bool subscribed_sent = false;
	
	if(lib_aci_is_pipe_available(aci_state, PIPE_DISTANCE_DISTANCE_TX)) {

		if(subscribed_sent == false) {
			
			distance_value[0] = *distance_ir_front;
			distance_value[1] = (*distance_ir_front >> 8);
			distance_value[2] = *distance_ir_rear;
			distance_value[3] = (*distance_ir_rear >> 8);
			distance_value[4] = *distance_us_front;
			distance_value[5] = (*distance_us_front >> 8);
			distance_value[6] = *distance_us_rear;
			distance_value[7] = (*distance_us_rear >> 8);
			
			distance_send_update(aci_state, distance_value);
			subscribed_sent = true;
			
			*old_distance_ir_front = *distance_ir_front;
			*old_distance_ir_rear  = *distance_ir_rear;
			*old_distance_us_front = *distance_us_front;
			*old_distance_us_rear  = *distance_us_rear;
		}

	} else {
		subscribed_sent = false;
	}
}

void distance_send_update(aci_state_t *aci_state, uint8_t distance[PIPE_DISTANCE_DISTANCE_TX_MAX_SIZE]) {
	if (lib_aci_send_data(PIPE_DISTANCE_DISTANCE_TX, distance, PIPE_DISTANCE_DISTANCE_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}