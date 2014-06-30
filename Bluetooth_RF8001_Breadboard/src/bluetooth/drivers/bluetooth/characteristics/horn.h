/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the horn characteristic
 */

#ifndef HORN_H_
#define HORN_H_

#define HORN_LVL_THRESHOLD 1

void horn_init(uint8_t *horn);
void horn_on_pipe_status(aci_state_t *aci_state, uint8_t *horn);
void horn_update(aci_state_t *aci_state, uint8_t *horn);
void horn_send_update(aci_state_t *aci_state, uint8_t horn[PIPE_HORN_HORN_TX_MAX_SIZE]);

#endif /* HORN_H_ */