/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the brightness characteristic
 */

#ifndef BRIGHTNESS_H_
#define BRIGHTNESS_H_

#define BRIGHTNESS_LVL_CHANGE_THRESHOLD 1

void brightness_init(uint16_t *brightness);
void brightness_on_pipe_status(aci_state_t *aci_state, uint16_t *brightness);
void brightness_update(aci_state_t *aci_state, uint16_t *brightness);
void brightness_send_update(aci_state_t *aci_state, uint8_t brightness[PIPE_BRIGHTNESS_BRIGHTNESS_TX_MAX_SIZE]);

#endif /* BRIGHTNESS_H_ */