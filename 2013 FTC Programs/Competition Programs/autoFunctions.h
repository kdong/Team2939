int conversionDegreeFactor = (1680/90); // encoder value found doing a '90' degree turn


 void resetEnc(){
 	nMotorEncoder[motorRight] = 0;
 	nMotorEncoder[motorLeft] = 0;
 }

void eStop(){

	motor[motorRight] = 0;
	motor[motorLeft] = 0;
	wait1Msec(5);
}

void initializeRobot(){
	nMotorEncoder[motorRight] = 0;
	nMotorEncoder[motorLeft] = 0;
	return;
}

void initIR(){
	servo[servoSensor] = 128;
	wait1Msec(1);
}

void gotoIR(){
	do {
		motor[motorLeft] = 100;
		motor[motorRight] = 100;
	} while (SensorValue[sensorIR] != 5);

	if(SensorValue[sensorIR] == 5){
		eStop();
	}
}

void determinePos(){
//	int beaconPos;

}

void turnDegreesRight(int mPower, int rDegrees){
	int conDegrees = rDegrees * conversionDegreeFactor;
	resetEnc();

	nMotorEncoderTarget[motorRight] = -conDegrees;
	nMotorEncoderTarget[motorLeft] = conDegrees;

	motor[motorRight] = -mPower;
	motor[motorLeft] = mPower;

		while(nMotorRunState[motorRight] != runStateIdle && nMotorRunState[motorLeft] != runStateIdle){
		// do nothing
	}
		eStop();
}

void turnDegreesLeft(int mPower, int rDegrees){
	int conDegrees = rDegrees * conversionDegreeFactor;
	resetEnc();

	nMotorEncoderTarget[motorRight] = conDegrees;
	nMotorEncoderTarget[motorLeft] = -conDegrees;

	motor[motorRight] = mPower;
	motor[motorLeft] = -mPower;

		while(nMotorRunState[motorRight] != runStateIdle && nMotorRunState[motorLeft] != runStateIdle){
		// do nothing
	}
		eStop();
}


void moveForward(int rInches, int mPower){
	int conInches = rInches * 150; // gets motor encoder ticks from rInches
	resetEnc();
	nMotorEncoderTarget[motorRight] = conInches;
	nMotorEncoderTarget[motorLeft] = conInches;

	motor[motorRight] = mPower;
	motor[motorLeft] = mPower;

	while(nMotorRunState[motorRight] != runStateIdle && nMotorRunState[motorLeft] != runStateIdle){
		// do nothing
	}
		eStop();
}

void moveBackward(int rInches, int mPower){
	int conInches = -rInches * 150; // gets motor encoder ticks from rInches
	resetEnc();
	nMotorEncoderTarget[motorRight] = conInches;
	nMotorEncoderTarget[motorLeft] = conInches;

	motor[motorRight] = -mPower;
	motor[motorLeft] = -mPower;

while(nMotorRunState[motorRight] != runStateIdle && nMotorRunState[motorLeft] != runStateIdle ){
		//do nothing
}
	eStop();
}



void scoreAuto(){
	motor[motorLift] = 100;
	wait1Msec(1300);

	servo[cServo] = 0;
	servo[cServoII] = 256;
	wait1Msec(850);

	servo[cServo] = 256;
	servo[cServoII] = 0;
	wait1Msec(850);
}

void gotoLastCrate(){

}

void raiseHang(){

}
