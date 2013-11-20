#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S2,     sensorIR,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     sensorLight,    sensorLightActive)
#pragma config(Sensor, S4,     sensorTouch,    sensorTouch)
#pragma config(Motor,  motorA,          motorFlip,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          motorFlag,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorFlag2,    tmotorNXT, PIDControl, reversed, encoder)
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

#include "JoystickDriver.c"
#include "teleopFunctions.h"

const bool useLogScale = true;

task main()
{
  initializeRobot();
  waitForStart();

  while (true) {
  getJoystickSettings(joystick);
	StartTask(driveCtrl);
	StartTask(operatorCtrl);
  }
}
