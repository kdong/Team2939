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
#define _45DEGREES 500
#define _90DEGREES 1000
#define _180DEGREES 2000
#define _360DEGREES 4000

 void resetEnc(){
 	nMotorEncoder[motorRight] = 0;
 	nMotorEncoder[motorLeft] = 0;
 }

void eStop(){
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
	wait1Msec(5);
}

void delayStop(int additionalTime){
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
	wait1Msec(additionalTime);
}

void initializeRobot(){
	resetEnc();
	return;
}

void initIR(){
	servo[servoSensor] = 128;
	wait1Msec(1);
}

void gotoIR_FORWARD(){
	while(SensorValue[sensorIR] < 5){
		motor[motorRight] = 100;
		motor[motorLeft] = 100;
	}
	if(SensorValue[sensorIR] == 5){
		eStop();
		wait1Msec(150);
		r_forwardEncVal = nMotorEncoder[motorRight];
		l_forwardEncVal = nMotorEncoder[motorLeft];
	}
	//end

}

void gotoIR_BACKWARD(){
		while(SensorValue[sensorIR] > 5){
		motor[motorRight] = -100;
		motor[motorLeft] = -100;
	}
	if(SensorValue[sensorIR] == 5){
		eStop();
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
	r_encValToEnd = 4550 - r_forwardEncVal;
	return r_encValToEnd;
}

int determineForwardPos_l(){
	l_encValToEnd = 4550 - l_forwardEncVal;
	return l_encValToEnd;
}

int determineBackwardPos_r(){
	back_r_encValToEnd = 4550 + r_backwardEncVal;
	return back_r_encValToEnd;
}

int determineBackwardPos_l(){
	back_l_encValToEnd = 4550 + l_backwardEncVal;
	return back_l_encValToEnd;
}

void turnRight(){

	resetEnc();
	while((nMotorEncoder[motorRight] > -encTurnVal) && (nMotorEncoder[motorLeft] < encTurnVal)){
	nMotorEncoderTarget[motorRight] = -encTurnVal;
	nMotorEncoderTarget[motorLeft] = encTurnVal;

	motor[motorRight] = -100;
	motor[motorLeft] = 100;
}
		eStop();
}

void turn_fortyfive_right(){

	resetEnc();
	while((nMotorEncoder[motorRight] < encTurnVal_FoFi) && (nMotorEncoder[motorLeft] > -encTurnVal_FoFi)){
	nMotorEncoderTarget[motorRight] = encTurnVal_FoFi;
	nMotorEncoderTarget[motorLeft] = -encTurnVal_FoFi;

	motor[motorRight] = 100;
	motor[motorLeft] = -100;
}
		eStop();
}

void turnLeft(){
	resetEnc();
	while((nMotorEncoder[motorRight] < encTurnVal) && (nMotorEncoder[motorLeft] > -encTurnVal)){
	nMotorEncoderTarget[motorRight] = encTurnVal;
	nMotorEncoderTarget[motorLeft] = -encTurnVal;

	motor[motorRight] = 100;
	motor[motorLeft] = -100;
}
		eStop();
}

void turn_fortyfive_left(){

	resetEnc();
	while((nMotorEncoder[motorRight] > -encTurnVal_FoFi) && (nMotorEncoder[motorLeft] < encTurnVal_FoFi)){
	nMotorEncoderTarget[motorRight] = -encTurnVal_FoFi;
	nMotorEncoderTarget[motorLeft] = encTurnVal_FoFi;

	motor[motorRight] = -100;
	motor[motorLeft] = 100;
}
		eStop();
}
void moveForward(int rInches){
	int convInches = rInches * 150;
	resetEnc();
	while((nMotorEncoder[motorRight] < convInches) && (nMotorEncoder[motorLeft] < convInches)){
	nMotorEncoderTarget[motorRight] = convInches;
	nMotorEncoderTarget[motorLeft] = convInches;

	motor[motorRight] = 100;
	motor[motorLeft] = 100;
}
		eStop();
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
		eStop();
}

void e_moveForward(){

	resetEnc();
	while((nMotorEncoder[motorRight] < r_encValToEnd) && (nMotorEncoder[motorLeft] < l_encValToEnd)){
	nMotorEncoderTarget[motorRight] = r_encValToEnd;
	nMotorEncoderTarget[motorLeft] = l_encValToEnd;

	motor[motorRight] = 100;
	motor[motorLeft] = 100;
}
		eStop();
}

void e_moveBackward(int rInches){
	int convInches = rInches * 150;
	resetEnc();
	while((nMotorEncoder[motorRight] > -convInches) && (nMotorEncoder[motorLeft] > -convInches)){
	nMotorEncoderTarget[motorRight] = -convInches;
	nMotorEncoderTarget[motorLeft] = -convInches;

	motor[motorRight] = -50;
	motor[motorLeft] = -50;
}
		eStop();
}



void scoreAuto(){
	motor[motorLift] = -100;
	wait1Msec(2350);	// up
	motor[motorLift] = 0;
	wait1Msec(3);

	servo[cServo] = 0;
	servo[cServoII] = 256; // down
	wait1Msec(750);

	servo[cServo] = 127;
	servo[cServoII] = 127; // stopped
	wait1Msec(32);

	servo[cServo] = 256;
	servo[cServoII] = 0; // up
	wait1Msec(1050);

	motor[motorLift] = 100;
	wait1Msec(2350); // down
	motor[motorLift] = 0;
	wait1Msec(3);
}


turnRight(int degrees){
	resetEnc();
	while((nMotorEncoder[motorRight] > -degrees) && (nMotorEncoder[motorLeft] < degrees)){
	nMotorEncoderTarget[motorRight] = -degrees;
	nMotorEncoderTarget[motorLeft] = degrees;

	motor[motorRight] = -100;
	motor[motorLeft] = 100;
}
		eStop();
}

void turnRight(){

	resetEnc();
	while((nMotorEncoder[motorRight] > -encTurnVal) && (nMotorEncoder[motorLeft] < encTurnVal)){
	nMotorEncoderTarget[motorRight] = -encTurnVal;
	nMotorEncoderTarget[motorLeft] = encTurnVal;

	motor[motorRight] = -100;
	motor[motorLeft] = 100;
}
		eStop();
}


