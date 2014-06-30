/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the generic actor 1 characteristic
 */

#ifndef GENERIC_ACTOR_2_H_
#define GENERIC_ACTOR_2_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"
#include "characteristic_util.h"

#define GENERIC_ACTOR_2_LVL_THRESHOLD 1

void generic_actor_2_init(uint16_t *generic_actor_2);
void generic_actor_2_on_pipe_status(aci_state_t *aci_state, uint16_t *generic_actor_2);
void generic_actor_2_update(aci_state_t *aci_state, uint16_t *generic_actor_2);
void generic_actor_2_send_update(aci_state_t *aci_state, uint8_t generic_actor_2[PIPE_GENERIC_GENERICACTOR2_TX_MAX_SIZE]);

#endif /* GENERIC_ACTOR_2_H_ */