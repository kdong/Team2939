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
#pragma config(Servo,  srvo_S1_C4_1,    servoSensor,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    cServo,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//auto code

#include "autoFunctions.h"



task main()
{
  initializeRobot(); //will reset motor encoders

  waitForStart();

  	initIR(); //[X]
	detectIR(); // []
	turnDegreesRight(90, 90); // []
	moveBackward(4, 60); // [ ]
	scoreAuto();//[	]
							// consists of: 1) Raise scissorLift, 2) Actuate flick down
							// 1) raise scissorLift - 1300 Mseconds at 100%
	turnDegreesLeft(90, 90); // [ ]
	gotoLastCrate(); // [	]
	// algorithm to determine placement
	turnDegreesLeft(90, 90); // [	]
	moveForward(6, 100); //[	]
	// 6 inches, 100% power
	turnDegreesLeft(90, 100); // [	]
	raiseHang(); // [	]
	moveForward(36, 100); // [ ]
	// 3 feet, 100% power
	eStop(); // [X] it should stop, but just incase



}
