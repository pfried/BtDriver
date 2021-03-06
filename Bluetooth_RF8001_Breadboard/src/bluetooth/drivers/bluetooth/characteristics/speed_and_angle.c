/**
 * @author Friedrich M�ckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the speed and angle characteristic
 */

#include "speed_and_angle.h"

static uint16_t *old_speed;
static uint16_t *old_angle;
static uint16_t *old_sensor_servo;

static uint8_t speed_and_angle_value[PIPE_DRIVE_SPEEDANDANGLE_TX_MAX_SIZE];

void speed_and_angle_init(uint16_t *speed, uint16_t *angle, uint16_t *sensor_servo) {
	old_speed = speed;
	old_angle = angle;
	old_sensor_servo = sensor_servo;
}

void speed_and_angle_update(aci_state_t *aci_state, uint16_t *speed, uint16_t *angle, uint16_t *sensor_servo) {
	
	uint16_t speed_difference = 0;
	uint16_t angle_difference = 0;
	uint16_t servo_difference = 0;
	
	if(*speed != *old_speed) {
		if (*speed < *old_speed) {
			speed_difference = *old_speed - *speed;
			} else {
			speed_difference = *speed - *old_speed;
		}
	}
	
	if(*angle != *old_angle) {
		if (*angle < *old_angle) {
			angle_difference = *old_angle - *angle;
			} else {
			angle_difference = *angle - *old_angle;
		}
	}
	
	if(*sensor_servo != *old_sensor_servo) {
		if (*sensor_servo < *old_sensor_servo) {
			servo_difference = *old_sensor_servo - *sensor_servo;
			} else {
			servo_difference = *sensor_servo - *old_sensor_servo;
		}
	}	
	
	if(speed_difference >= SPEED_LVL_THRESHOLD || angle_difference >= ANGLE_LVL_THRESHOLD || servo_difference >= SENSOR_SERVO_THRESHOLD) {
		
		speed_and_angle_value[0] = *speed;
		speed_and_angle_value[1] = (*speed >> 8);
		speed_and_angle_value[2] = *angle;
		speed_and_angle_value[3] = (*angle >> 8);
		speed_and_angle_value[4] = *sensor_servo;
		speed_and_angle_value[5] = (*sensor_servo >> 8);
		
		lib_aci_set_local_data(PIPE_DRIVE_SPEEDANDANGLE_TX, speed_and_angle_value, PIPE_DRIVE_SPEEDANDANGLE_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_DRIVE_SPEEDANDANGLE_TX)) {
			if (aci_state->data_credit_available > 0) {
				speed_and_angle_send_update(aci_state, speed_and_angle_value);
			}			
		}
		
		*old_angle = *angle;
		*old_speed = *speed;
		*old_sensor_servo = *sensor_servo;
	}
}

void speed_and_angle_on_pipe_status(aci_state_t *aci_state, uint16_t *speed, uint16_t *angle, uint16_t *sensor_servo) {
	
	static bool subscribed_sent = false;
	
	if(lib_aci_is_pipe_available(aci_state, PIPE_DRIVE_SPEEDANDANGLE_TX)) {
		
		if(subscribed_sent == false) {
			speed_and_angle_value[0] = *speed;
			speed_and_angle_value[1] = (*speed >> 8);
			speed_and_angle_value[2] = *angle;
			speed_and_angle_value[3] = (*angle >> 8);
			speed_and_angle_value[4] = *sensor_servo;
			speed_and_angle_value[5] = (*sensor_servo >> 8);
			
			speed_and_angle_send_update(aci_state, speed_and_angle_value);
			subscribed_sent = true;
			*old_angle = *angle;
			*old_speed = *speed;
			*old_sensor_servo = *sensor_servo;
		}
	
	} else {
		subscribed_sent = false;
	}
}
void speed_and_angle_send_update(aci_state_t *aci_state, uint8_t speed_and_angle[PIPE_DRIVE_SPEEDANDANGLE_TX_MAX_SIZE]) {
	if (lib_aci_send_data(PIPE_DRIVE_SPEEDANDANGLE_TX, speed_and_angle, PIPE_DRIVE_SPEEDANDANGLE_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}