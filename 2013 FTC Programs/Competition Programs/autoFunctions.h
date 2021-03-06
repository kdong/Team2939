//defining e_forward variables
int r_forwardEncVal;
int l_forwardEncVal;
int r_backwardEncVal;
int l_backwardEncVal;
int r_encValToEnd;
int l_encValToEnd;
int back_r_encValToEnd;
int back_l_encValToEnd;
bool firstTest;
bool secondTest;
//end e_forward variables

//constants
#define _45DEGREES 538
#define _90DEGREES 1075
#define _65DEGREES 750
#define _135DEGREES 1275
#define _180DEGREES 2150
#define _360DEGREES 4300
#define mEncLength 5350

	void retractServo(){
	servo[servoSensor] = 15; //256
	wait1Msec(500);
	}

	void irSensorPos(){
		servo[servoSensor] = 175;
	}

 void determineFirst(){
 	if(SensorValue[sensorIR] == 0){
		firstTest = true;
 	}else{
 	secondTest = true;
}
 }

 void determineSecond(){
   if(SensorValue[sensorIR] == 0){
   	secondTest = false;
   }else{
   	secondTest = true;
   }
 }

 void resetEnc(){
 	nMotorEncoder[motorRight] = 0;
 	nMotorEncoder[motorLeft] = 0;
 }

 void rotateServo(){
 	servo[servoSensor] = 17;
 	determineSecond();
 	//servo[servoSensor] = 35;
 	//determineSecond();
 	//servo[servoSensor] = 0;
 	//determineSecond();
 }

 void rotateServo_B(){
 	servo[servoSensor] = 162;
 	determineSecond();
 }

 void stopDrive(){ //just to stop drive motors
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
	wait1Msec(5);
}
void moveForward(int rInches){
	int convInches = rInches * 150;
	resetEnc();
	while((nMotorEncoder[motorRight] < convInches) && (nMotorEncoder[motorLeft] < convInches)){
	nMotorEncoderTarget[motorRight] = convInches;
	nMotorEncoderTarget[motorLeft] = convInches;

	motor[motorRight] = 69;
	motor[motorLeft] = 69;
}
		stopDrive();
}

void moveBackward(int rInches){
	int convInches = rInches * 150;
	resetEnc();
	while((nMotorEncoder[motorRight] > -convInches) && (nMotorEncoder[motorLeft] > -convInches)){
	nMotorEncoderTarget[motorRight] = -convInches;
	nMotorEncoderTarget[motorLeft] = -convInches;

	motor[motorRight] = -60;
	motor[motorLeft] = -60;
}
		stopDrive();
}

void moveBackwardSec(int seconds){
		motor[motorRight] = -80;
		motor[motorLeft] = -80;
		wait1Msec(1000 * seconds);
		stopDrive();
}

void delayStop(int additionalTime){ //usage in IRAuto and IRAuto_Back, for precision in turns
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
	wait1Msec(additionalTime);
}

void initIR(){
	//servo[servoSensor] = 128;
	servo[servoSensor] = 155;
	wait1Msec(10);
}

void initializeRobotAUTO(){
	resetEnc();
	initIR();
	return;
}

void gotoIR_FORWARD(){
	while(SensorValue[sensorIR] < 5){
		motor[motorRight] = 45;
		motor[motorLeft] = 45;
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
		r_backwardEncVal = nMotorEncoder[motorRight];
		l_backwardEncVal = nMotorEncoder[motorLeft];
		}
}

void storeEncoderValues(){
		r_forwardEncVal = nMotorEncoder[motorRight];
		l_forwardEncVal = nMotorEncoder[motorLeft];
		r_backwardEncVal = nMotorEncoder[motorRight];
		l_backwardEncVal = nMotorEncoder[motorLeft];
}

void moveForwardif(int rInches){
	if((r_forwardEncVal < 3750) && (l_forwardEncVal < 3750))
{
	int convInches = rInches * 150;
	resetEnc();
	while((nMotorEncoder[motorRight] < convInches) && (nMotorEncoder[motorLeft] < convInches)){
	nMotorEncoderTarget[motorRight] = convInches;
	nMotorEncoderTarget[motorLeft] = convInches;

	motor[motorRight] = 55;
	motor[motorLeft] = 55;
}
		stopDrive();

}else{
	stopDrive();
}
}

void moveBackwardif(int rInches){
	if((r_backwardEncVal > -4000) && (l_backwardEncVal > -4000))
{
	int convInches = rInches * 150;
	resetEnc();
	while((nMotorEncoder[motorRight] > -convInches) && (nMotorEncoder[motorLeft] > -convInches)){
	nMotorEncoderTarget[motorRight] = -convInches;
	nMotorEncoderTarget[motorLeft] = -convInches;

	motor[motorRight] = -100;
	motor[motorLeft] = -100;
}
		stopDrive();
}else{
	stopDrive();
}
}

int determineForwardPos_r(){
	r_encValToEnd = mEncLength - r_forwardEncVal;
	return r_encValToEnd;
}

int determineForwardPos_l(){
	l_encValToEnd = mEncLength - l_forwardEncVal;
	return l_encValToEnd;
}

int determineBackwardPos_r(){
	back_r_encValToEnd = -mEncLength + r_backwardEncVal;
	return back_r_encValToEnd;
}

int determineBackwardPos_l(){
	back_l_encValToEnd = -mEncLength + l_backwardEncVal;
	return back_l_encValToEnd;
}


void gotoEnd_for(){

	resetEnc();
	while((nMotorEncoder[motorRight] < determineForwardPos_r()) && (nMotorEncoder[motorLeft] < determineForwardPos_l())){
	nMotorEncoderTarget[motorRight] = determineForwardPos_r();
	nMotorEncoderTarget[motorLeft] = determineForwardPos_l();

	motor[motorRight] = 55;
	motor[motorLeft] = 55;
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
	wait1Msec(1900);	// up
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
	wait1Msec(1900); // down
	motor[motorLift] = 0;
	wait1Msec(3);
}


void turnRight(int degrees){
	resetEnc();
	while((nMotorEncoder[motorRight] > -degrees) && (nMotorEncoder[motorLeft] < degrees)){
	nMotorEncoderTarget[motorRight] = -degrees;
	nMotorEncoderTarget[motorLeft] = degrees;

	motor[motorRight] = -65;
	motor[motorLeft] = 65;
}
		stopDrive();
}

void turnLeft(int degrees){
	resetEnc();
	while((nMotorEncoder[motorRight] < degrees) && (nMotorEncoder[motorLeft] > -degrees)){
	nMotorEncoderTarget[motorRight] = degrees;
	nMotorEncoderTarget[motorLeft] = -degrees;

	motor[motorRight] = 65;
	motor[motorLeft] = -65;
}
		stopDrive();
}

void pivotLeft(int degrees){
	resetEnc();
	while((nMotorEncoder[motorRight] == 0) && (nMotorEncoder[motorLeft] > -degrees)){
	nMotorEncoderTarget[motorRight] = 0;
	nMotorEncoderTarget[motorLeft] = -degrees;

	motor[motorRight] = 90;
	motor[motorLeft] = -90;
}
		stopDrive();
}

void pivotRight(int degrees){
	resetEnc();
	while((nMotorEncoder[motorRight] > -degrees) && (nMotorEncoder[motorLeft] == 0)){
	nMotorEncoderTarget[motorRight] = -degrees;
	nMotorEncoderTarget[motorLeft] = 0;

	motor[motorRight] = -90;
	motor[motorLeft] = 90;
}
		stopDrive();
}


void timedMove(int seconds, int power, int direction){
	motor[motorRight] = power * direction;
	motor[motorLeft] = power * direction;
	wait1Msec(seconds * 1000);
}

void armsDown(){
	motor[motorHang] = -60;
}
