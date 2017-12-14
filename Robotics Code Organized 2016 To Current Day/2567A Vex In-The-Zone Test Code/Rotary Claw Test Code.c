#pragma config(Sensor, in1,    gyroSensor,     sensorGyro)
#pragma config(Sensor, in2,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl7,  ClawEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           idek,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           MGLiftMotors,  tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RDMotors,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           RTLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RBLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LBLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LTLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LDMotors,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           ClawMotors,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          fakewhiteboi,  tmotorVex393_HBridge, openLoop)


task main()
{
	while (true)
	{

		motor[RDMotors]  = vexRT[Ch3];
		motor[LDMotors]  = vexRT[Ch2];

		////////////////////////////////////////////////////////////////////

		if(vexRT[Btn6U] == 1)       //motor code for bar lift going up
		{
			motor[LTLift] = 127;			//motor code for LTLift going up
			motor[LBLift] = 127;			//motor code for LBLift going up
			motor[RTLift] = 127;      //motor code for RTLift going up
			motor[RBLift] = 127;  	  //motor code for RBLift going up

		}

		else if(vexRT[Btn6D] == 1)	//motor code for bar lift going down
		{
			motor[LTLift] = -127;			//motor code for LTLift going down
			motor[LBLift] = -127;			//motor code for LBLift going down
			motor[RTLift] = -127;     //motor code for RTLift going down
			motor[RBLift] = -127;  	  //motor code for RBLift going down

		}

		else												//stop for bar lift
		{
			motor[LTLift] = 0;				//end of motor code for LTLift
			motor[LBLift] = 0;				//end of motor code for LBLift
			motor[RTLift] = 0;    	  //end of motor code for RTLift
			motor[RBLift] = 0;  		  //end of motor code for RBLift
		}

		////////////////////////////////////////////////////////////////////

		if(vexRT[Btn5U] == 1)       //motor code for claw motors picking up
		{
			motor[ClawMotors] = 64;				//motor code for claw motors picking up
		}

		else if(vexRT[Btn5D] == 1)	//motor code for claw motors dropping
		{
			motor[ClawMotors] = -64;			//motor code for claw motors dropping
		}

		else												//stop for claw motors
		{
			motor[ClawMotors] = 0;					// end motor code for claw motors
		}


		////////////////////////////////////////////////////////////////////

		if(vexRT[Btn8U] == 1)       //motor code for Mobile Goal Lift lifting
		{
			motor[MGLiftMotors] = 127;				//motor code for Mobile Goal Lift lifting
		}

		else if(vexRT[Btn8D] == 1)	//motor code for Mobile Goal Lift lowering
		{
			motor[MGLiftMotors] = -64;			//motor code for Mobile Goal Lift lowering
		}

		else												//stop for Mobile Goal Lift motors
		{
			motor[MGLiftMotors] = 0;					// end motor code for Mobile Goal Lift motors
		}



	}
}
