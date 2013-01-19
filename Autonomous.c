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
tHTIRS2DSPMode _mode = DSP_1200;

// Array of strings to keep track of changes 
string sTextLines[8];

// displayText function prototype
void displayText(int nLineNumber, string cChar, int nValueDC, int nValueAC);

void initializeRobot() {
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}

void displayIRData() {
  // Set the sensor mode, if unsucessful throw error
  if (tHTIRS2DSPMode(IRSensor, _mode) == 0) {
    eraseDisplay();
    nxtDisplayCenteredTextLine(0, "ERROR!");
    nxtDisplayCenteredTextLine(2, "Init failed!");
    nxtDisplayCenteredTextLine(3, "Connect sensor");
    nxtDisplayCenteredTextLine(4, "to Port 1.");

    PlaySound(soundBeepBeep);
    wait10Msec(300);
    return;
  }
  
  for (int i = 0; i < 8; ++i) {
    sTextLines[i] = "";
  }
  
  eraseDisplay();
  nxtDisplayTextLine(0, "       DC    AC");
  nxtDisplayTextLine(1, "-----------------");
  
  while (true) {
    _dirDC = HTIRS2readDCDir(HTIRS2);
    if (_dirDC < 0) {
      break;
    }
    _dirAC = HTIRS2readACDir(HTIRS2);
    if (_dirAC < 0) {
      break;
    }

    if (!HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5)) {
      break;
    }
    if (!HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS5)) {
      break;
    }
    displayText(2, "D", _dirDC, _dirAC);
    displayText(3, "0", dcS1, acS1);
    displayText(4, "1", dcS2, acS2);
    displayText(5, "2", dcS3, acS3);
    displayText(6, "3", dcS4, acS4);
    displayText(7, "4", dcS5, acS5);

    wait10Msec(5);
  }
}

void displayText(int nLineNumber, string cChar, int nValueDC, int nValueAC) {
  string sTemp;
  StringFormat(sTemp, "%4d  %4d", nValueDC, nValueAC);
  // Check if the new line is the same as the previous one
  // Only update screen if it's different.
  if (sTemp != sTextLines[nLineNumber]) {
    string sTemp2;
    sTextLines[nLineNumber] = sTemp;
    StringFormat(sTemp2, "%s:  %s", cChar, sTemp);
    nxtDisplayTextLine(nLineNumber, sTemp2);
  }
}

task main() {
  initializeRobot();

  // waitForStart(); // Wait for the beginning of autonomous phase.

  while (true) {}
}
