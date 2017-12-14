#pragma config(Sensor, dgtl1,  REncoder,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  LEncoder,       sensorQuadEncoder)
#pragma config(Motor,  port1,           RExtraBarMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           RFront,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RBack,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RBarMotors,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LBarMotors,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LClawMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RClawMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LBack,	       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           LFront,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          LExtraBarMotor, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                            */
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

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	//------------- End of User Interface Code ---------------------

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
	while(true)
	{

		//////////////Clear sensor values
		SensorValue[dgtl1]=0;
		SensorValue[dgtl3]=0;

		motor[port6] = -127;
		motor[port7] = -127;
		motor[RFront]= 127;
		motor[LFront]= 63;
		motor[RBack]= 127;
		motor[LBack]= 63;
		motor[port4] = -127;
		motor[port5] = -127;
		motor[port1] = -127;
		motor[port10] = -127;
		wait1Msec(675);
		motor[port6] = 0;
		motor[port7] = 0;
		wait1Msec(175);
		motor[port4] = -30;
		motor[port5] = -30;
		motor[port1] = -30;
		motor[port10] = -30;
		untilEncoderCounts(650, dgtl1);
		motor[RFront]= 0;
		motor[LFront]= 0;
		motor[RBack]= 0;
		motor[LBack]= 0;
		motor[port4] = 0;
		motor[port5] = 0;
		motor[port1] = 0;
		motor[port10] = 0;
		wait1Msec(50);

		motor[RFront]= 90;
		motor[RBack]= 90;
		motor[LFront]= 90;
		motor[LBack]= 90;
		wait1Msec(250);

		//////////////Clear sensor values
		SensorValue[dgtl1]=0;
		SensorValue[dgtl3]=0;

		motor[RFront]= -50;
		motor[RBack]= -50;
		motor[LFront]= -50;
		motor[LBack]= -50;
		untilEncoderCounts(-350, dgtl1);

		//////////////Clear sensor values
		SensorValue[dgtl1]=0;
		SensorValue[dgtl3]=0;

		motor[RFront]= 0;
		motor[RBack]= 0;
		motor[LFront]= 0;
		motor[LBack]= 0;
		wait1Msec(50);

		//////////////Clear sensor values
		SensorValue[dgtl1]=0;
		SensorValue[dgtl3]=0;

		motor[RFront]= -90;
		motor[RBack]= -90;
		motor[LFront]= 90;
		motor[LBack]= 90;
		untilEncoderCounts(-300, dgtl1);

		motor[RFront]= 0;
		motor[RBack]= 0;
		motor[LFront]= 0;
		motor[LBack]= 0;
		wait1Msec(50);

		//////////////Clear sensor values
		SensorValue[dgtl1]=0;
		SensorValue[dgtl3]=0;

		motor[RFront]= 90;
		motor[RBack]= 90;
		motor[LFront]= 90;
		motor[LBack]= 90;
		untilEncoderCounts(300, dgtl1);

		motor[RFront]= 0;
		motor[RBack]= 0;
		motor[LFront]= 0;
		motor[LBack]= 0;
		wait1Msec(50);

		motor[port4] = -123;
		motor[port5] = -123;
		motor[port1] = -123;
		motor[port10] = -123;
		wait1Msec(750);

		motor[port4] = -30;
		motor[port5] = -30;
		motor[port1] = -30;
		motor[port10] = -30;
		motor[RFront]= 90;
		motor[RBack]= 90;
		motor[LFront]= -90;
		motor[LBack]= -90;
		untilEncoderCounts(300, dgtl1);

		motor[RFront]= 90;
		motor[RBack]= 90;
		motor[LFront]= 90;
		motor[LBack]= 90;
		untilEncoderCounts(300, dgtl1);

		motor[RFront]= 0;
		motor[RBack]= 0;
		motor[LFront]= 0;
		motor[LBack]= 0;
		wait1Msec(50);

		motor[port6] = -90;
		motor[port7] = -90;
		wait1Msec(600);

		motor[port6] = 0;
		motor[port7] = 0;
		wait1Msec(50);

		motor[port6] = 0;
		motor[port7] = 0;
		motor[port4] = 0;
		motor[port5] = 0;
		motor[port1] = 0;
		motor[port10] = 0;
		motor[RFront]=0;
		motor[RBack]=0;
		motor[LFront]=0;
		motor[LBack]=0;
		wait1Msec(100);

		wait1Msec(5058752378952879542092430789498403897);
	}
}
//------------- End of Robot Movement Code -----------------------


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

		motor[port2]=vexRT[Ch2];
		motor[port3]=vexRT[Ch2];
		motor[port8]=vexRT[Ch3];
		motor[port9]=vexRT[Ch3];


		////////////////////////////////////////////////////////////////////

		if(vexRT[Btn6U] == 1)       //motor code for bar lift going up
		{
			motor[port4] = -123;				//motor code for port 4 going up
			motor[port5] = -123;				//motor code for port 5 going up
			motor[port1] = -123;       //motor code for port 1 going up
			motor[port10] = -123;      //motor code for port 10 going up

		}

		else if(vexRT[Btn6D] == 1)	//motor code for bar lift going down
		{
			motor[port4] = 123;			//motor code for port 4 going down
			motor[port5] = 123;			//motor code for port 5 going down
			motor[port1] = 123;      //motor code for port 1 going down
			motor[port10] = 123;  	  //motor code for port 10 going down

		}

		else												//stop for bar lift
		{
			motor[port4] = 0;         // end motor code for port 4
			motor[port5] = 0;					// end motor code for port 5
			motor[port1] = 0;         // end motor code for port 1
			motor[port10] = 0;        // end motor code for port 10


		}


		////////////////////////////////////////////////////////////////////

		if(vexRT[Btn5D] == 1)       //motor code for claw opening
		{
			motor[port6] = 127;				//motor code for port 6 opening
			motor[port7] = 127;				//motor code for port 7 opening

		}

		else if(vexRT[Btn5U] == 1)	//motor code for claw closing
		{
			motor[port6] = -127;				//motor code for port 6 closing
			motor[port7] = -127;				//motor code for port 7 closing

		}

		else												//stop for claw motors
		{
			motor[port6] = 0;         // end motor code for port 6
			motor[port7] = 0;					// end motor code for port 7


		}
	}
}
