#pragma config(Motor,  port2,           LBack,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           LFront,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           LBarMotors,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           RBarMotors,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LClawMotor,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           RClawMotor,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RBack,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           RFront,        tmotorVex393HighSpeed_MC29, openLoop, reversed)



void driveVariable()
{
	while(true)
	{
		motor[port2]=vexRT[Ch2];
		motor[port2]=vexRT[Ch2];
		motor[port8]=vexRT[Ch3];
		motor[port9]=vexRT[Ch3];
	}
}
void barliftVariable()
{
	while(true)
	{
		if(vexRT[Btn6U] == 1)       //motor code for bar lift going up
		{
			motor[port4] = 40;				//motor code for port 4 going up
			motor[port5] = 40;				//motor code for port 5 going up

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
	}
}

task main()
{
	driveVariable();
	barliftVariable();
}
