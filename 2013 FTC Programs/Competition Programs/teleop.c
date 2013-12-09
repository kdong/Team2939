#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S2,     sensorIR,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          motorFlip,     tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          motorFlag,     tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          motorFlag2,    tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorRight,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorLeft,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorHang,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorLift,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorRoller,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servoSensor,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    cServo,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_3,    cServoII,             tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "teleopFunctions.h"



task main()
{

  initializeRobot(); // retract servo
  waitForStart();

  while (true) {
  	getJoystickSettings(joystick);
  	 // wait1Msec(5); <- see no reason for this to be there, but keeping it just in case.
		StartTask(tsk_r_drive); // joy1Y2
		StartTask(tsk_l_drive); // joy1Y1

 		StartTask(tsk_roller); // joy1Btn(5) and joy1Btn(7)
  	StartTask(tsk_flip); // joy2 d-pad up and down
  	StartTask(tsk_hang); // joy2Y2
  	StartTask(tsk_lift); // joy2Y1

  	}
}
