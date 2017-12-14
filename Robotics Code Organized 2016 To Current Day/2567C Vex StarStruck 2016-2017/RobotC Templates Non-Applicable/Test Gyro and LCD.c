#pragma config(Sensor, in7,    gyro,                sensorGyro)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//////////////////////////////////////////////////////////////////////////////////////////////
//
//                                VEX LCD and Gyro Demo
//
// Short little program to demonstrate the VEX LCD and Gyro sensor.
//
// NOTE: The calibration for the gyro takes 1.1 seconds! Calibration is performed every time
// ====  a gyro sensor type is defined -- i.e. when the program first starts up. The gyro should
//       be kept in a stable non-moving position during the calibration process!
//
// Gyro sensor is configured on Port '7'. THe VEX LCD is used to display the various gyro
// parameters:
//    - Calculated angle.
//    - Full Scale (for modulus function). In this case 3600 for 360 degrees.
//    - Scaling factor used to translate analog value to angular acceleration (in degrees)
//    - Dead band to eliminate noise measurements.
//    - Bias value which is calculated with 200 measurements at steady state.
//
// Pushing the "enter" (Center) button will zero the sensor. [But not recalculate the bias].
//
// Even if you do not have a VEX LCD, you can monitor the program output using ROBOTC's "remote LCD"
// function. This is a PC window included in the ROBOTC IDE that copies the LCD display to a
// window on your PC display. You can view it when the ROBOTC Debugger is active via the menu
// command "Robot -> Debugger Windows -> Remote Display".
//
//////////////////////////////////////////////////////////////////////////////////////////////

int nCycles = 0;
int nMenuIndex = 0;
int nCurrentSeconds;
int nLastDisplayTime = -1;

task testMotorNoise();
void displayValue();

task main()
{
  startTask(testMotorNoise);
  bLCDBacklight = true;
  displayLCDPos(0, 0);
  displayNextLCDString("    Gyro Test   ");
  wait1Msec(500);

  SensorScale[gyro]    = 100;
  //SensorBias[gyro]     = 526;    // Override value calculated by driver.

  while (true)
  {
    ++nCycles;
    if (nLCDButtons & 0x01)
    {
      while (nLCDButtons & 0x01)
      {}
      --nMenuIndex;
    }

    else if (nLCDButtons & 0x04)
    {
      while (nLCDButtons & 0x04)
      {}
      ++nMenuIndex;
    }

    else if (nLCDButtons & 0x02)
    {
      while (nLCDButtons & 0x02)
      {}
      SensorValue[gyro] = 0;
      nMenuIndex = 0;
    }

    nMenuIndex += 4;
    nMenuIndex %= 4;

    switch (nMenuIndex)
    {
    case 0:
      nCurrentSeconds = time1[T1] / 1000;
      if (nCurrentSeconds != nLastDisplayTime)
      {
        nLastDisplayTime = nCurrentSeconds;
        displayValue();
      }
      break;
    case 1:   displayLCDPos(1, 0); displayNextLCDString("<<  Bias:999  >>");  displayLCDPos(1, 9); displayNextLCDNumber(SensorBias[gyro], 3);      break;
    case 2:   displayLCDPos(1, 0); displayNextLCDString("<< Range:9999 >>");  displayLCDPos(1, 9); displayNextLCDNumber(SensorFullCount[gyro], 4); break;
    case 3:   displayLCDPos(1, 0); displayNextLCDString("<< Scale:9999 >>");  displayLCDPos(1, 9); displayNextLCDNumber(SensorScale[gyro], 4);     break;
    }
    wait1Msec(10);

  }
}

void displayValue()
{
  int nValue;

  nValue = SensorValue[gyro];
  displayLCDPos(1, 0);
  displayNextLCDString("<< Gyro:      >>");
  displayLCDPos(1, 9);
  if (nValue < 0)
  {
    nValue = - nValue;
    displayNextLCDChar('-');
  }
  else
    displayNextLCDChar(' ');

  displayNextLCDNumber(nValue / 10);
  displayNextLCDChar('.');
  displayNextLCDNumber(nValue % 10, 1);
}


task testMotorNoise()
{
  //
  // There was concern that motor movement creates electrical noise on the gyro. This is a short little task to
  // generate some movement on a motor to see if it impacts the gyro position.
  //
  const int kStartupDelay = 5000;
  const int kCycleTime    =  400; //5000;

  wait1Msec(kStartupDelay);
  while (true)
  {
    motor[port2] = 127;
    wait1Msec(kCycleTime);
    motor[port2] = -127;
    wait1Msec(kCycleTime);
  }
}
