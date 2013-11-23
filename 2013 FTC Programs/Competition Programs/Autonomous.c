#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     sensorIR,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     sensorLight,    sensorLightActive)
#pragma config(Sensor, S4,     sensorTouch,    sensorTouch)
#pragma config(Motor,  motorA,          motorFlip,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorRight,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorLeft,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorHang,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorLift,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorRoller,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorRoller2,  tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    servoSensor,          tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
//#include "autoFunctions.h"

void initializeRobot(){


	return;
}


task main()
{
  initializeRobot(); //will reset motor encoders

  waitForStart();


    motor[motorRight] = -100;
    motor[motorLeft] = -100;
		wait1Msec(2500);
		motor[motorRight] = 0;
		motor[motorLeft] = 0;
		wait1Msec(2000);

}
