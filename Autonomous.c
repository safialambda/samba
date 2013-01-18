#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     armRight,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     armLeft,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     frontLeft,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     rearLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     rearRight,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
//#include "hitechnic-irseeker-v2.h" //Include the file to communicate with IR seeker

// Directional values for DC and AC
int _dirDC = 0;
int _dirAC = 0;

// DC and AC values from 5 detectors
int dcS1, dcS2, dcS3, dcS4, dcS5 = 0;
int acS1, acS2, acS3, acS4, acS5 = 0;

// Set sesnsor to recognize 1200 Hz pulse
//tHTIRS2DSPMode _mode = DSP_1200;

void initializeRobot() {
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}

//void displayIRData() {
//  // Set the sensor mode, if unsucessful throw error
//  if (tHTIRS2DSPMode(IRSensor, _mode) == 0) {
//    eraseDisplay();
//    nxtDisplayCenteredTextLine(0, "ERROR!");
//    nxtDisplayCenteredTextLine(2, "Init failed!");
//    nxtDisplayCenteredTextLine(3, "Connect sensor");
//    nxtDisplayCenteredTextLine(4, "to Port 1.");

//    PlaySound(soundBeepBeep);
//    wait10Msec(300);
//    return;
//  }
//}

task main() {
  initializeRobot();

  // waitForStart(); // Wait for the beginning of autonomous phase.

  while (true) {
  	motor[frontRight] = 50;
  }
}
