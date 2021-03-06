#pragma config(Sensor, S2,     PCF8574,             sensorI2CCustomFastSkipStates)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * philips-pcf8574.h provides an API for the Philips PCF8574 IO MUX. This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 30 March 2010
 * version 0.1
 */

#include "philips-pcf8574.h"

task main () {
  while (true) {
    for (short i = 0; i < 8; i++) {
      short foo = 1 << i;
      foo = ~foo;
      PCF8574sendBytes(PCF8574, foo);
      sleep(50);
    }
    for (short i = 7; i > -1; i--) {
      short foo = 1 << i;
      foo = ~foo;
      PCF8574sendBytes(PCF8574, foo);
      sleep(50);
    }
  }
}
