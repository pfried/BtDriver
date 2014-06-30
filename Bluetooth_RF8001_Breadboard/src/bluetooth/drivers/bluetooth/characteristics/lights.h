/**
 * @author Friedrich M�ckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the lights characteristic
 */

#ifndef LIGHTS_H_
#define LIGHTS_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"
#include "characteristic_util.h"

#define LIGHTS_LVL_THRESHOLD 1

void lights_init(uint8_t *lights);
void lights_on_pipe_status(aci_state_t *aci_state, uint8_t *lights);
void lights_update(aci_state_t *aci_state, uint8_t *lights);
void lights_send_update(aci_state_t *aci_state, uint8_t lights[PIPE_LIGHTS_LIGHTS_TX_MAX_SIZE]);

#endif /* LIGHTS_H_ */