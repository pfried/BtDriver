/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the speed and angle characteristic
 */

#ifndef SPEED_AND_ANGLE_H_
#define SPEED_AND_ANGLE_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"
#include "characteristic_util.h"

#define SPEED_LVL_THRESHOLD 1
#define ANGLE_LVL_THRESHOLD 1
#define SENSOR_SERVO_THRESHOLD 1

void speed_and_angle_init(uint16_t *speed, uint16_t *angle, uint16_t *sensor_servo);
void speed_and_angle_on_pipe_status(aci_state_t *aci_state, uint16_t *speed, uint16_t *angle, uint16_t *sensor_servo);
void speed_and_angle_update(aci_state_t *aci_state, uint16_t *speed, uint16_t *angle, uint16_t *sensor_servo);
void speed_and_angle_send_update(aci_state_t *aci_state, uint8_t speed_and_angle[PIPE_DRIVE_SPEEDANDANGLE_TX_MAX_SIZE]);

#endif /* SPEED_AND_ANGLE_H_ */