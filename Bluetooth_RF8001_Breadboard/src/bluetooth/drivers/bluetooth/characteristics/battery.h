/*
 * battery.h
 *
 * Created: 29.06.2014 18:22:17
 *  Author: fried_000
 */ 

#ifndef BATTERY_H_
#define BATTERY_H_

#define BATTERY_LVL_THRESHOLD 1

void battery_init(uint16_t *battery);
void battery_on_pipe_status(aci_state_t *aci_state, uint16_t *battery);
void battery_update(aci_state_t *aci_state, uint16_t *battery);
void battery_send_update(aci_state_t *aci_state, uint8_t battery[PIPE_BATTERYLEVEL_BATTERYLEVEL_TX_MAX_SIZE]);

#endif /* BATTERY_H_ */