/*
 * btcar.h
 *
 * Created: 22.05.2014 11:56:49
 *  Author: Friedrich Maeckle
 */ 

#include <stdint.h>
#include "bluetooth.h"

#ifndef BTCAR_H_
#define BTCAR_H_

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
	uint16_t temperature;
} bluetooth_car_t;

void carBluetoothSetup(void);
void carBluetoothProcess(void);

static void initCarModel(void);

uint16_t bluetoothGetDirection(void);
uint16_t bluetoothGetSpeed(void);
uint8_t  bluetoothGetSpeedMode(void);
uint8_t  bluetoothGetHorn(void);
uint8_t  bluetoothGetLights(void);

void bluetoothSetBrightness(uint16_t brightness);

void bluetoothSetDistanceIRFront(uint16_t distance);
void bluetoothSetDistanceIRRear(uint16_t distance);
void bluetoothSetDistanceUSFront(uint16_t distance);
void bluetoothSetDistanceUSRear(uint16_t distance);

void bluetoothSetBatteryLevel(uint16_t battery);
void bluetoothSetTemperature(uint16_t temperature);

void bluetoothSetGenericActor1(uint16_t actor);
uint16_t bluetoothGetGenericActor1(void);
void bluetoothSetGenericActor2(uint16_t actor);
uint16_t bluetoothGetGenericActor2(void);

#endif /* BTCAR_H_ */