// Create better readibility for joystick values
int motorScale = 0.85;

int joy1X1(){return joystick.joy1_x1;}

int joy1X2(){return joystick.joy1_x2;}

int joy1Y1(){return joystick.joy1_y1;}
int Ajoy1Y1(){
	return (motorScale * (pow(joy1Y1()),3) + (1 - motorScale) * (joy1Y1()));
}
}

int joy1Y2(){return joystick.joy1_y2;}
int Ajoy1Y2(){ //adjusted joy1Y2
	return (motorScale * (pow(joy1Y2()),3) + (1 - motorScale) * (joy1Y2()));
}

int joy2X1(){return joystick.joy2_x1;}

int joy2X2(){return joystick.joy2_x2;}

int joy2Y1(){return joystick.joy2_y1;}

int joy2Y2(){return joystick.joy2_y2;}

int joyD_Right(){return (joystick.joy2_TopHat == 2;)}

int joyD_Left(){return (joystick.joy2_TopHat == 6;)}

int joyD_Up(){return (joystick.joy2_TopHat == 0;)}

int joyD_Down(){return (joystick.joy2_TopHat == 4;)}

//-------------------------------------------------------//
int joyD_UpRight(){return joystick.joy2_TopHat == 1;}

int joyD_DownRight(){return joystick.joy2_TopHat == 3;}

int joyD_DownLeft(){return joystick.joy2_TopHat == 5;}

int joyD_UpLeft(){return joystick.joy2_TopHat == 7;}
//------------------------------------------------------//
