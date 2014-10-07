/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the Infrared Distance characteristic
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_

#include "../lib/lib_aci.h"
#include "../lib/services.h"

#define DISTANCE_IR_FRONT_LVL_THRESHOLD 1
#define DISTANCE_IR_REAR_LVL_THRESHOLD 1
#define DISTANCE_US_FRONT_LVL_THRESHOLD 1
#define DISTANCE_US_REAR_LVL_THRESHOLD 1

void distance_init(uint16_t *distance_ir_front, uint16_t *distance_ir_rear, uint16_t *distance_us_front, uint16_t *distance_us_rear);
void distance_on_pipe_status(aci_state_t *aci_state, uint16_t *distance_ir_front, uint16_t *distance_ir_rear, uint16_t *distance_us_front, uint16_t *distance_us_rear);
void distance_update(aci_state_t *aci_state, uint16_t *distance_ir_front, uint16_t *distance_ir_rear, uint16_t *distance_us_front, uint16_t *distance_us_rear);
void distance_send_update(aci_state_t *aci_state, uint8_t distance[PIPE_DISTANCE_DISTANCE_TX_MAX_SIZE]);

#endif /* DISTANCE_H_ */