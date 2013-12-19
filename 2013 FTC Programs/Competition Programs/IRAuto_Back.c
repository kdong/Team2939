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
//auto code

#include "autoFunctions.h"
#include "JoystickDriver.c"

task main()
{
  	initializeRobot();
  	resetEnc();
  	//will reset motor encoders
  	waitForStart();
  	determineFirst();
  	while(firstTest == true){
  	rotateServo();
  }

while(secondTest == false){
	stopDrive();
}

while(secondTest == true){
	gotoIR_FORWARD();
	storeEncoderValues();
	resetEnc();
	delayStop(500);

	//switch case
	moveForwardif(2.75);
	delayStop(2);

	turnLeft(_135DEGREES + 150);
	delayStop(500);

	moveBackward(8.75);
	resetEnc();
	scoreAuto();
	moveForward(3.3);
	resetEnc();
	delayStop(300);

	turnRight(_90DEGREES);
	resetEnc();
	delayStop(300);

	gotoEnd_for();
	delayStop(300);

	turnLeft(_135DEGREES - 25);
	delayStop(300);

	moveBackward(25);
	delayStop(300);

	turnRight(_90DEGREES + 50);
	delayStop(200);

	moveBackwardSec(2.5);
	delayStop(200);

	retractServo();
	stopDrive();
	secondTest = false;
}
	for(;;){}//loop forever
}
