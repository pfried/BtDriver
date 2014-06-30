/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the sensor servo characteristic
 */

#ifndef SENSOR_SERVO_H_
#define SENSOR_SERVO_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"
#include "characteristic_util.h"

#define SENSOR_SERVO_LVL_THRESHOLD 1

void sensor_servo_init(uint16_t *sensor_servo);
void sensor_servo_on_pipe_status(aci_state_t *aci_state, uint16_t *sensor_servo);
void sensor_servo_update(aci_state_t *aci_state, uint16_t *sensor_servo);
void sensor_servo_send_update(aci_state_t *aci_state, uint8_t sensor_servo[PIPE_DISTANCE_SENSORSERVO_RX_MAX_SIZE]);

#endif /* SENSOR_SERVO_H_ */