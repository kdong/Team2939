//variable declaration

int DEADZONE = 15;
int motorScale = 0.85;

//end variable declaration

#include joystickMapping.h
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



void lift() {
	if(abs(joy2Y2()) > DEADZONE) {
		motor[motorLift] = joy2Y2();
		}else{
		motor[motorLift] = 0;
	}
}

void flipper(){
	//btn6 up btn8 down
	if(joy2Btn(6)){
		nMotorEncoderTarget[motorFlip] = 270; //	some value for up
	}
	if(joy2Btn(8)){
		nMotorEncoderTarget[motorFlip] = 270;
	}
}

void roller() {
	if(abs(joy2Y1()) > DEADZONE){
		motor[motorRoller] = joy2Y1();
	}	else{
		motor[motorRoller] = 0;
	}
}

void drive(){


	if(abs(joy1Y2()) > DEADZONE){
		motor[motorRight] = Ajoy1Y2();
		}else{
		motor[motorRight] = 0;
	}

	if(abs(joy1Y1()) > DEADZONE){
		motor[motorLeft] = Ajoy1Y1();
		}else{
		motor[motorLeft] = 0;
	}
}

void initializeRobot()
{
	return;
}

//end robo functions



// drive & operator tasks
task driveCtrl(){
	drive();

}

task operatorCtrl(){
	roller();
	lift();
	hang();
	flag();
}
// end drive & operator tasks
