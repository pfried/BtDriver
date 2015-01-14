/*  GlobalDefinitions.h
 *	2.0, 2014-02-12
 *	
 *		Here are all global "#define"'s implemented
 *
 *	(C) 2014 IAS, Universitaet Stuttgart
 *	Author: Jonathan Mueller
 *	Changed by: Michael Neumeier
 *	Changed by: Jonathan Mueller
 */

#ifndef GLOBALDEFINITIONS_H_
#define GLOBALDEFINITIONS_H_


/****************************   CLOCK   ****************************/

#define	F_CPU					  32000000UL



/****************************    PWM    ****************************/

#define	PWM_MAX_FORWARD					 500 
#define PWM_MIN_FORWARD					 725
#define PWM_MIN_REVERSE					 775
#define PWM_MAX_REVERSE					1000

#define PWM_MIN_LEFT					 725
#define PWM_MIN_RIGHT					 775

#define STEERING_SERVO_AHEAD			 750
#define SENSOR_SERVO_AHEAD				 750



/****************************   REMOTE  ****************************/

#define DRIVING_DIRECTION				0x00
#define STEERING_DIRECTION				0x01
#define LIGHT_STATUS					0x02
#define HORN_STATUS						0x03

#define LIGHT_OFF						0x00
#define LIGHT_AUTOMATIC					0x01
#define LIGHT_ON						0x02



/****************************    HORN   ****************************/

#define HORN_OFF						0x00
#define HORN_ON							0x01



/****************************    LED   *****************************/

#define LED_ON					1
#define LED_OFF					0

#define LED_TURNLEFT			0
#define LED_TURNRIGHT			1


/****************************   SENSOR  ****************************/

#define FRONT_SONIC						0x00
#define REAR_SONIC						0x01

#define FRONT_IR						0x00
#define REAR_IR							0x01


/****************************   Custom  ****************************/


#endif /* GLOBALDEFINITIONS_H_ */




