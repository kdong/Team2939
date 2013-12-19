//variable declaration

#define DEADZONE 15

//end variable declaration


//joystick mapping maps most joystick values to pretty variable names
#include "joystickMapping.h"


// Retract servo to a safe position
void initializeRobot()
{
	servo[servoSensor] = 0;
	return;
}


// Robot system functions
void hang() {
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

void flipper() {
	while(joyD_Up()){
		servo[cServo] = 256; // 'up'
		servo[cServoII] = 0; // 'up'
	}
	while(joyD_Down()){
		servo[cServo] = 0; // 'down'
		servo[cServoII] = 256; // 'down'
	}
		servo[cServo] = 127; // 127 = stopped
		servo[cServoII] = 127;
}

void roller() {
	while(joy1Btn(7)){
		motor[motorRoller] = 100;
	}
	while(joy1Btn(5)){
		motor[motorRoller] = -100;
	}
	motor[motorRoller] = 0;
}

void l_drive() { // left side robot drive
	while(joy1Btn(6)){ // precision driving
		if(abs(joy1Y1()) > DEADZONE){
		motor[motorLeft] = joy1Y1()/2;
		}else{
		motor[motorLeft] = 0;
	}
}
		if(abs(joy1Y1()) > DEADZONE){
		motor[motorLeft] = joy1Y1();
		}else{
		motor[motorLeft] = 0;
}
}

void r_drive(){ // right side robot drive
	while(joy1Btn(6)){ // precision driving
		if(abs(joy1Y2()) > DEADZONE){
		motor[motorRight] = joy1Y2()/2;
		}else{
		motor[motorRight] = 0;
	}
}
		if(abs(joy1Y2()) > DEADZONE){
		motor[motorRight] = joy1Y2()/2;
		}else{
		motor[motorRight] = 0;
}
}
void autoScore(){
	if(joyD_Right()){
	motor[motorLift] = -100;
	wait1Msec(2150);	// up
	motor[motorLift] = 0;
	wait1Msec(3);

	servo[cServo] = 0;
	servo[cServoII] = 256; // down
	wait1Msec(550);

	servo[cServo] = 127;
	servo[cServoII] = 127; // stopped
	wait1Msec(3);

	servo[cServo] = 256;
	servo[cServoII] = 0; // up
	wait1Msec(550);

	motor[motorLift] = 100;
	wait1Msec(2150); // down
	motor[motorLift] = 0;
	wait1Msec(3);
}

	if(joyD_Left()){
	motor[motorLift] = -100;
	wait1Msec(1600);	// up
	motor[motorLift] = 0;
	wait1Msec(3);

	servo[cServo] = 0;
	servo[cServoII] = 256; // down
	wait1Msec(550);

	servo[cServo] = 127;
	servo[cServoII] = 127; // stopped
	wait1Msec(3);

	servo[cServo] = 256;
	servo[cServoII] = 0; // up
	wait1Msec(550);

	motor[motorLift] = 100;
	wait1Msec(1600); // down
	motor[motorLift] = 0;
	wait1Msec(3);
}
}

//end robot system functions


// multithreading (multitasking/allowing more than one thing to be processed at once)
// not using task priority unless there are notable lags in robot system
task tsk_r_drive(){
	while(true){
		r_drive();
	}
	EndTimeSlice();
}

task tsk_l_drive(){
	while(true){
		l_drive();
	}
	EndTimeSlice();
}

task tsk_roller(){
	while(true){
		roller();
	}
	EndTimeSlice();
}

task tsk_lift(){
	while(true){
		lift();
	}
	EndTimeSlice();
}

task tsk_hang(){
	while(true){
		hang();
	}
	EndTimeSlice();
}

task tsk_flip(){
	while(true){
		flipper();
	}
	EndTimeSlice();
}

task tsk_score(){
	while(true){
		autoScore();
	}
	EndTimeSlice();
}
