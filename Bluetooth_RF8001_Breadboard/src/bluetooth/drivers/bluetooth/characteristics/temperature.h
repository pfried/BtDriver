/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the temperature characteristic
 */


#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"

#define TEMPERATURE_LVL_CHANGE_THRESHOLD 1

void temperature_init(uint16_t *temperature);
void temperature_on_pipe_status(aci_state_t *aci_state, uint16_t *temperature);
void temperature_update(aci_state_t *aci_state, uint16_t *temperature);
void temperature_send_update(aci_state_t *aci_state, uint8_t temperature[PIPE_THERMOMETER_TEMPERATURE_TX_MAX_SIZE]);

#endif /* TEMPERATURE_H_ */