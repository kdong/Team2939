//defining e_forward variables
int r_forwardEncVal;
int l_forwardEncVal;
int r_backwardEncVal;
int l_backwardEncVal;
int r_encValToEnd;
int l_encValToEnd;
int back_r_encValToEnd;
int back_l_encValToEnd;
//end e_forward variables

//constants
#define _45DEGREES 550
#define _90DEGREES 1075
#define _65DEGREES 750
#define _135DEGREES 1275
#define _180DEGREES 2000
#define _360DEGREES 4000

 void resetEnc(){
 	nMotorEncoder[motorRight] = 0;
 	nMotorEncoder[motorLeft] = 0;
 }

void stopDrive(){ //just to stop drive motors
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
	wait1Msec(5);
}

void delayStop(int additionalTime){ //usage in IRAuto and IRAuto_Back, for precision in turns
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
	wait1Msec(additionalTime);
}

void initIR(){
	servo[servoSensor] = 128;
	wait1Msec(1);
}

void initializeRobot(){
	resetEnc();
	initIR();
	return;
}

void gotoIR_FORWARD(){
	while(SensorValue[sensorIR] < 5){
		motor[motorRight] = 75;
		motor[motorLeft] = 75;
	}
	if(SensorValue[sensorIR] == 5){
		stopDrive();
		wait1Msec(150);
		r_forwardEncVal = nMotorEncoder[motorRight];
		l_forwardEncVal = nMotorEncoder[motorLeft];
	}
}

void gotoIR_BACKWARD(){
		while(SensorValue[sensorIR] > 5){
		motor[motorRight] = -100;
		motor[motorLeft] = -100;
	}
	if(SensorValue[sensorIR] == 5){
		stopDrive();
		wait1Msec(150);
		}
}

void storeEncoderValues(){
		r_forwardEncVal = nMotorEncoder[motorRight];
		l_forwardEncVal = nMotorEncoder[motorLeft];
		r_backwardEncVal = nMotorEncoder[motorRight];
		l_backwardEncVal = nMotorEncoder[motorLeft];
}


int determineForwardPos_r(){
	r_encValToEnd = 5175 - r_forwardEncVal;
	return r_encValToEnd;
}

int determineForwardPos_l(){
	l_encValToEnd = 5175 - l_forwardEncVal;
	return l_encValToEnd;
}

int determineBackwardPos_r(){
	back_r_encValToEnd = -6850 + r_backwardEncVal;
	return back_r_encValToEnd;
}

int determineBackwardPos_l(){
	back_l_encValToEnd = -8050 + l_backwardEncVal;
	return back_l_encValToEnd;
}

void moveForward(int rInches){
	int convInches = rInches * 150;
	resetEnc();
	while((nMotorEncoder[motorRight] < convInches) && (nMotorEncoder[motorLeft] < convInches)){
	nMotorEncoderTarget[motorRight] = convInches;
	nMotorEncoderTarget[motorLeft] = convInches;

	motor[motorRight] = 85;
	motor[motorLeft] = 85;
}
		stopDrive();
}

void moveBackward(int rInches){
	int convInches = rInches * 150;
	resetEnc();
	while((nMotorEncoder[motorRight] > -convInches) && (nMotorEncoder[motorLeft] > -convInches)){
	nMotorEncoderTarget[motorRight] = -convInches;
	nMotorEncoderTarget[motorLeft] = -convInches;

	motor[motorRight] = -50;
	motor[motorLeft] = -50;
}
		stopDrive();
}

void gotoEnd_for(){

	resetEnc();
	while((nMotorEncoder[motorRight] < determineForwardPos_r()) && (nMotorEncoder[motorLeft] < determineForwardPos_l())){
	nMotorEncoderTarget[motorRight] = determineForwardPos_r();
	nMotorEncoderTarget[motorLeft] = determineForwardPos_l();

	motor[motorRight] = 60;
	motor[motorLeft] = 60;
}
		stopDrive();
}

void gotoEnd_back(){

	resetEnc();
	while((nMotorEncoder[motorRight] > -determineBackwardPos_r()) && (nMotorEncoder[motorLeft] > -determineBackwardPos_l())){
	nMotorEncoderTarget[motorRight] = -determineBackwardPos_r();
	nMotorEncoderTarget[motorLeft] = -determineBackwardPos_l();

	motor[motorRight] = -100;
	motor[motorLeft] = -100;
}
		stopDrive();
}



void scoreAuto(){
	motor[motorLift] = -100;
	wait1Msec(1850);	// up
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
	wait1Msec(1850); // down
	motor[motorLift] = 0;
	wait1Msec(3);
}


void turnRight(int degrees){
	resetEnc();
	while((nMotorEncoder[motorRight] > -degrees) && (nMotorEncoder[motorLeft] < degrees)){
	nMotorEncoderTarget[motorRight] = -degrees;
	nMotorEncoderTarget[motorLeft] = degrees;

	motor[motorRight] = -100;
	motor[motorLeft] = 100;
}
		stopDrive();
}

void turnLeft(int degrees){
	resetEnc();
	while((nMotorEncoder[motorRight] < degrees) && (nMotorEncoder[motorLeft] > -degrees)){
	nMotorEncoderTarget[motorRight] = degrees;
	nMotorEncoderTarget[motorLeft] = -degrees;

	motor[motorRight] = 100;
	motor[motorLeft] = -100;
}
		stopDrive();
}
