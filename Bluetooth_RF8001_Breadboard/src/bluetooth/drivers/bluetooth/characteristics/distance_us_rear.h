/*
 * distance_us_rear.h
 *
 * Created: 29.06.2014 18:14:48
 *  Author: fried_000
 */ 

#ifndef DISTANCE_US_REAR_H_
#define DISTANCE_US_REAR_H_

#define DISTANCE_US_REAR_LVL_THRESHOLD 1

void distance_us_rear_init(uint16_t *distance);
void distance_us_rear_on_pipe_status(aci_state_t *aci_state, uint16_t *distance);
void distance_us_rear_update(aci_state_t *aci_state, uint16_t *distance);
void distance_us_rear_send_update(aci_state_t *aci_state, uint8_t distance[PIPE_DISTANCE_DISTANCEUSREAR_TX_MAX_SIZE]);

#endif /* DISTANCE_US_REAR_H_ */