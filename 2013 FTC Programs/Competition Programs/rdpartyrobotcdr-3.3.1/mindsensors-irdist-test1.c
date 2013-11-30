#pragma config(Sensor, S1,     MSDIST,              sensorI2CCustomFastSkipStates9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-irdist-test1.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * MSAC-driver.h provides an API for the Mindsensors Acceleration Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 * - 0.3: Fixed stupid typo
 * - 0.4: Removed sensor configuration call, now done automatically.
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER. 

 * Xander Soldaat (xander_at_botbench.com)
 * 06 July 2010
 * version 0.4
 */

#include "drivers/mindsensors-irdist.h"

task main () {
  int distance = 0;
  int voltage = 0;
  int mindist = 0;
  int maxdist = 0;
  string type;

  nxtDisplayCenteredTextLine(0, "Mindsensors");
  nxtDisplayCenteredBigTextLine(1, "DIST-nx");
  nxtDisplayCenteredTextLine(3, "Test 1");

  wait1Msec(2000);

  PlaySound(soundBeepBeep);
  while(bSoundActive) EndTimeSlice();
  eraseDisplay();

  // Read the minimum distance the sensor can "see"
  mindist = MSDISTreadMinDist(MSDIST);

  // Read the maximum distance the sensor can "see"
  maxdist = MSDISTreadMaxDist(MSDIST);

  // Get the type of Sharp IR module connected to the sensor
  switch(MSDISTreadModuleType(MSDIST)) {
    case MSDIST_GP2D12:  type = " GP2D12"; break;
    case MSDIST_GP2D120: type = "GP2D120"; break;
    case MSDIST_GP2YA02: type = "GP2YA02"; break;
    case MSDIST_GP2YA21: type = "GP2YA21"; break;
    case MSDIST_CUSTOM:  type = " CUSTOM"; break;
  }

  nxtDisplayTextLine(5, "Type: %s", type);
  nxtDisplayTextLine(6, "Min:   %4dmm", mindist);
	nxtDisplayTextLine(7, "Max:   %4dmm", maxdist);

  while (true) {
    // Get the distance calculated based on the data from the IR Sharp module
    distance = MSDISTreadDist(MSDIST);

    // Get the raw voltage data from the Sharp IR module
    voltage = MSDISTreadVoltage(MSDIST);
    if (distance < 0) {
      nxtDisplayTextLine(4, "ERROR!!");
      wait1Msec(2000);
      StopAllTasks();
    }

    nxtDisplayCenteredBigTextLine(0, "%4dmm", distance);
    nxtDisplayCenteredBigTextLine(3, "%4dmV", voltage);
    wait1Msec(50);
  }
}

/*
 * $Id: mindsensors-irdist-test1.c 133 2013-03-10 15:15:38Z xander $
 */