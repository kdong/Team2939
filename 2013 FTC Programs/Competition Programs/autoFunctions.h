


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



void moveToIR(char placement){

	

}

void moveForward(int inches, int power){

	nMotorEncoderTarget[motorRight] = inches;
	nMotorEncoderTarget[motorLeft] = inches;

	motor[motorRight] = power;
	motor[motorLeft] = power;
}


}
