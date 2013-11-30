//variable declaration

int DEADZONE = 15;


//end variable declaration

#include "joystickMapping.h"
//joystick mapping maps most joystick values to pretty variable names

//end joystick config

//robot functions
/*void hang() {
	if(joy1Btn(2) == 1){
		motor[motorHang] = 70;
		}else{
		motor[motorHang] = 0;
	}
}
											We will not use these two functions for the first league match.
void flag() {
	motor[motorA] = joy2X1();
	motor[motorB] = joy2X1();
}*/

void hang(){
	if(abs(joy2Y2()) > DEADZONE){
		motor[motorHang] = joy2Y2();


	}else{
		motor[motorHang] = 0;

	}

}

void lift() {
	if(abs(joy2Y1()) > DEADZONE) {
		motor[motorLift] = -joy2Y1();
		}else{
		motor[motorLift] = 0;
	}
}

void flipper(){
	//btn6 up btn8 down
	if(joyD_Up()){
		nMotorEncoderTarget[motorFlip] = 0; //	some value for up
		motor[motorFlip] = 100;
	}
	if(joyD_Down()){
		nMotorEncoderTarget[motorFlip] = -25;
		motor[motorFlip] = -100;
	}
}

void roller() { // put on joy 1
	while(joy1Btn(5)){
		motor[motorRoller] = 100;	
	}
	while(joy1Btn(7)){
		motor[motorRoller] = -100;	
	}
	motor[motorRoller] = 0;
}

void drive(){


	if(abs(joy1Y2()) > DEADZONE){
		motor[motorLeft] = joy1Y2();
		}else{
		motor[motorLeft] = 0;
	}

	if(abs(joy1Y1()) > DEADZONE){
		motor[motorRight] = -joy1Y1();
		}else{
		motor[motorRight] = 0;
	}
}

void initializeRobot()
{
	return;
}

//end robo functions
