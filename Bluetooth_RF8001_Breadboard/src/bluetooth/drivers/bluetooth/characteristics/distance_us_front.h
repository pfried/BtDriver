/*
 * distance_us_front.h
 *
 * Created: 29.06.2014 17:00:11
 *  Author: fried_000
 */ 


#ifndef DISTANCE_US_FRONT_H_
#define DISTANCE_US_FRONT_H_

#define DISTANCE_US_FRONT_LVL_THRESHOLD 1

void distance_us_front_init(uint16_t *distance);
void distance_us_front_on_pipe_status(aci_state_t *aci_state, uint16_t *distance);
void distance_us_front_update(aci_state_t *aci_state, uint16_t *distance);
void distance_us_front_send_update(aci_state_t *aci_state, uint8_t distance[PIPE_DISTANCE_DISTANCEUSFRONT_TX_MAX_SIZE]);

#endif /* DISTANCE_US_FRONT_H_ */