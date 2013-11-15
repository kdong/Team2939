//variable declaration

int DEADZONE = 15;
int motorScale = 0.85;

//end variable declaration

//joystick configuration for variables

// joysticks
int joy1X1(){
	return joystick.joy1_x1;
}

int joy1X2(){
	return joystick.joy1_x2;
}

int joy1Y1(){
	return joystick.joy1_y1;
}
int Ajoy1Y1(){
	return (motorScale * pow(joy1Y1(), 3) + (1 - motorScale) * (joy1Y1()));
}


int joy1Y2(){
	return joystick.joy1_y2;
}
int Ajoy1Y2(){
	return (motorScale * pow(joy1Y2(), 3) + (1 - motorScale) * (joy1Y2()));
}

int joy2X1(){
	return joystick.joy2_x1;
}

int joy2X2(){
	return joystick.joy2_x2;
}

int joy2Y1(){
	return joystick.joy2_y1;
}

int joy2Y2(){
	return joystick.joy2_y2;
}


// tophat/d-pad functions
int joyD_Right(){
	return (joystick.joy2_TopHat == 2);
}

int joyD_Left(){
	return (joystick.joy2_TopHat == 6);}

int joyD_Up(){
	return (joystick.joy2_TopHat == 0);
}

int joyD_Down(){
	return (joystick.joy2_TopHat == 4);
}


int joyD_UpRight(){
	return joystick.joy2_TopHat == 1;
}

int joyD_DownRight(){
	return joystick.joy2_TopHat == 3;
}

int joyD_DownLeft(){
	return joystick.joy2_TopHat == 5;
}

int joyD_UpLeft(){
	return joystick.joy2_TopHat == 7;
}
//end joystick config

//robot functions
void hang() {
	if(joy1Btn(2) == 1){
		motor[motorHang] = 70;
		}else{
		motor[motorHang] = 0;
	}
}

void flag() {
	motor[motorA] = joy2X1();
	motor[motorB] = joy2X1();
}

void lift() {
	if(abs(joy2Y2()) > DEADZONE) {
		motor[motorLift] = joy2Y2();
		}	else{
		motor[motorLift] = 0;
	}
}

void roller() {
	// joystick buttons 5 & 7, might need to test.
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
