#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motor1,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motor2,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motor3,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motor4,        tmotorTetrix, openLoop)

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.



void initializeRobot()
{
  return;
}

task main()
{
  initializeRobot();

  waitForStart();   // wait for start of tele-op phase


  int scale = 5;
	int dZone = 20;

  while (true)
  {
  	getJoystickSettings(joystick);
  	/*motor[motor1] = (-1 * joystick.joy1_y1) - (joystick.joy1_x1) - (joystick.joy1_x2);
  	motor[motor2] = (1 * joystick.joy1_y1) - (joystick.joy1_x1) - (joystick.joy1_x2);
  	motor[motor3] = (-1 * joystick.joy1_y1) + (joystick.joy1_x1) - (joystick.joy1_x2);
  	motor[motor4] = (1 * joystick.joy1_y1) + (joystick.joy1_x1) - (joystick.joy1_x2);
  	//joystick.joy1_y1
    */

   // y1 axis and the x1 axis make up the strafing movements,
    // while the x2 axis controls the rotation
    // front left = motor1
    // front right = motor2
    // back left = motor 3
    // back right = motor 4



	//essential code for holonomic drive
    motor[motor1] = (-1 * joystick.joy1_y1) + (joystick.joy1_x1) - (joystick.joy1_x2);
    motor[motor2] = (-1 * joystick.joy1_y1) - (joystick.joy1_x1) - (joystick.joy1_x2);
    motor[motor3] = (1 * joystick.joy1_y1) + (joystick.joy1_x1) - (joystick.joy1_x2);
    motor[motor4] = (1 * joystick.joy1_y1) + (joystick.joy1_x1) - (joystick.joy1_x2);

    //not sure if this works, but if it does, it should increase the speed of the robot
    //by pressing whatever button 3 is
    if(joy1Btn(3)){
    	motor[motor1] = motor1 * scale;
    	motor[motor2] = motor2 * scale;
    	motor[motor3] = motor3 * scale;
    	motor[motor4] = motor4 * scale;
    }


    // put deadzones here for accuracy

  }
}
