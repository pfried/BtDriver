/**
 * @author Friedrich Mäckle
 * @date 2014
 * @copyright IAS, University of Stuttgart, Germany
 *
 * @brief Implementation of the Blueooth Service for the IAS teamwork car.
 * @details  Provides setters and getters for the properties of the car. The car model is used to sync the data with the bluetooth driver. Provide a name to the setup function and the device will shop up in Bluetooth with this name.
 */

#include "btcar.h"
#include "../drivers/bluetooth/bluetooth.h"
#include "../drivers/bt_active_led/bt_active_led.h"

bluetooth_car_t bluetooth_car;
static bool isSafetyStop = false;

// A model to synchronize Bluetooth and Car, initialize Values to 0;
static void initCarModel(void) {
	bluetooth_car.speed = 0x02ee;
	bluetooth_car.direction = 0x02ee;
	bluetooth_car.speedMode = 0x00;
	bluetooth_car.battery = 0x0000;
	bluetooth_car.brightness = 0x0000;
	bluetooth_car.distance_ir_front = 0x0000;
	bluetooth_car.distance_ir_rear = 0x0000;
	bluetooth_car.distance_us_front = 0x0000;
	bluetooth_car.distance_us_rear = 0x0000;
	bluetooth_car.temperature = 0x0000;
	bluetooth_car.sensorServo = 0x02ee;
	bluetooth_car.horn = 0x00;
	bluetooth_car.lights = 0x00;
	bluetooth_car.generic_actor_1 = 0x0000;
	bluetooth_car.generic_actor_2 = 0x0000;
	bluetooth_car.generic_config = 0x0000;
	bluetooth_car.name = "defaultCar";
	bluetooth_car.safetyStop = false;
}

/**
 * @param name max 10 Characters
 */
void carBluetoothSetup(char *name) {
	
	// Setup LED
	bluetooth_led_setup();
	
	initCarModel();
	
	bluetooth_car.name = name;
	
	// Setup BT Driver
	bluetooth_config_t bluetooth_config;
	bluetooth_get_config_defaults(&bluetooth_config);
	bluetooth_init(&bluetooth_config, &bluetooth_car);
	
}

void setBit(uint8_t *byte_value, char status, int bit) {
	if(status) {
		*byte_value |= (1 << bit);
	} else {
		*byte_value &= ~(1 << bit);
	}
}


/**
 * The configuration of the buttons is only available on startup as the smartphone app will read it only on connection once
 */
uint8_t carConfigureButton1(uint8_t config) {
	bluetooth_car.generic_config |= config;
}

uint8_t carConfigureButton2(uint8_t config) {
	bluetooth_car.generic_config |= (config << 8);
}

// Process the bluetooth data
void carBluetoothProcess(void) {
	bluetooth_process();
}

uint16_t bluetoothGetSpeed(void) {
	
	if(bluetooth_car.safetyStop == true) {
		return SPEED_STOP;
	}
	
	return bluetooth_car.speed;
}

void bluetoothSetSpeed(uint16_t speed) {
	bluetooth_car.speed = speed;
}

uint16_t bluetoothGetDirection(void) {
	return bluetooth_car.direction;
}

void bluetoothSetDirection(uint16_t direction) {
	bluetooth_car.direction = direction;
}

uint8_t bluetoothGetSpeedMode(void) {
	return bluetooth_car.speedMode;
}

void bluetoothSetSpeedMode(uint8_t speedMode) {
	bluetooth_car.speedMode = speedMode;
}

uint8_t bluetoothGetHorn(void) {		
	return bluetooth_car.horn;
}

void bluetoothSetHorn(uint8_t horn) {
	bluetooth_car.horn = horn;
}

uint8_t bluetoothGetLights(void) {
	return bluetooth_car.lights;
}

void bluetoothSetLights(uint8_t lights) {
	bluetooth_car.lights = lights;
}

void bluetoothSetBrakeLight(int status) {
	setBit(&bluetooth_car.lights, status, 2);
}

void bluetoothSetFrontLight(int status) {
	setBit(&bluetooth_car.lights, status, 0);
}

void bluetoothSetReverseLight(int status) {
	setBit(&bluetooth_car.lights, status, 1);
}

void bluetoothSetTurnSignal(char dir, int status) {
	if(dir == LED_TURNLEFT) {
		setBit(&bluetooth_car.lights, status, 3);
	}
	if(dir == LED_TURNRIGHT) {
		setBit(&bluetooth_car.lights, status, 4);
	}
}

void bluetoothSetBrightness(uint16_t brightness) {
	bluetooth_car.brightness = brightness;
}

void bluetoothSetTemperature(uint16_t temperature) {
	bluetooth_car.temperature = temperature;
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

uint16_t bluetoothGetSensorServo(void) {
	return bluetooth_car.sensorServo;
}

void bluetoothSetSensorServo(uint16_t servo) {
	bluetooth_car.sensorServo = servo;
}

void bluetoothSetGenericActor1(uint16_t actor) {
	bluetooth_car.generic_actor_1 = actor;
}

uint16_t bluetoothGetGenericActor1(void) {
	return bluetooth_car.generic_actor_1;
}

void bluetoothSetGenericActor2(uint16_t actor) {
	bluetooth_car.generic_actor_2 = actor;
}

uint16_t bluetoothGetGenericActor2(void) {
	return bluetooth_car.generic_actor_2;
}