/*
 * distance_ir_rear.h
 *
 * Created: 29.06.2014 18:22:00
 *  Author: fried_000
 */ 

#ifndef DISTANCE_IR_REAR_H_
#define DISTANCE_IR_REAR_H_

#define DISTANCE_IR_REAR_LVL_THRESHOLD 1

void distance_ir_rear_init(uint16_t *distance);
void distance_ir_rear_on_pipe_status(aci_state_t *aci_state, uint16_t *distance);
void distance_ir_rear_update(aci_state_t *aci_state, uint16_t *distance);
void distance_ir_rear_send_update(aci_state_t *aci_state, uint8_t distance[PIPE_DISTANCE_DISTANCEIRREAR_TX_MAX_SIZE]);

#endif /* DISTANCE_IR_REAR_H_ */