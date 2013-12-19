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

//#include "autoFunctions.h"
#include "JoystickDriver.c"
#include "autoFunctions.h"

task main(){

	waitForStart();
//	turnRight(_45DEGREES);
//	delayStop(1000);
//	turnLeft(_45DEGREES);
//	delayStop(1000);

////need to get _90DEGREES right, so that it will make for easier allignment.
//	turnLeft(_90DEGREES);
//	delayStop(1000);
//	turnRight(_90DEGREES);
//	delayStop(1000);


//	turnLeft(_180DEGREES);
//	delayStop(1000);
//	turnRight(_180DEGREES);
//	delayStop(1000);


//	turnLeft(_360DEGREES);
//	delayStop(1000);
//	turnRight(_360DEGREES);
//	delayStop(1000);
		turnRight(_90DEGREES + 100);
		delayStop(500);

		turnLeft(_90DEGREES + 100);
		delayStop(500);

		turnRight(_90DEGREES);
		delayStop(500);
	}
