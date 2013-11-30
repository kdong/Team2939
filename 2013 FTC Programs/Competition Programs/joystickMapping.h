//Joystick mapping
int scaledJoy1Y1;
int scaledJoy1Y2;
int scaledJoy2Y1;
int scaledJoy2Y2;

const int LogScale[17] =
	{
		0, 5, 9, 10,
		12, 15, 18, 24,
		30, 36, 43, 50,
		60, 72, 85, 100,
		100
	};

bool LogScaleEnabled = true;
//joystick configuration for variables

// joysticks
int joy1X1(){

	int scaledJoy1X1 = joystick.joy1_x1;
	return scaledJoy1X1;
}

int joy1X2(){
	int scaledJoy1X2 = joystick.joy1_x2;
	return scaledJoy1X2;
}

int joy1Y1(){
	if(LogScaleEnabled == true){
	scaledJoy1Y1 = joystick.joy1_y1 / 8;
	if(scaledJoy1Y1 >= 0){
		scaledJoy1Y1 = LogScale[scaledJoy1Y1];
	}else{
		scaledJoy1Y1 = -LogScale[-scaledJoy1Y1];
	}
	}
	return scaledJoy1Y1;
}

int joy1Y2(){

	if(LogScaleEnabled == true){
	scaledJoy1Y2 = joystick.joy1_y2 / 8;
	if(scaledJoy1Y2 >= 0){
		scaledJoy1Y2 = LogScale[scaledJoy1Y2];
	}else{
		scaledJoy1Y2 = -LogScale[-scaledJoy1Y2];
	}
	}
	return scaledJoy1Y2;
}

int joy2X1(){

	return joystick.joy2_x1/1.27;
}

int joy2X2(){

	return joystick.joy2_x2/1.27;
}

int joy2Y1(){
	if(LogScaleEnabled == true){
	scaledJoy2Y1 = joystick.joy2_y1 / 8;
	if(scaledJoy1Y2 >= 0){
		scaledJoy2Y1 = LogScale[scaledJoy2Y1];
	}else{
		scaledJoy2Y1 = -LogScale[-scaledJoy2Y1];
	}
	}
	return scaledJoy1Y2;
}

int joy2Y2(){
	if(LogScaleEnabled == true){
		 scaledJoy2Y2 = joystick.joy2_y2 / 8;
	if(scaledJoy2Y2 >= 0){
		scaledJoy1Y2 = LogScale[scaledJoy2Y2];
	}else{
		scaledJoy2Y2 = -LogScale[-scaledJoy2Y2];
	}
	}

	return scaledJoy2Y2;

}


// tophat/d-pad functions
int joyD_Right(){
	return (joystick.joy2_TopHat == 2);
}

int joyD_Left(){
	return (joystick.joy2_TopHat == 6);
}

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
