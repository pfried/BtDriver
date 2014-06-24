BtDriver
========

Bluetooth Low Energy nRF8001 Driver for XMEGA

Studienarbeit Friedrich Mäckle IAS Universtiy of Stuttgart, 2014

# Ported Driver from Nordic Semiconductor
The Bluetooth Driver consists of the actual driver which is a port to XMEGA from the Nordic Semiconductor Driver for Arduino: https://github.com/NordicSemiconductor/ble-sdk-arduino

There are changes regarding:
1. delay_routine
2. interrupt control
3. SPI control
4. IO
5. Removed all Arduino specific code like debug prints
6. Changed included libaries to have correct data types in place

The driver supports both interrupt and polling interface of the driver.

# Bluetooth Driver

## ASF

The driver uses the Atmel Software Foundation Framework to interact with SPI, delay and GPIO

# Bluetooth Service

The Bluetooth Service provides an interface to the IAS Teamarbeit (Teamwork). The students in the course program a remote controlled car which is equipped with several sensors. The students implement a simple driver assistant.

The Service provides:

* A setup routing which must be called once on setup: `car_bluetooth_setup`
* A process routing which processes incoming data, should be called on the beginning of the main loop: `car_bluetooth_process`










