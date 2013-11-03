#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     ,              tmotorNone, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     ,              tmotorNone, openLoop)


#include "JoystickDriver.c"
#include "AutoFunctions.h" //our header file with all of our functions for autonomous

int circWheel = 3 * PI; // 9.42
// 9.42 = 1440 motor encoder ticks
// 1440 = 9.42 inches
// 1440 / 9.42 = inches

int inch = 1440 / circWheel;
int feet = inch * 12;


void initializeRobot()
{


  return;
}



task main()
{
  initializeRobot();

  waitForStart();

  while (true)
  {}
}
