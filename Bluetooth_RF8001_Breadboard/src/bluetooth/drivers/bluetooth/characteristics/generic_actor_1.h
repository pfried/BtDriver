/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the generic actor 1 characteristic
 */

#ifndef GENERIC_ACTOR_1_H_
#define GENERIC_ACTOR_1_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"
#include "characteristic_util.h"

#define GENERIC_ACTOR_1_LVL_THRESHOLD 1

void generic_actor_1_init(uint16_t *generic_actor_1);
void generic_actor_1_on_pipe_status(aci_state_t *aci_state, uint16_t *generic_actor_1);
void generic_actor_1_update(aci_state_t *aci_state, uint16_t *generic_actor_1);
void generic_actor_1_send_update(aci_state_t *aci_state, uint8_t generic_actor_1[PIPE_GENERIC_GENERICACTOR1_TX_MAX_SIZE]);

#endif /* GENERIC_ACTOR_1_H_ */