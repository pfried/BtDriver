/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the horn characteristic
 */

#include "horn.h"

static uint8_t horn_value[PIPE_HORN_HORN_TX_MAX_SIZE];

static uint8_t *oldHorn;

void horn_init(uint8_t *horn) {
	oldHorn = horn;
}

void horn_update(aci_state_t *aci_state, uint8_t *horn) {
	
	uint16_t horn_difference = 0;
	
	if(*horn != *oldHorn) {
		if(*horn < *oldHorn) {
			horn_difference = *oldHorn - *horn;
			} else {
			horn_difference = *horn - *oldHorn;
		}
	}
	
	if(horn_difference >= HORN_LVL_THRESHOLD) {
		
		horn_value[0] = *horn;
		
		lib_aci_set_local_data(PIPE_HORN_HORN_TX, horn_value, PIPE_HORN_HORN_TX_MAX_SIZE);
		
		if(lib_aci_is_pipe_available(aci_state, PIPE_HORN_HORN_TX)) {
			if (aci_state->data_credit_available > 0) {
				horn_send_update(aci_state, horn_value);
			}
		}
		
		*oldHorn = *horn;
	}
}

void horn_on_pipe_status(aci_state_t *aci_state, uint8_t *horn) {
	if(lib_aci_is_pipe_available(aci_state, PIPE_HORN_HORN_TX)) {
		horn_value[0] = *horn;
		horn_send_update(aci_state, horn_value);
	}
}

void horn_send_update(aci_state_t *aci_state, uint8_t horn[PIPE_HORN_HORN_TX]) {
	if (lib_aci_send_data(PIPE_HORN_HORN_TX, horn, PIPE_HORN_HORN_TX_MAX_SIZE)) {
		aci_state->data_credit_available--;
	}
}