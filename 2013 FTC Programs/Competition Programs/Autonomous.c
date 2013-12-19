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

#include "JoystickDriver.c"
#include "autoFunctions.h"

void initializeRobot(){

	return;
}


task main()
{
  initializeRobot();

    waitForStart();

    turnLeft(_45DEGREES - 35);
    delayStop(10);

    moveBackward(32);
    delayStop(10);

    turnLeft(_90DEGREES);
    delayStop(10);

    timedMove(5, 100, -1); // 5 seconds, 100 power, backwards
    stopDrive();
    delayStop(0);
    timedMove(3, 100, 1); // 3 seconds, 100 power, forward
    stopDrive();
    delayStop(0);
    timedMove(4, 100, -1); // 4 seconds, 100 power, backwards
    stopDrive();
    delayStop(0);

    gotoIR_FORWARD();
    storeEncoderValues();
    resetEnc();
    delayStop(300);

    turnRight(_90DEGREES - 35);
    resetEnc();
    delayStop(0);


}
