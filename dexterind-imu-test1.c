#pragma config(Sensor, S1,     DIMU,                sensorI2CCustomFastSkipStates)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: dexterind-imu-test1.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * dexterind-imu.h provides an API for the Dexter Industries IMU Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Dexter Industries for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER. 

 * Xander Soldaat (xander_at_botbench.com)
 * 07 August 2011
 * version 0.1
 */

#include "dexterind-imu.h"

task main(){

  float x_val, y_val, z_val;      // Gyro axis values

  nxtDisplayCenteredTextLine(0, "Dexter Ind.");
  nxtDisplayCenteredBigTextLine(1, "IMU");
  nxtDisplayCenteredTextLine(3, "Test 1");
  nxtDisplayCenteredTextLine(5, "Connect sensor");
  nxtDisplayCenteredTextLine(6, "to S1");
  wait1Msec(2000);
  eraseDisplay();

  // Fire up the gyro and initialize it. Only needs to be done once.
  //DIMUconfigGyro(DIMU, DIMU_GYRO_RANGE_500);
  if (!DIMUconfigAccel(DIMU, DIMU_ACC_RANGE_2G))
    PlaySound(soundException);

  if(!DIMUconfigGyro(DIMU, DIMU_GYRO_RANGE_500))
    PlaySound(soundException);

  while (true){

		// Read the GYROSCOPE
    // There are 3 ways to do this:

    // All at once, very convenient if you need all 3
    DIMUreadGyroAxes(DIMU, x_val, y_val, z_val);

    // Via a single command with the axis specified as one of the arguments
		//x_val = DIMUreadGyroAxis(DIMU, DIMU_GYRO_X_AXIS);    // Get x-axis in dps.
		//y_val = DIMUreadGyroAxis(DIMU, DIMU_GYRO_Y_AXIS);    // Get y-axis in dps.
		//z_val = DIMUreadGyroAxis(DIMU, DIMU_GYRO_Z_AXIS);    // Get z-axis in dps.

    // Using a macro that calls the above function with the right argument
    // x_val = DIMUreadGyroXAxis(DIMU);    // Get x-axis in dps.
		// y_val = DIMUreadGyroYAxis(DIMU);    // Get y-axis in dps.
		// z_val = DIMUreadGyroZAxis(DIMU);    // Get z-axis in dps.

		nxtDisplayTextLine(1, "%f", x_val);
		nxtDisplayTextLine(2, "%f", y_val);
		nxtDisplayTextLine(3, "%f", z_val);

		// Read the accelerometer
		// Again, there are multiple ways to do this:

		// All at once, in either 8 bit or 10 bit format
		// DIMUreadAccelAxes8Bit(DIMU, x_val, y_val, z_val);
		// DIMUreadAccelAxes10Bit(DIMU, x_val, y_val, z_val);

		// One by one, specifying the axis as an argument, available in 8 and 10 bit.
		//
		// 8 bit
		//x_val = DIMUreadAccelAxis8Bit(DIMU, DIMU_ACC_X_AXIS);
		// y_val = DIMUreadAccelAxis8Bit(DIMU, DIMU_ACC_Y_AXIS);
		// z_val = DIMUreadAccelAxis8Bit(DIMU, DIMU_ACC_Z_AXIS);
		//
		// 10 bit
		x_val = DIMUreadAccelAxis10Bit(DIMU, DIMU_ACC_X_AXIS);
		y_val = DIMUreadAccelAxis10Bit(DIMU, DIMU_ACC_Y_AXIS);
		z_val = DIMUreadAccelAxis10Bit(DIMU, DIMU_ACC_Z_AXIS);

		// Function that doesn't require a specified axis, this is just a macro
		// x_val = DIMUreadAccelXAxis8Bit(DIMU);
    // y_val = DIMUreadAccelYAxis8Bit(DIMU);
    // z_val = DIMUreadAccelZAxis8Bit(DIMU);

    // x_val = DIMUreadAccelXAxis10Bit(DIMU);
    // y_val = DIMUreadAccelYAxis10Bit(DIMU);
    // z_val = DIMUreadAccelZAxis10Bit(DIMU);

		nxtDisplayTextLine(5, "%f", x_val);
		nxtDisplayTextLine(6, "%f", y_val);
		nxtDisplayTextLine(7, "%f", z_val);
		wait1Msec(50);
  }
}

/*
 * $Id: dexterind-imu-test1.c 133 2013-03-10 15:15:38Z xander $
 */
