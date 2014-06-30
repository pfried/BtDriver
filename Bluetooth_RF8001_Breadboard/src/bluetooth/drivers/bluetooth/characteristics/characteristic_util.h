/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the Characteristic Utilities
 */ 

#ifndef CHARACTERISTIC_UTIL_H_
#define CHARACTERISTIC_UTIL_H_

#include <stdint.h>

uint8_t toBluetoothData(uint16_t input_value);
uint16_t fromBluetoothData(uint8_t input_value[2]);

#endif /* CHARACTERISTIC_UTIL_H_ */