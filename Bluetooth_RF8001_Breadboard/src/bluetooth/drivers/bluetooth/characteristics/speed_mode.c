/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the speed mode characteristic
 */

#include "speed_mode.h"

static uint8_t speed_mode_value[PIPE_DRIVE_SPEEDMODE_TX_MAX_SIZE];

static uint8_t *old_speed_mode;

void speed_mode_init(uint8_t *speed_mode) {
	old_speed_mode = speed_mode;
}

void speed_mode_update(aci_state_t *aci_state, uint8_t *speed_mode) {
	
	uint16_t speed_mode_difference = 0;
	
	if(*speed_mode != *old_speed_mode) {
		if(*speed_mode < *old_speed_mode) {
			speed_mode_difference = *old_speed_mode - *speed_mode;
			} else {
			speed_mode_difference = *speed_mode - *old_speed_mode;
		}
	}
	
	if(speed_mode_difference >= SPEED_MODE_LVL_THRESHOLD) {
		
		speed_mode_value[0] = *speed_mode;
		
		lib_aci_set_local_data(PIPE_DRIVE_SPEEDMODE_TX, speed_mode_value, PIPE_DRIVE_SPEEDMODE_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_DRIVE_SPEEDMODE_TX)) {
			if (aci_state->data_credit_available > 0) {
				speed_mode_send_update(aci_state, speed_mode_value);
			}
		}
		
		*old_speed_mode = *speed_mode;
	}
}

void speed_mode_on_pipe_status(aci_state_t *aci_state, uint8_t *speed_mode) {
	if(lib_aci_is_pipe_available(aci_state, PIPE_DRIVE_SPEEDMODE_TX)) {
		speed_mode_value[0] = *speed_mode;
		speed_mode_send_update(aci_state, speed_mode_value);
	}
}

void speed_mode_send_update(aci_state_t *aci_state, uint8_t speed_mode[PIPE_DRIVE_SPEEDMODE_TX]) {
	if (lib_aci_send_data(PIPE_DRIVE_SPEEDMODE_TX, speed_mode, PIPE_DRIVE_SPEEDMODE_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}