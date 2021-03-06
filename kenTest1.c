#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     sensorIR,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     sensorLight,    sensorLightActive)
#pragma config(Motor,  motorA,          motorFlip,     tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          motorFlag,     tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          motorFlag2,    tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorRight,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorLeft,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorHang,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorLift,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorRoller,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servoSensor,          tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_2,    cServo,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "autoFunctions.h"


void initializeRobot()
{

  return;
}

void moveForward(int rInches, int mPower){
	int conInches = rInches * 150; // gets motor encoder ticks from rInches
	resetEnc();
	nMotorEncoderTarget[motorRight] = conInches;
	nMotorEncoderTarget[motorLeft] = conInches;

	motor[motorRight] = mPower;
	motor[motorLeft] = mPower;

	while(nMotorRunState[motorRight] != runStateIdle){
		eStop();
	}
}

void moveBackward(int rInches, int mPower){
	int conInches = -rInches * 150; // gets motor encoder ticks from rInches
	resetEnc();
	nMotorEncoderTarget[motorRight] = conInches;
	nMotorEncoderTarget[motorLeft] = conInches;

	motor[motorRight] = -mPower;
	motor[motorLeft] = -mPower;

	while(nMotorRunState[motorRight] != runStateIdle){
		eStop();
	}
}

task main()
{
  initializeRobot();

  waitForStart();

}
