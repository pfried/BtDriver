/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the Infrared Distance Sensor Rear characteristic
 */

#ifndef DISTANCE_IR_REAR_H_
#define DISTANCE_IR_REAR_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"

#define DISTANCE_IR_REAR_LVL_THRESHOLD 1

void distance_ir_rear_init(uint16_t *distance);
void distance_ir_rear_on_pipe_status(aci_state_t *aci_state, uint16_t *distance);
void distance_ir_rear_update(aci_state_t *aci_state, uint16_t *distance);
void distance_ir_rear_send_update(aci_state_t *aci_state, uint8_t distance[PIPE_DISTANCE_DISTANCEIRREAR_TX_MAX_SIZE]);

#endif /* DISTANCE_IR_REAR_H_ */