/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the speed mode characteristic
 */

#ifndef SPEED_MODE_H_
#define SPEED_MODE_H_

#include "../lib/services.h"
#include "../lib/lib_aci.h"
#include "characteristic_util.h"

#define SPEED_MODE_LVL_THRESHOLD 1

void speed_mode_init(uint8_t *speed_mode);
void speed_mode_on_pipe_status(aci_state_t *aci_state, uint8_t *speed_mode);
void speed_mode_update(aci_state_t *aci_state, uint8_t *speed_mode);
void speed_mode_send_update(aci_state_t *aci_state, uint8_t speed_mode[PIPE_DRIVE_SPEEDMODE_TX_MAX_SIZE]);

#endif /* SPEED_MODE_H_ */