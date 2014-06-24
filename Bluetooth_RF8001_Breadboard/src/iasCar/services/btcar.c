/*
 * iascar.c
 *
 * Created: 22.05.2014 11:56:59
 *  Author: Friedrich Maeckle
 */

#include "btcar.h"
#include "bluetooth.h"
#include "bt_active_led.h"

bluetooth_car_t bluetooth_car;

// A model to synchronize Bluetooth and Car, initialize Values to 0;
void initCarModel(void) {
	bluetooth_car.speed = 0x0000;
	bluetooth_car.direction = 0x0000;
	bluetooth_car.speedMode = 0x00;
	bluetooth_car.battery = 0x0000;
	bluetooth_car.brightness = 0x0000;
	bluetooth_car.distance_ir_front = 0x0000;
	bluetooth_car.distance_ir_rear = 0x0000;
	bluetooth_car.distance_us_front = 0x0000;
	bluetooth_car.distance_us_rear = 0x0000;
	bluetooth_car.temperature = 0x0000;
	bluetooth_car.sensorServo = 0x00;
	bluetooth_car.horn = 0x00;
	bluetooth_car.lights = 0x00;
	bluetooth_car.generic_actor_1 = 0x0000;
	bluetooth_car.generic_actor_2 = 0x0000;
}

void carBluetoothSetup(void) {
	
	// Setup LED
	bluetooth_led_setup();
	
	// Setup BT Driver
	bluetooth_config_t bluetooth_config;
	bluetooth_get_config_defaults(&bluetooth_config);
	bluetooth_init(&bluetooth_config);
	
}

// Process the bluetooth data
void carBluetoothProcess(void) {
	bluetooth_process();
}

uint16_t bluetoothGetSpeed(void) {
	return bluetooth_car.speed;
}

uint16_t bluetoothGetDirection(void) {
	return bluetooth_car.direction;
}

uint8_t bluetoothGetSpeedMode(void) {
	return bluetooth_car.speedMode;
}

uint8_t  bluetoothGetHorn(void) {
	return bluetooth_car.horn;
}
uint8_t  bluetoothGetLights(void) {
	return bluetooth_car.lights;
}

void bluetoothSetBrightness(uint16_t brightness) {
	bluetooth_car.brightness = brightness;
}

void bluetoothSetDistanceIRFront(uint16_t distance) {
	bluetooth_car.distance_ir_front = distance;
}

void bluetoothSetDistanceIRRear(uint16_t distance) {
	bluetooth_car.distance_ir_rear = distance;
}

void bluetoothSetDistanceUSFront(uint16_t distance) {
	bluetooth_car.distance_us_front = distance;
}

void bluetoothSetDistanceUSRear(uint16_t distance) {
	bluetooth_car.distance_us_rear = distance;
}

void bluetoothSetBatteryLevel(uint16_t battery) {
	bluetooth_car.battery = battery;
}

void bluetoothSetGenericActor1(uint16_t actor) {
	bluetooth_car.generic_actor_1 = actor;
}

void bluetoothSetGenericActor2(uint16_t actor) {
	bluetooth_car.generic_actor_2 = actor;
}

