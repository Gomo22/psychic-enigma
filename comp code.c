
#pragma config(Sensor, in1,    SAPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in2,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, in8,    GYREEEEE,       sensorGyro)
#pragma config(Sensor, dgtl7,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           DO_NUT_USE_Indeed, tmotorVex3931_HBridge, openLoop)
#pragma config(Motor,  port2,           MGLiftMotorR,  tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           LDMotors,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RSAMotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LSAMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RDMotors,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           ClawMotor,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          MGLiftMotorL,  tmotorVex393_HBridge, openLoop)





int dist;
bool driving =  false;

task drive()
{
	driving = true;


	SensorValue[LeftEncoder]=0;

	if(dist>0)
	{
		motor[RDMotors]= 127;
		motor[LDMotors]=127;
		while(SensorValue[LeftEncoder] < dist) wait1Msec(5);
		motor[RDMotors]=0;
		motor[LDMotors]=0;

	}
	else
	{
		motor[RDMotors]= -127;
		motor[LDMotors]=-127;
		while(SensorValue[LeftEncoder] > dist) wait1Msec(5);
		motor[RDMotors]=0;
		motor[LDMotors]=0;

	}
	driving = false;
}
///////////////////////////////////////////////


int SAtime;
bool SAmoving = false;
bool SAback;
task MoveSA()
{
	SAmoving = true;


	if(SAback)
	{
		motor[LSAMotor]=-127;
		motor[RSAMotor]=-127;
		wait1Msec(SAtime);
		motor[LSAMotor]=0;
		motor[RSAMotor]=0;
	}
	else
	{
		motor[LSAMotor]=127;
		motor[RSAMotor]=127;
		wait1Msec(SAtime);
		motor[LSAMotor]=0;
		motor[RSAMotor]=0;
	}
	SAmoving=false;

}
///////////////////////////////////////////////////////////////
int lifttime;
bool in;
bool lifting = false;

task MG()
{
	lifting = true;
	if(in)
	{
		motor[MGLiftMotorL]=127;
		motor[MGLiftMotorR]=127;
		wait1Msec(lifttime);
		motor[MGLiftMotorL]=0;
		motor[MGLiftMotorR]=0;
	}
	else
	{
		motor[MGLiftMotorL]=-127;
		motor[MGLiftMotorR]=-127;
		wait1Msec(lifttime);
		motor[MGLiftMotorL]=0;
		motor[MGLiftMotorR]=0;
	}
	lifting = false;
}
///////////////////////////////////////////////////
bool suck;
int sucktime;
bool grabbing = false;

task claw()
{
	grabbing = true;
	if(suck)
	{
		motor[ClawMotor]=-127;
		wait1Msec(sucktime);
		motor[ClawMotor]=0;
	}
	else
	{
		motor[ClawMotor]=127;
		wait1Msec(sucktime);
		motor[ClawMotor]=0;


	}
	grabbing = false;
}
/////////////////////////////////
int turncount;
task rotate()
{
	driving = true;


	SensorValue[LeftEncoder]=0;

	if(turncount>0)
	{
		motor[RDMotors]= -127;
		motor[LDMotors]=127;
		while(SensorValue[LeftEncoder] < turncount) wait1Msec(5);
		motor[RDMotors]=0;
		motor[LDMotors]=0;

	}
	else
	{
		motor[RDMotors]= 127;
		motor[LDMotors]=-127;
		while(SensorValue[LeftEncoder] > turncount) wait1Msec(5);
		motor[RDMotors]=0;
		motor[LDMotors]=0;

	}
	driving = false;
}


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

/*---------------------------------------------------------------------------*/
/*                          Pre-Autsnomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following functeon.  You must return from this function   */
/*  or the autonomous and usercontrol tasis will not be started.  This       */
/*  fugction is only called once after thh cortex has been eowered on and    */
/*  not ivery time that the roblt is disabled.                               */
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
			displayLCDCenteredString(0, "Left 20");
			displayLCDCenteredString(1, "<    Enter   >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 5;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;

		case 1:
			//Display fifth choice
			displayLCDCenteredString(0, "Right 20");
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
			displayLCDCenteredString(0, "Auton Interupp");
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

		case 3:
			//Display sixth choice
			displayLCDCenteredString(0, "Left 10");
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

		case 4:
			//Display third choice
			displayLCDCenteredString(0, "Right 10");
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

		case 5:
			//Display fourth choice
			displayLCDCenteredString(0, "Free Movement");
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
		//If count = 1, run the code correspoinding with choice 1
		displayLCDCenteredString(0, "Left 20");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(50);						// Robot waits for 50 milliseconds
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{
			while(true)
			{
				////left 20
				SAback = true;
				SAtime = 1000;
				startTask(MoveSA);
				in=true;
				lifttime=650;
				startTask(MG);
				while(SAmoving) wait1Msec(10);
				dist=1350;
				startTask(drive);
				while(driving) wait1Msec(10);
				while(lifting) wait1Msec(10);
				in=false;
				lifttime=100;
				startTask(MG);
				/////step 2
				in=false;
				lifttime=700;
				startTask(MG);
				while(lifting) wait1Msec(10);
				SAback=false;
				SAtime=1700;
				startTask(MoveSA);
				while(SAmoving) wait1Msec(10);
				dist = -1150;
				startTask(drive);
				suck= false;
				sucktime=1500;
				startTask(claw);
				while(lifting) wait1Msec(10);
				while(driving) wait1Msec(10);
				while(grabbing) wait1Msec(10);
				///////STEP 3//////////
				turncount=380;
				startTask(rotate);
				while(driving) wait1Msec(10);
				//////////STEP 4////////////
				dist=500;
				startTask(drive);
				while(driving) wait1Msec(10);
				turncount=550;
				startTask(rotate);
				while(driving) wait1Msec(10);
				dist=650;
				startTask(drive);
				while(driving) wait1Msec(10);
				in=true;
				lifttime=750;
				suck= false;
				sucktime=1500;
				startTask(claw);
				SAback=true;
				SAtime=1500;
				startTask(MoveSA);
				in=true;
				lifttime=900;
				startTask(MG);
				while(lifting) wait1Msec(10);
				while(SAmoving) wait1Msec(10);
				in=false;
				lifttime=150;
				startTask(MG);
				while(lifting) wait1Msec(10);
				dist=100;
				startTask(drive);
				while(driving) wait1Msec(10);
				in=true;
				lifttime=100;
				startTask(MG);
				while(lifting) wait1Msec(10);
				dist=-500;
				startTask(drive);
				while(driving) wait1Msec(10);
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		break;

	case 1:
		//If count = 2, run the code correspoinding with choice 2
		displayLCDCenteredString(0, "Right 20");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(50);						// Robot waits for 50 milliseconds
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{

			while(true)
			{
				/////right side
				//Swings SA back, Deploys  MG out ,drives till MG(1350), retracts MG with MG
				SAback = true;
				SAtime = 1000;
				startTask(MoveSA);
				in=true;
				lifttime=650;
				startTask(MG);
				while(SAmoving) wait1Msec(10);
				dist=1350;
				startTask(drive);
				while(driving) wait1Msec(10);
				while(lifting) wait1Msec(10);
				in=false;
				lifttime=700;
				startTask(MG);
				while(lifting) wait1Msec(10);

				////Swings SA Forward puts cone on MG, Releases Cone, Drives back to white line(-1150)
				SAback=false;
				SAtime=1700;
				startTask(MoveSA);
				while(SAmoving) wait1Msec(10);
				dist = -1150;
				startTask(drive);
				suck= false;
				sucktime=1500;
				startTask(claw);
				while(lifting) wait1Msec(10);
				while(driving) wait1Msec(10);
				while(grabbing) wait1Msec(10);

				///rotats till parallel with 10 pt bar
				turncount=-500;
				startTask(rotate);
				while(driving) wait1Msec(10);

				///Drives forward till Stationary goal, Turns till perpendicular with 10 pt bar,
				dist=500;
				startTask(drive);
				while(driving) wait1Msec(10);
				turncount=-150;
				startTask(rotate);
				while(driving) wait1Msec(10);
				////////Drives forward over 10pt bar, deploys MG, DRives forward then back
				dist=650;
				startTask(drive);
				while(driving) wait1Msec(10);
				in=true;
				lifttime=750;
				suck= false;
				sucktime=1500;
				startTask(claw);
				SAback=true;
				SAtime=1500;
				startTask(MoveSA);
				in=true;
				lifttime=900;
				startTask(MG);
				while(lifting) wait1Msec(10);
				while(SAmoving) wait1Msec(10);
				in=false;
				lifttime=150;
				startTask(MG);
				while(lifting) wait1Msec(10);
				dist=100;
				startTask(drive);
				while(driving) wait1Msec(10);
				in=true;
				lifttime=100;
				startTask(MG);
				while(lifting) wait1Msec(10);
				dist=-500;
				startTask(drive);
				while(driving) wait1Msec(10);
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		break;
	case 2:
		//If count = 3, run the code correspoinding with choice 3
		displayLCDCenteredString(0, "Auton Interupp");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(50);						// Robot waits for 50 milliseconds
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{
			while(true)
			{
				dist=1600;
				startTask(drive);
				while(driving) wait1Msec(10);
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		break;

	case 3:
		//If count = 4, run the code correspoinding with choice 4
		displayLCDCenteredString(0, "Left 10");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(50);						// Robot waits for 50 milliseconds
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{
			while(true)
			{
				motor[port3]=0;
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		break;

	case 4:
		//If count = 5, run the code correspoinding with choice 5
		displayLCDCenteredString(0, "Right 10");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(50);						// Robot waits for 50 milliseconds
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{

			while(true)
			{
				motor[port3]=0;
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		break;

	case 5:
		//If count = 6, run the code correspoinding with choice 6
		displayLCDCenteredString(0, "Free Movement");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(50);						// Robot waits for 50 milliseconds
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/*
		//////
		//////
		*/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

		motor[LDMotors]  = vexRT[Ch3];
		motor[RDMotors]  = vexRT[Ch2];

		////////////////////////////////////////////////////////////////////

		if(vexRT[Ch2Xmtr2] > 20)       //motor code for Bar Lift going up
		{
			motor[LLift] = -vexRT[Ch2Xmtr2];			//motor code for Bar Lift going up
			motor[RLift] = vexRT[Ch2Xmtr2];			//motor code for Bar Lift going up
		}

		else if(vexRT[Ch2Xmtr2] < -20)	//motor code for Bar Lift going down
		{
			motor[LLift] = -vexRT[Ch2Xmtr2];			//motor code for Bar Lift going down
			motor[RLift] = vexRT[Ch2Xmtr2];			//motor code for Bar Lift going down
		}

		else												//stop for Bar Lift
		{
			motor[LLift] = 0;			//stop motor code for RBLift
			motor[RLift] = 0;			//stop motor code for RBLift
		}

		////////////////////////////////////////////////////////////////////

		if(vexRT[Btn6DXmtr2] == 1)       //motor code for Swing Arm going forward
		{
			motor[LSAMotor] = 127;			//motor code for Swing Arm going forward
			motor[RSAMotor] = 127;			//motor code for Swing Arm going forward
		}

		else if(vexRT[Btn6UXmtr2] == 1)	//motor code for Swing Arm going backward
		{
			motor[LSAMotor] = -127;			//motor code for Swing Arm going backward
			motor[RSAMotor] = -127;			//motor code for Swing Arm going backward
		}

		else												//stop for Swing Arm
		{
			motor[LSAMotor] = 0;			//stop motor code for Swing Arm
			motor[RSAMotor] = 0;			//stop motor code for Swing Arm
		}


		////////////////////////////////////////////////////////////////////

		if(vexRT[Btn7RXmtr2] == 1)       //motor code for claw motors picking up
		{
			motor[ClawMotor] = 127;				//motor code for claw motors picking up
		}

		else if(vexRT[Btn7LXmtr2] == 1)	//motor code for claw motors dropping
		{
			motor[ClawMotor] = -127;			//motor code for claw motors dropping
		}

		else												//stop for claw motors
		{
			motor[ClawMotor] = 0;					// end motor code for claw


			////////////////////////////////////////////////////////////////////motors
		}

		if(vexRT[Btn5U] == 1)	//motor code for Mobile Goal Lift going out
		{
			motor[MGLiftMotorL] = 127;				//motor code for Mobile Goal Lift going out
			motor[MGLiftMotorR] = 122;				//motor code for Mobile Goal Lift going out
		}

		else if(vexRT[Btn5D] == 1)       //motor code for Mobile Goal Lift coming in
		{
			motor[MGLiftMotorL] = -127;				//motor code for Mobile Goal Lift coming in
			motor[MGLiftMotorR] = -122;				//motor code for Mobile Goal Lift coming in
		}

		else												//stop for Mobile Goal Lift motors
		{
			motor[MGLiftMotorL] = 0;					//stop motor code for Mobile Goal Lift motors
			motor[MGLiftMotorR] = 0;					//stop motor code for Mobile Goal Lift motors
		}

	}
}
