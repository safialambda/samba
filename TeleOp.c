#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     armRight,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     armLeft,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rearLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     rearRight,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void initializeRobot() {
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}

task main() {
  initializeRobot();

  waitForStart();   // wait for start of tele-op phase

  while (true) {
  }
}
