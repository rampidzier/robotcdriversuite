#pragma config(Sensor, S1,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * hitechnic-accelerometer.h provides an API for the HiTechnic Acceleration Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Make use of new API calls
 * - 0.3: Better comments
 * - 0.4: Fixed line number in display functionality
 * - 0.5: Now uses HTSMUX driver which has been split from common.h\n
 *        HTSMUX initialisation and scanning functions have been removed\n
 *        Removed single axis functions, they're no longer in the driver
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 * - Chris Shepherd for pointing a silly bug in the display functionality
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 20 February 2011
 * version 0.5
 */

#include "hitechnic-accelerometer.h"

task main () {
  displayCenteredTextLine(0, "HiTechnic");
  displayCenteredBigTextLine(1, "Accel");
  displayCenteredTextLine(3, "Test 1");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);

  playSound(soundBeepBeep);
  while(bSoundActive) sleep(1);

  // Create struct to hold sensor data
  tHTAC accelerometer;

	// The sensor is connected to the first port
	// of the SMUX which is connected to the NXT port S1.
	// To access that sensor, we must use msensor_S1_1.  If the sensor
	// were connected to 3rd port of the SMUX connected to the NXT port S4,
	// we would use msensor_S4_3

  // Initialise and configure struct and port
  initSensor(&accelerometer, msensor_S1_1);

  while (true) {
    eraseDisplay();

    // Read all of the axes at once
    if (!readSensor(&accelerometer)) {
      displayTextLine(4, "ERROR!!");
      sleep(2000);
      stopAllTasks();
    }

    displayTextLine(0,"HTAC Test 1");
    displayTextLine(2, "   X    Y    Z");

    displayTextLine(3, "%4d %4d %4d", accelerometer.x, accelerometer.y, accelerometer.z);
		// Alternatively, you can read them like this:
    displayTextLine(4, "%4d %4d %4d", accelerometer.axes[0], accelerometer.axes[1], accelerometer.axes[2]);
    sleep(100);
  }
}
