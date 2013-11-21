#define one_inch 1440
#define one_foot 17280


void initializeRobot(){
	nMotorEncoder[motorRight] = 0;
	nMotorEncoder[motorLeft] = 0;
	nMotorEncoder[motorLift] = 0;
	return;
}

void turnDegreesRight(int power, int degrees){
	// motor left go

}

void turnDegreesLeft(int power, int degrees){


}

void pivotTurnRight(int power, int degrees){


}

void pivotTurnLeft(int power, int degrees){


}

void arcTurnRight(int power, int degrees){


}

void arcTurnLeft(int power, int degrees){


}

void irPinPoint(){


}

void detectIR(){

	if(SensorValue[sensorIR] ){

		placement = IR1;
	}
	if(SensorValue[sensorIR] ){

		placement = IR2;
	}
	if(SensorValue[sensorIR] ){

		placement = IR3;
	}
	if(SensorValue[sensorIR] ){

		placement = IR4;
	}


	return placement;
}

// typedef enum = IR1, IR2, IR3, IR4;

void moveToIR(char placement){

	switch(placement){

		case IR1:
		moveForward(3);
		break;

		case IR2:
		//move 13 inches
		moveForward(13);
		break;

		case IR3:
		//move 36 inches from base
		moveForward(36);
		break;

		case IR4:
		//move 46 inches from base
		moveForward(46);
		break;

		default:
		//function detectIR did not work. do nothing.
		break;
	}
}

void moveForward(int inches, int power){

	nMotorEncoderTarget[motorRight] = inches;
	nMotorEncoderTarget[motorLeft] = inches;

	motor[motorRight] = power;
	motor[motorLeft] = power;
}

int distanceToBeacon(){



	return inches;
}

void stop(){
	motor[motorRight] = 0;
	motor[motorLeft] = 0;
}

task detectIRBeacon(){
	if(SensorValue[sensorIR] < 5){



	}
	if(SensorValue[sensorIR] > 5){



	}
	if(SensorValue[sensorIR] == 5){



	}


}
