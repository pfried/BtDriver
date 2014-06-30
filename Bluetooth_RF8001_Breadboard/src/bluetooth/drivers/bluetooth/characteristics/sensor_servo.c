/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the sensor servo characteristic
 */

#include "sensor_servo.h"

static uint16_t *old_sensor_servo;
static uint8_t sensor_servo_value[PIPE_DISTANCE_SENSORSERVO_TX_MAX_SIZE];

void sensor_servo_init(uint16_t *sensor_servo) {
	old_sensor_servo = sensor_servo;
}

void sensor_servo_update(aci_state_t *aci_state, uint16_t *sensor_servo) {
	
	uint16_t sensor_servo_difference = 0;
	
	if(*sensor_servo != *old_sensor_servo) {
		if(*sensor_servo < *old_sensor_servo) {
			sensor_servo_difference = *old_sensor_servo - *sensor_servo;
			} else {
			sensor_servo_difference = *sensor_servo - *old_sensor_servo;
		}
	}
	
	if(sensor_servo_difference >= SENSOR_SERVO_LVL_THRESHOLD) {
		
		sensor_servo_value[0] = *sensor_servo;
		sensor_servo_value[1] = (*sensor_servo >> 8);
		
		lib_aci_set_local_data(PIPE_DISTANCE_SENSORSERVO_TX, sensor_servo_value, PIPE_DISTANCE_SENSORSERVO_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_DISTANCE_SENSORSERVO_TX)) {
			if (aci_state->data_credit_available > 0) {
				sensor_servo_send_update(aci_state, sensor_servo_value);
			}
		}
		
		*old_sensor_servo = *sensor_servo;
	}
}

void sensor_servo_on_pipe_status(aci_state_t *aci_state, uint16_t *sensor_servo) {
	
	static bool subscribed_sent = false;
	
	if(lib_aci_is_pipe_available(aci_state, PIPE_DISTANCE_SENSORSERVO_TX)) {
		
		if(subscribed_sent == false) {
			sensor_servo_value[0] = *sensor_servo;
			sensor_servo_value[1] = (*sensor_servo >> 8);
			
			sensor_servo_send_update(aci_state, sensor_servo_value);
			subscribed_sent = true;
			*old_sensor_servo = *sensor_servo;	
		}
		
	} else {
		subscribed_sent = false;
	}
}

void sensor_servo_send_update(aci_state_t *aci_state, uint8_t sensor_servo[PIPE_DISTANCE_SENSORSERVO_TX_MAX_SIZE]) {
	if (lib_aci_send_data(PIPE_DISTANCE_SENSORSERVO_TX, sensor_servo, PIPE_DISTANCE_SENSORSERVO_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}