#define encoder_inch 150
#define encoder_foot 1800


void initializeRobot(){
	nMotorEncoder[motorRight] = 0;
	nMotorEncoder[motorLeft] = 0;
	return;
}

void initIR(){
	servo[servoSensor] = 128;
	wait1Msec(1);
}

void detectIR(){
	while(SensorValue[sensorIR] != 5){
		
	}	
}

void turnDegreesRight(int power, int degrees){
	// motor left go

}

void turnDegreesLeft(int power, int degrees){


}

void arcTurnRight(int power, int degrees){


}

void arcTurnLeft(int power, int degrees){


}

void irPinPoint(){


}


void moveToIR(char placement){



}

void moveForward(int inches, int power){

	converted_inches = encoder_inch * inches;

	nMotorEncoderTarget[motorRight] = converted_inches;
	nMotorEncoderTarget[motorLeft] = converted_inches;

	motor[motorRight] = power;
	motor[motorLeft] = power;
}

void moveBackward(int inches, int power){

	converted_inches = encoder_inch * inches;
	while(nMotorEncoder[motorRight] && nMotorEncoder[motorLeft] = converted_inches){
		motor[motorRight] = -power;
		motor[motorLeft] = -power;

	}
	nMotorEncoderTarget[motorRight] = -converted_inches;
	nMotorEncoderTarget[motorLeft] = -converted_inches;

}

void eStop(){

	motor[motorRight] = 0;
	motor[motorLeft] = 0;
	wait10Msec(5);
}

void scoreAuto(){

}

void gotoLastCrate(){

}

void raiseHang(){

}
