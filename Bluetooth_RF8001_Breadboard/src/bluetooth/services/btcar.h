/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Header of the Bluetooth Service
 */

#include <stdint.h>
#include "../drivers/bluetooth/bluetooth.h"
#include "../drivers/bluetooth/lib/services.h"

#ifndef BTCAR_H_
#define BTCAR_H_

#define CONFIG_SWITCH 0x00
#define CONFIG_BUTTON 0x01
#define CONFIG_VALUE  0x02

typedef struct bluetooth_car  {
	uint16_t speed;
	uint16_t direction;
	uint8_t  speedMode;
	uint8_t  horn;
	uint8_t  lights;
	uint16_t battery;
	uint16_t brightness;
	uint16_t sensorServo;
	uint16_t distance_us_front;
	uint16_t distance_us_rear;
	uint16_t distance_ir_front;
	uint16_t distance_ir_rear;
	uint16_t generic_actor_1;
	uint16_t generic_actor_2;
	uint16_t generic_config;
	uint16_t temperature;
	char *name;
} bluetooth_car_t;

void carBluetoothSetup(char name[PIPE_GAP_DEVICE_NAME_SET_MAX_SIZE]);
uint8_t carConfigureButton1(uint8_t config);
uint8_t carConfigureButton2(uint8_t config);

void carBluetoothProcess(void);

static void initCarModel(void);

uint16_t bluetoothGetDirection(void);
uint16_t bluetoothGetSpeed(void);
uint8_t  bluetoothGetSpeedMode(void);
uint16_t bluetoothGetSensorServo(void);
uint8_t  bluetoothGetHorn(void);
uint8_t  bluetoothGetLights(void);

void bluetoothSetDirection(uint16_t direction);
void bluetoothSetSpeed(uint16_t speed);
void bluetoothSetSpeedMode(uint8_t speedMode);
void bluetoothSetHorn(uint8_t horn);
void bluetoothSetLights(uint8_t lights);

void bluetoothSetBrightness(uint16_t brightness);

void bluetoothSetDistanceIRFront(uint16_t distance);
void bluetoothSetDistanceIRRear(uint16_t distance);
void bluetoothSetDistanceUSFront(uint16_t distance);
void bluetoothSetDistanceUSRear(uint16_t distance);

void bluetoothSetBatteryLevel(uint16_t battery);
void bluetoothSetTemperature(uint16_t temperature);

void bluetoothSetSensorServo(uint16_t servo);

void bluetoothSetGenericActor1(uint16_t actor);
uint16_t bluetoothGetGenericActor1(void);
void bluetoothSetGenericActor2(uint16_t actor);
uint16_t bluetoothGetGenericActor2(void);

#endif /* BTCAR_H_ */