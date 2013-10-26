#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motor1,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motor2,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motor3,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motor4,        tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
*	Zenith 2939
*	@author Ken
*
*/


#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void initializeRobot()
{

	return;
}

task main()
{
	initializeRobot();

	waitForStart();

	int x1Val = 0;
	int y1Val = 0;
	int x2Val = 0;
	int y2Val = 0;

	int scale = 5;
	int boundBox = 9;


	int motor1Val = 0;
	int motor2Val = 0;
	int motor3Val = 0;
	int motor4Val = 0;


	while (true)
	{
		getJoystickSettings(joystick);


		if(abs(joystick.joy1_x1) > boundBox)
		{
			x1Val = joystick.joy1_x1 / scale;
		}
		else
		{
			x1Val = 0;
		}

		if(abs(joystick.joy1_y1) > boundBox)
		{
			y1Val = joystick.joy1_y1 / scale;
		}
		else
		{
			y1Val = 0;
		}

		if(abs(joystick.joy1_x2) > boundBox)
		{
			x2Val = joystick.joy1_x2 / scale;
		}
		else
		{
			x2Val = 0;
		}

		if(abs(joystick.joy1_y2) > boundBox)
		{
			y2Val = joystick.joy1_y2 / scale;
		}
		else
		{
			y2Val = 0;
		}



		motor1Val = y1Val + x1Val - x2Val;
		motor2Val = -y1Val + x1Val - x2Val;
		motor3Val = -y1Val - x1Val - x2Val;
		motor4Val = y1Val - x1Val - x2Val;

		if((motor1Val <= 15) &&  (motor1Val >= 15)){
			motor1Val = 0;
		}
		if((motor2Val <= 15) && (motor2Val >= 15)){
			motor2Val = 0;
		}
		if((motor3Val <= 15) && (motor3Val >= 15)){
			motor3Val = 0;
		}
		if((motor4Val <= 15) && (motor4Val >= 15)){
			motor4Val = 0;
		}

		if(joy1Btn(06) == 1){
			motor[motor1] = motor1Val;
			motor[motor2] = motor2Val;
			motor[motor3] = motor3Val;
			motor[motor4] = motor4Val;
		}
		else{
			motor[motor1] = motor1Val * scale;
			motor[motor2] = motor2Val * scale;
			motor[motor3] = motor3Val * scale;
			motor[motor4] = motor4Val * scale;
		}



	}
}
