#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     sensorIR,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          motorFlip,     tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          motorFlag,     tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          motorFlag2,    tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorRight,    tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorLeft,     tmotorTetrix, PIDControl, reversed, encoder)
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

//auto code

#include "autoFunctions.h"
#include "JoystickDriver.c"


task main()
{
  	initializeRobotAUTO();
  	resetEnc();
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
	moveForwardif(1.75);
	delayStop(200);

	turnLeft(_90DEGREES);
	delayStop(500);

	moveBackward(7);
	resetEnc();
	scoreAuto();
	moveForward(3.5);
	resetEnc();
	delayStop(300);

	turnRight(_90DEGREES);
	resetEnc();
	stopDrive();
	delayStop(300);

	gotoEnd_for();
	delayStop(300);

	turnLeft(_135DEGREES + 215);
	delayStop(300);

	moveBackward(28.9);
	delayStop(300);

	turnRight(_90DEGREES + 135);
	delayStop(200);

	moveBackward(39.5);
	delayStop(200);

	moveForward(3.5);
	delayStop(350);

	moveBackward(3.5);
	delayStop(350);

	retractServo();
	stopDrive();
	secondTest = false;
}
	for(;;){}//loop forever
}
