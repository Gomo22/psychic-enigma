#pragma config(Sensor, in1,    gyroSensor,     sensorGyro)
#pragma config(Sensor, in2,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl7,  ClawEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           DO_NUT_USE_Indeed,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           MGLiftMotorR,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           RDMotors,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RSAMotor,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LSAMotor,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LDMotors,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           ClawMotor,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          MGLiftMotorL,  tmotorVex393_HBridge, openLoop)
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
	bStopTasksBetweenModes = true;

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
	// Insert user code here.
	// ..........................................................................

	while(true)
	{
		motor[port1] = 0;
	}
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

		if(vexRT[Btn6U] == 1)       //motor code for bar lift going up
		{
			motor[LLift] = 127;			//motor code for LBLift going up
			motor[RLift] = 127;  	  //motor code for RBLift going up
		}

		else if(vexRT[Btn6D] == 1)	//motor code for bar lift going down
		{
			motor[LLift] = -127;			//motor code for LBLift going down
			motor[RLift] = -127;  	  //motor code for RBLift going down
		}

		else												//stop for bar lift
		{
			motor[LLift] = 0;				//end of motor code for LBLift
			motor[RLift] = 0;  		  //end of motor code for RBLift
		}


		////////////////////////////////////////////////////////////////////

		if(vexRT[Btn6U] == 1)       //motor code for Swing Arm going forward
		{
			motor[LSAMotor] = 127;			//motor code for Swing Arm going forward
			motor[RSAMotor] = 127;			//motor code for Swing Arm going forward
		}

		else if(vexRT[Btn6D] == 1)	//motor code for Swing Arm going backward
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

		if(vexRT[Btn5U] == 1)       //motor code for claw motors picking up
		{
			motor[ClawMotor] = 127;				//motor code for claw motors picking up
		}

		else if(vexRT[Btn5D] == 1)	//motor code for claw motors dropping
		{
			motor[ClawMotor] = -127;			//motor code for claw motors dropping
		}

		else												//stop for claw motors
		{
			motor[ClawMotor] = 0;					// end motor code for claw motors
		}


		////////////////////////////////////////////////////////////////////

		if(vexRT[Btn8U] == 1)	//motor code for Mobile Goal Lift going out
		{
			motor[MGLiftMotorL] = 127;				//motor code for Mobile Goal Lift going out
			motor[MGLiftMotorR] = 127;				//motor code for Mobile Goal Lift going out
		}

		else if(vexRT[Btn8D] == 1)       //motor code for Mobile Goal Lift coming in
		{
			motor[MGLiftMotorL] = -127;				//motor code for Mobile Goal Lift coming in
			motor[MGLiftMotorR] = -127;				//motor code for Mobile Goal Lift coming in
		}

		else												//stop for Mobile Goal Lift motors
		{
			motor[MGLiftMotorL] = 0;					//stop motor code for Mobile Goal Lift motors
			motor[MGLiftMotorR] = 0;					//stop motor code for Mobile Goal Lift motors
		}

	}
}
