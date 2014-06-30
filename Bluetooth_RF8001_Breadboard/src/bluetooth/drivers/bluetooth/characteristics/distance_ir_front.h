/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the Infrared Distance Sensor Front characteristic
 */

#ifndef DISTANCE_IR_FRONT_H_
#define DISTANCE_IR_FRONT_H_

#define DISTANCE_IR_FRONT_LVL_THRESHOLD 1

void distance_ir_front_init(uint16_t *distance);
void distance_ir_front_on_pipe_status(aci_state_t *aci_state, uint16_t *distance);
void distance_ir_front_update(aci_state_t *aci_state, uint16_t *distance);
void distance_ir_front_send_update(aci_state_t *aci_state, uint8_t distance[PIPE_DISTANCE_DISTANCEIRFRONT_TX_MAX_SIZE]);

#endif /* DISTANCE_IR_FRONT_H_ */