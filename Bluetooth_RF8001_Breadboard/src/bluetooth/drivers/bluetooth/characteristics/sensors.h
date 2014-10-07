/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the sensors characteristic
 */

#ifndef SENSORS_H_
#define SENSORS_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"

#define BRIGHTNESS_LVL_CHANGE_THRESHOLD 1
#define TEMPERATURE_LVL_CHANGE_THRESHOLD 1
#define BATTERY_LVL_CHANGE_THRESHOLD 1

void sensors_init(uint16_t *brightness, uint16_t *temperature, uint16_t * battery);
void sensors_on_pipe_status(aci_state_t *aci_state, uint16_t *brightness, uint16_t *temperature, uint16_t * battery);
void sensors_update(aci_state_t *aci_state,uint16_t *brightness, uint16_t *temperature, uint16_t * battery);
void sensors_send_update(aci_state_t *aci_state, uint8_t sensors[PIPE_SENSORS_SENSORS_TX_MAX_SIZE]);

#endif /* SENSORS_H_ */