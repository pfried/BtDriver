/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the actors characteristic
 */ 

#ifndef ACTORS_H_
#define ACTORS_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"

#define HORN_LVL_THRESHOLD 1
#define LIGHTS_LVL_THRESHOLD 1
#define GENERIC_ACTOR_1_LVL_THRESHOLD 1
#define GENERIC_ACTOR_2_LVL_THRESHOLD 1

void actors_init(uint8_t *horn, uint8_t *lights, uint16_t *generic_actor_1, uint16_t *generic_actor_2);
void actors_on_pipe_status(aci_state_t *aci_state, uint8_t *horn, uint8_t *lights, uint16_t *generic_actor_1, uint16_t *generic_actor_2);
void actors_update(aci_state_t *aci_state, uint8_t *horn, uint8_t *lights, uint16_t *generic_actor_1, uint16_t *generic_actor_2);
void actors_send_update(aci_state_t *aci_state, uint8_t actors[PIPE_ACTORS_ACTORS_TX_MAX_SIZE]);

#endif /* ACTORS_H_ */