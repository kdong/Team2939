#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorRight,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


int circWheel = 2.95 * PI; //which comes out to ~ 9.267inches
int scaledDown = (joystick.joy1_y1) / 1.27;
//distance from one right wheel to left wheel is 13.0 inches
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
 nxtDisplayTextLine(3, "ticks %d", nMotorEncoder[motorRight]);
  return;
}

task main(){
	while(true){
		getJoystickSettings(joystick);
		nxtDisplayTextLine(3, "Ticks: %d", nMotorEncoder[motorRight]);
		motor[motorRight] = (joystick.joy1_y1) / 1.27;
		if(joy1Btn(6)){
			nMotorEncoder[motorRight] = 0;
		}
	}
}
