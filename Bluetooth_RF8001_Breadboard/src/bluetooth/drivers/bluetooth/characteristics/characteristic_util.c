/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the Characteristic Utilities
 */

#include "characteristic_util.h"

// Put a 16 bit value in two 8 bit values
uint8_t toBluetoothData(uint16_t input_value, length) {
	uint8_t output_val[2];
	
	output_val[0] = (input_value >> 8);
	output_val[1] = input_value;
	
	return output_val;
}

// extract a 16bit value from two 8 bit values
uint16_t fromBluetoothData(uint8_t input_value[2]) {
	return ((uint16_t) input_value << 8) | input_value[1];
}