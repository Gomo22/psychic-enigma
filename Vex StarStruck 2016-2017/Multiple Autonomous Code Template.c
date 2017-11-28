/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
//http://help.robotc.net/WebHelpVEX/Content/Resources/topics/ROBOTC_Interface/Toolbars/Toolbars.htm
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------
int count;
void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	const short leftButton = 1;
	const short centerButton = 2;
	const short rightButton = 4;


	//Declare count variable to keep track of our choice

	count=0;

	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	bLCDBacklight=true;
	while(nLCDButtons != centerButton)
	{
		//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "Autonomous 1");
			displayLCDCenteredString(1, "<    Enter   >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 2;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;

		case 1:
			//Display fifth choice
			displayLCDCenteredString(0, "Autonomous 2");
			displayLCDCenteredString(1, "<    Enter   >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;

		case 2:
			//Display second choice
			displayLCDCenteredString(0, "Autonomous 3");
			displayLCDCenteredString(1, "<    Enter   >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;


		default:
			count = 0;
			break;
		}

		//------------- End of User Interface Code ---------------------
	}
	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	bDisplayCompetitionStatusOnLcd = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...



}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	// ..........................................................................
	// Insert user code here
	// ..........................................................................
	//------------- Beginning of Robot Movement Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Switch Case that actually runs the user choice
	switch(count){
	case 0:
		//If count = 0, run the code correspoinding with choice 1
		displayLCDCenteredString(0, "Autonomous 1");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(200);						// Robot waits for 200 milliseconds
		while(true)
		{

			motor[port1] = 0;

		}
		break;

	case 1:
		//If count = 1, run the code correspoinding with choice 2
		displayLCDCenteredString(0, "Autonomous 2");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(200);						// Robot waits for 200 milliseconds
		while(true)
		{

			motor[port1] = 0;

		}
		break;

	case 2:
		//If count = 2, run the code correspoinding with choice 3
		displayLCDCenteredString(0, "Autonomous 3");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(200);						// Robot waits for 200 milliseconds
		while(true)
		{

			motor[port1] = 0;

		}
		break;

	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
		break;
	}
	//------------- End of Robot Movement Code -----------------------

}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{

		motor[port1] = 0;

	}
}
