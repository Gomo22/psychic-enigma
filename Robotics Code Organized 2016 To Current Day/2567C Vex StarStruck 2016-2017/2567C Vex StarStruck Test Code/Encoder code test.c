#pragma config(Sensor, dgtl1,  LSpeed,         sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  RSpeed,         sensorQuadEncoder)
#pragma config(Motor,  port2,           LBack,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           LFront,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           LBarMotors,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           RBarMotors,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LClawMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           RClawMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RBack,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           RFront,        tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = false;

	//Clear sensor values
	SensorValue[dgtl1]=0;					//	CLEAR
	SensorValue[dgtl3]=0;					//	CLEAR

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

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

	//Clear sensor values
	SensorValue[dgtl1]=0;
	SensorValue[dgtl3]=0;
	/////////////////////// AUTO STRAIGHTEN ///////////////////////////
	if(SensorValue[dgtl1]> SensorValue[dgtl3])
	{
		motor[port2]=55;
		motor[port3]=55;
		motor[port8]=61;
		motor[port9]=61;
	}

	if(SensorValue[dgtl1]< SensorValue[dgtl3])
	{
		motor[port2]=61;
		motor[port2]=61;
		motor[port8]=55;
		motor[port9]=55;
	}

	if(SensorValue[dgtl1] == SensorValue[dgtl3])
	{
		motor[port2]=61;
		motor[port2]=61;
		motor[port8]=61;
		motor[port9]=61;
	}

	//CLEAR SENSORS FOR DRIVER CONTROL PERIOD
	SensorValue[dgtl1]=0;
	SensorValue[dgtl3]=0;
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

		/////////////////////// AUTO STRAIGHTEN ///////////////////////////
		if(SensorValue[dgtl1]< SensorValue[dgtl3])
		{
			motor[port2]=vexRT[Ch3]-5;
			motor[port3]=vexRT[Ch3]-5;
			motor[port8]=vexRT[Ch2];
			motor[port9]=vexRT[Ch2];
		}

		if(SensorValue[dgtl1]> SensorValue[dgtl3])
		{
			motor[port2]=vexRT[Ch3];
			motor[port2]=vexRT[Ch3];
			motor[port8]=vexRT[Ch2]-17;
			motor[port9]=vexRT[Ch2]-17;
		}

		if(SensorValue[dgtl1] == SensorValue[dgtl3])
		{
			motor[port2]=vexRT[Ch3];
			motor[port2]=vexRT[Ch3];
			motor[port8]=vexRT[Ch2];
			motor[port9]=vexRT[Ch2];
		}



		if(vexRT[Btn6U] == 1)       //motor code for bar lift going up
		{
			motor[port4] = 123;				//motor code for port 4 going up
			motor[port5] = 123;				//motor code for port 5 going up
		}

		else if(vexRT[Btn6D] == 1)	//motor code for bar lift going down
		{
			motor[port4] = -40;				//motor code for port 4 going down
			motor[port5] = -40;				//motor code for port 5 going down
		}

		else												//stop for bar lift
		{
			motor[port4] = 0;         // end motor code for port 4
			motor[port5] = 0;					// end motor code for port 5
		}


		if(vexRT[Btn5U] == 1)				//motor code for claw opening
		{
			motor[port6] = 63;				//motor code for port 6 going out
			motor[port7] = 63;				//motor code for port 7 going out
		}

		else if(vexRT[Btn5D] == 1)			//motor code for claw closing
		{
			motor[port6] = -73;				//motor code for port 6 coming in
			motor[port7] = -73;				//motor code for port 7 coming in
		}

		else												//motor code for claw stop
		{
			motor[port6] = 0;					//end motor code for port 6
			motor[port7] = 0;					//end motor code for port 7
		}

	}
}
//http://wp.robodesigners.com/wordpress/?p=38
