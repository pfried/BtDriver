/* 
* Copyright (c) 2013, Nordic Semiconductor ASA
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
* 
* - Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
* 
* - Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or
*   other materials provided with the distribution.
* 
* - The name of Nordic Semiconductor ASA may not be used to endorse or promote
*   products derived from this software without specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
* This file is autogenerated by nRFgo Studio 1.16.1.3119 
*/

#ifndef SETUP_MESSAGES_H__
#define SETUP_MESSAGES_H__

#include "hal_platform.h" 
#include "aci.h"

// You have now chosen to upload the configuration to OTP on the device.
// This will result in a device that you can not modify afterwards. If this is your intention,
// remove this comment and the #error below
#error Generating configuration for OTP. Please verify usage by removing this error message from include file.

#define SETUP_ID 0
#define SETUP_FORMAT 3 /** nRF8001 D */
#define ACI_DYNAMIC_DATA_SIZE 248

/* Service: Gap - Characteristic: Device name - Pipe: SET */
#define PIPE_GAP_DEVICE_NAME_SET          1
#define PIPE_GAP_DEVICE_NAME_SET_MAX_SIZE 10

/* Service: Brightness - Characteristic: Brightness - Pipe: TX */
#define PIPE_BRIGHTNESS_BRIGHTNESS_TX          2
#define PIPE_BRIGHTNESS_BRIGHTNESS_TX_MAX_SIZE 2

/* Service: Distance - Characteristic: DistanceIRFront - Pipe: TX */
#define PIPE_DISTANCE_DISTANCEIRFRONT_TX          3
#define PIPE_DISTANCE_DISTANCEIRFRONT_TX_MAX_SIZE 2

/* Service: Distance - Characteristic: DistanceIRRear - Pipe: TX */
#define PIPE_DISTANCE_DISTANCEIRREAR_TX          4
#define PIPE_DISTANCE_DISTANCEIRREAR_TX_MAX_SIZE 2

/* Service: Distance - Characteristic: DistanceUSFront - Pipe: TX */
#define PIPE_DISTANCE_DISTANCEUSFRONT_TX          5
#define PIPE_DISTANCE_DISTANCEUSFRONT_TX_MAX_SIZE 2

/* Service: Distance - Characteristic: DistanceUSRear - Pipe: TX */
#define PIPE_DISTANCE_DISTANCEUSREAR_TX          6
#define PIPE_DISTANCE_DISTANCEUSREAR_TX_MAX_SIZE 2

/* Service: Distance - Characteristic: SensorServo - Pipe: TX */
#define PIPE_DISTANCE_SENSORSERVO_TX          7
#define PIPE_DISTANCE_SENSORSERVO_TX_MAX_SIZE 2

/* Service: Distance - Characteristic: SensorServo - Pipe: RX */
#define PIPE_DISTANCE_SENSORSERVO_RX          8
#define PIPE_DISTANCE_SENSORSERVO_RX_MAX_SIZE 2

/* Service: Lights - Characteristic: Lights - Pipe: TX */
#define PIPE_LIGHTS_LIGHTS_TX          9
#define PIPE_LIGHTS_LIGHTS_TX_MAX_SIZE 1

/* Service: Lights - Characteristic: Lights - Pipe: RX_ACK_AUTO */
#define PIPE_LIGHTS_LIGHTS_RX_ACK_AUTO          10
#define PIPE_LIGHTS_LIGHTS_RX_ACK_AUTO_MAX_SIZE 1

/* Service: Horn - Characteristic: Horn - Pipe: TX */
#define PIPE_HORN_HORN_TX          11
#define PIPE_HORN_HORN_TX_MAX_SIZE 1

/* Service: Horn - Characteristic: Horn - Pipe: RX */
#define PIPE_HORN_HORN_RX          12
#define PIPE_HORN_HORN_RX_MAX_SIZE 1

/* Service: Drive - Characteristic: SpeedAndAngle - Pipe: RX */
#define PIPE_DRIVE_SPEEDANDANGLE_RX          13
#define PIPE_DRIVE_SPEEDANDANGLE_RX_MAX_SIZE 4

/* Service: Drive - Characteristic: SpeedMode - Pipe: TX */
#define PIPE_DRIVE_SPEEDMODE_TX          14
#define PIPE_DRIVE_SPEEDMODE_TX_MAX_SIZE 1

/* Service: Drive - Characteristic: SpeedMode - Pipe: RX_ACK_AUTO */
#define PIPE_DRIVE_SPEEDMODE_RX_ACK_AUTO          15
#define PIPE_DRIVE_SPEEDMODE_RX_ACK_AUTO_MAX_SIZE 1

/* Service: BatteryLevel - Characteristic: BatteryLevel - Pipe: TX */
#define PIPE_BATTERYLEVEL_BATTERYLEVEL_TX          16
#define PIPE_BATTERYLEVEL_BATTERYLEVEL_TX_MAX_SIZE 2

/* Service: Generic - Characteristic: GenericActor1 - Pipe: TX */
#define PIPE_GENERIC_GENERICACTOR1_TX          17
#define PIPE_GENERIC_GENERICACTOR1_TX_MAX_SIZE 2

/* Service: Generic - Characteristic: GenericActor1 - Pipe: RX_ACK_AUTO */
#define PIPE_GENERIC_GENERICACTOR1_RX_ACK_AUTO          18
#define PIPE_GENERIC_GENERICACTOR1_RX_ACK_AUTO_MAX_SIZE 2

/* Service: Generic - Characteristic: GenericActor2 - Pipe: TX */
#define PIPE_GENERIC_GENERICACTOR2_TX          19
#define PIPE_GENERIC_GENERICACTOR2_TX_MAX_SIZE 2

/* Service: Generic - Characteristic: GenericActor2 - Pipe: RX_ACK_AUTO */
#define PIPE_GENERIC_GENERICACTOR2_RX_ACK_AUTO          20
#define PIPE_GENERIC_GENERICACTOR2_RX_ACK_AUTO_MAX_SIZE 2


#define NUMBER_OF_PIPES 20

#define SERVICES_PIPE_TYPE_MAPPING_CONTENT {\
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_RX},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_RX_ACK_AUTO},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_RX},   \
  {ACI_STORE_LOCAL, ACI_RX},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_RX_ACK_AUTO},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_RX_ACK_AUTO},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_RX_ACK_AUTO},   \
}

#define GAP_PPCP_MAX_CONN_INT 0xffff /**< Maximum connection interval as a multiple of 1.25 msec , 0xFFFF means no specific value requested */
#define GAP_PPCP_MIN_CONN_INT  0xffff /**< Minimum connection interval as a multiple of 1.25 msec , 0xFFFF means no specific value requested */
#define GAP_PPCP_SLAVE_LATENCY 0
#define GAP_PPCP_CONN_TIMEOUT 0xffff /** Connection Supervision timeout multiplier as a multiple of 10msec, 0xFFFF means no specific value requested */

#define NB_SETUP_MESSAGES 47
#define SETUP_MESSAGES_CONTENT {\
    {0x00,\
        {\
            0x07,0x06,0x00,0x00,0x03,0x02,0x41,0xfe,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x14,0x01,0x01,0x00,0x00,0x06,0x00,0x01,\
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x03,0x90,0x01,0xff,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x38,0xff,0xff,0x02,0x58,0x0a,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,\
            0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x05,0x06,0x10,0x54,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x00,0x04,0x04,0x02,0x02,0x00,0x01,0x28,0x00,0x01,0x00,0x18,0x04,0x04,0x05,0x05,0x00,\
            0x02,0x28,0x03,0x01,0x0e,0x03,0x00,0x00,0x2a,0x04,0x14,0x0a,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x1c,0x06,0x00,0x03,0x2a,0x00,0x01,0x69,0x61,0x73,0x43,0x61,0x72,0x73,0x65,0x6d,0x69,\
            0x04,0x04,0x05,0x05,0x00,0x04,0x28,0x03,0x01,0x02,0x05,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x38,0x01,0x2a,0x06,0x04,0x03,0x02,0x00,0x05,0x2a,0x01,0x01,0x00,0x00,0x04,0x04,0x05,\
            0x05,0x00,0x06,0x28,0x03,0x01,0x02,0x07,0x00,0x04,0x2a,0x06,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x54,0x04,0x09,0x08,0x00,0x07,0x2a,0x04,0x01,0xff,0xff,0xff,0xff,0x00,0x00,0xff,0xff,\
            0x04,0x04,0x02,0x02,0x00,0x08,0x28,0x00,0x01,0x01,0x18,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x70,0x04,0x02,0x02,0x00,0x09,0x28,0x00,0x01,0x50,0x00,0x04,0x04,0x13,0x13,0x00,0x0a,\
            0x28,0x03,0x01,0x12,0x0b,0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x8c,0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x51,0x00,0x5f,0x5d,0x16,0x04,0x03,0x02,0x00,0x0b,\
            0x00,0x51,0x02,0x00,0x00,0x46,0x14,0x03,0x02,0x00,0x0c,0x29,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xa8,0x02,0x01,0x00,0x00,0x04,0x04,0x10,0x10,0x00,0x0d,0x28,0x00,0x01,0x1b,0xc5,0xd5,\
            0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x40,0x00,0x5f,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xc4,0x5d,0x04,0x04,0x13,0x13,0x00,0x0e,0x28,0x03,0x01,0x12,0x0f,0x00,0x1b,0xc5,0xd5,\
            0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x43,0x00,0x5f,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xe0,0x5d,0x16,0x04,0x03,0x02,0x00,0x0f,0x00,0x43,0x02,0x00,0x00,0x46,0x14,0x03,0x02,\
            0x00,0x10,0x29,0x02,0x01,0x00,0x00,0x04,0x04,0x13,0x13,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xfc,0x11,0x28,0x03,0x01,0x12,0x12,0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,\
            0x11,0x70,0xe6,0x44,0x00,0x5f,0x5d,0x16,0x04,0x03,0x02,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x18,0x12,0x00,0x44,0x02,0x00,0x00,0x46,0x14,0x03,0x02,0x00,0x13,0x29,0x02,0x01,0x00,\
            0x00,0x04,0x04,0x13,0x13,0x00,0x14,0x28,0x03,0x01,0x12,0x15,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x34,0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x41,0x00,0x5f,\
            0x5d,0x16,0x04,0x03,0x02,0x00,0x15,0x00,0x41,0x02,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x50,0x46,0x14,0x03,0x02,0x00,0x16,0x29,0x02,0x01,0x00,0x00,0x04,0x04,0x13,0x13,0x00,\
            0x17,0x28,0x03,0x01,0x12,0x18,0x00,0x1b,0xc5,0xd5,0xa5,0x02,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x6c,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x42,0x00,0x5f,0x5d,0x16,0x04,0x03,0x02,0x00,\
            0x18,0x00,0x42,0x02,0x00,0x00,0x46,0x14,0x03,0x02,0x00,0x19,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x88,0x29,0x02,0x01,0x00,0x00,0x04,0x04,0x13,0x13,0x00,0x1a,0x28,0x03,0x01,0x16,0x1b,\
            0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xa4,0xe6,0x45,0x00,0x5f,0x5d,0x56,0x14,0x03,0x02,0x00,0x1b,0x00,0x45,0x02,0x00,0x00,\
            0x46,0x14,0x03,0x02,0x00,0x1c,0x29,0x02,0x01,0x00,0x00,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xc0,0x04,0x10,0x10,0x00,0x1d,0x28,0x00,0x01,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,\
            0xe3,0x11,0x70,0xe6,0x20,0x00,0x5f,0x5d,0x04,0x04,0x13,0x13,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xdc,0x00,0x1e,0x28,0x03,0x01,0x1a,0x1f,0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,\
            0xe3,0x11,0x70,0xe6,0x21,0x00,0x5f,0x5d,0x56,0x14,0x02,0x01,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xf8,0x00,0x1f,0x00,0x21,0x02,0x00,0x46,0x14,0x03,0x02,0x00,0x20,0x29,0x02,0x01,0x00,\
            0x00,0x04,0x04,0x10,0x10,0x00,0x21,0x28,0x00,0x01,0x1b,0xc5,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x14,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x10,0x00,0x5f,0x5d,0x04,0x04,\
            0x13,0x13,0x00,0x22,0x28,0x03,0x01,0x16,0x23,0x00,0x1b,0xc5,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x30,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x11,0x00,0x5f,0x5d,0x56,0x14,\
            0x02,0x01,0x00,0x23,0x00,0x11,0x02,0x00,0x46,0x14,0x03,0x02,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x4c,0x00,0x24,0x29,0x02,0x01,0x00,0x00,0x04,0x04,0x10,0x10,0x00,0x25,0x28,0x00,0x01,\
            0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x68,0x00,0x00,0x5f,0x5d,0x04,0x04,0x13,0x13,0x00,0x26,0x28,0x03,0x01,0x06,0x27,0x00,\
            0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x84,0x01,0x00,0x5f,0x5d,0x46,0x14,0x05,0x04,0x00,0x27,0x00,0x01,0x02,0x00,0x00,0x00,\
            0x00,0x04,0x04,0x13,0x13,0x00,0x28,0x28,0x03,0x01,0x1a,0x29,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0xa0,0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x02,0x00,0x5f,\
            0x5d,0x56,0x14,0x02,0x01,0x00,0x29,0x00,0x02,0x02,0x00,0x46,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0xbc,0x14,0x03,0x02,0x00,0x2a,0x29,0x02,0x01,0x00,0x00,0x04,0x04,0x10,0x10,0x00,0x2b,\
            0x28,0x00,0x01,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0xd8,0x11,0x70,0xe6,0x30,0x00,0x5f,0x5d,0x04,0x04,0x13,0x13,0x00,0x2c,0x28,0x03,0x01,\
            0x12,0x2d,0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0xf4,0x11,0x70,0xe6,0x31,0x00,0x5f,0x5d,0x16,0x04,0x03,0x02,0x00,0x2d,0x00,0x31,0x02,\
            0x00,0x00,0x46,0x14,0x03,0x02,0x00,0x2e,0x29,0x02,0x01,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x23,0x10,0x00,0x04,0x04,0x10,0x10,0x00,0x2f,0x28,0x00,0x01,0x1b,0xc5,0xd5,0xa5,0x02,0x00,\
            0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x70,0x00,0x5f,0x5d,0x04,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x23,0x2c,0x13,0x13,0x00,0x30,0x28,0x03,0x01,0x1a,0x31,0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,\
            0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x71,0x00,0x5f,0x5d,0x56,0x14,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x23,0x48,0x03,0x02,0x00,0x31,0x00,0x71,0x02,0x00,0x00,0x46,0x14,0x03,0x02,0x00,0x32,0x29,\
            0x02,0x01,0x00,0x00,0x04,0x04,0x13,0x13,0x00,0x33,0x28,0x03,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x23,0x64,0x01,0x1a,0x34,0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,\
            0x72,0x00,0x5f,0x5d,0x56,0x14,0x03,0x02,0x00,0x34,0x00,0x72,\
        },\
    },\
    {0x00,\
        {\
            0x12,0x06,0x23,0x80,0x02,0x00,0x00,0x46,0x14,0x03,0x02,0x00,0x35,0x29,0x02,0x01,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x00,0x2a,0x00,0x01,0x00,0x80,0x04,0x00,0x03,0x00,0x00,0x00,0x51,0x02,0x00,0x02,0x04,\
            0x00,0x0b,0x00,0x0c,0x00,0x43,0x02,0x00,0x02,0x04,0x00,0x0f,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x1c,0x00,0x10,0x00,0x44,0x02,0x00,0x02,0x04,0x00,0x12,0x00,0x13,0x00,0x41,0x02,0x00,\
            0x02,0x04,0x00,0x15,0x00,0x16,0x00,0x42,0x02,0x00,0x02,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x38,0x00,0x18,0x00,0x19,0x00,0x45,0x02,0x00,0x0a,0x04,0x00,0x1b,0x00,0x1c,0x00,0x21,\
            0x02,0x04,0x02,0x04,0x00,0x1f,0x00,0x20,0x00,0x11,0x02,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x54,0x0a,0x04,0x00,0x23,0x00,0x24,0x00,0x01,0x02,0x00,0x08,0x04,0x00,0x27,0x00,0x00,\
            0x00,0x02,0x02,0x04,0x02,0x04,0x00,0x29,0x00,0x2a,0x00,0x31,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x70,0x02,0x00,0x02,0x04,0x00,0x2d,0x00,0x2e,0x00,0x71,0x02,0x04,0x02,0x04,0x00,0x31,\
            0x00,0x32,0x00,0x72,0x02,0x04,0x02,0x04,0x00,0x34,0x00,0x35,\
        },\
    },\
    {0x00,\
        {\
            0x13,0x06,0x50,0x00,0x1b,0xc5,0xd5,0xa5,0x02,0x00,0xf3,0xa4,0xe3,0x11,0x70,0xe6,0x00,0x00,0x5f,0x5d,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x11,0x06,0x60,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x06,0x06,0xf0,0x00,0x83,0x64,0x7e,\
        },\
    },\
}

#endif
