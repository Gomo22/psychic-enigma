#pragma config(Sensor, dgtl1,  REncoder,       sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  LEncoder,       sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  Sonar,          sensorSONAR_inch)
#pragma config(Motor,  port1,           LExtraBarMotor, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           RFront,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RBack,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           LBarMotors,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           RBarMotors,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LClawMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RClawMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LBack,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           LFront,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          RExtraBarMotor, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int speed;
	speed=103;

	int correction;
	correction=86;



	//////////////Clear sensor values
	SensorValue[dgtl1]=0;
	SensorValue[dgtl7]=0;
	/////////////////////////////////
	motor[port6] = -127;
	motor[port7] = -127;
	wait1Msec(575);
	motor[port6]=0;
	motor[port7]=0;
	wait1Msec(100);
	motor[port4] = -123;
	motor[port5] = -123;
	motor[port1] = -123;
	motor[port10] = -123;
	wait1Msec(1050);
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port1] = 0;
	motor[port10] = 0;
	wait1Msec(50);
	///////////////Base Forward 1//////////////
	while(SensorValue[Sonar]<28)
	{
		/////////////////////// AUTO STRAIGHTEN ///////////////////////////
		if(SensorValue[REncoder] > SensorValue[LEncoder])
		{
			motor[RFront]=correction;
			motor[RBack]=correction;
			motor[LFront]=speed;
			motor[LBack]=speed;
		}

		if(SensorValue[LEncoder] > SensorValue[REncoder])
		{
			motor[RFront]=speed;
			motor[RBack]=speed;
			motor[LFront]=correction;
			motor[LBack]=correction;
		}

		if(SensorValue[REncoder] == SensorValue[LEncoder])
		{
			motor[RFront]=speed;
			motor[RBack]=speed;
			motor[LFront]=speed;
			motor[LBack]=speed;
		}
	}

	motor[RFront]=50;
	motor[LFront]=50;
	motor[RBack]=50;
	motor[LBack]=50;
	wait1Msec(450);
	motor[RFront]=0;
	motor[LFront]=0;
	motor[RBack]=0;
	motor[LBack]=0;
	wait1Msec(500);




	//////////////Clear sensor values
	SensorValue[dgtl1]=0;
	SensorValue[dgtl7]=0;

	while(SensorValue[Sonar]>20)
	{
		/////////////////////// AUTO STRAIGHTEN ///////////////////////////
		if(SensorValue[REncoder] > SensorValue[LEncoder])
		{
			motor[RFront]=-correction;
			motor[RBack]=-correction;
			motor[LFront]=-speed;
			motor[LBack]=-speed;
		}

		if(SensorValue[LEncoder] > SensorValue[REncoder])
		{
			motor[RFront]=-speed;
			motor[RBack]=-speed;
			motor[LFront]=-correction;
			motor[LBack]=-correction;
		}

		if(SensorValue[REncoder] == SensorValue[LEncoder])
		{
			motor[RFront]=-speed;
			motor[RBack]=-speed;
			motor[LFront]=-speed;
			motor[LBack]=-speed;
		}
	}
	motor[RFront]=0;
	motor[RBack]=0;
	motor[LFront]=0;
	motor[LBack]=0;
	wait1Msec(100);
	motor[port4] = 123;
	motor[port5] = 123;
	motor[port1] = 123;
	motor[port10]= 123;
	wait1Msec(1050);
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port1] = 0;
	motor[port10] = 0;
	motor[RFront]=103;
	motor[LFront]=0;
	motor[RBack]=103;
	motor[LBack]=0;
	wait1Msec(550);
	motor[RFront]=93;
	motor[LFront]=93;
	motor[RBack]=93;
	motor[LBack]=93;
	wait1Msec(850);
	motor[RFront]=0;
	motor[LFront]=0;
	motor[RBack]=0;
	motor[LBack]=0;
	motor[port6] = -127;
	motor[port7] = -127;
	wait1Msec(575);
	motor[port6] = 0;
	motor[port7] = 0;
	wait1Msec(100);
	motor[port6]=-60;
	motor[port7]=-60;
	motor[port4] = -123;
	motor[port5] = -123;
	motor[port1] = -123;
	motor[port10] = -123;
	wait1Msec(2000);
	motor[RFront]=0;
	motor[LFront]=103;
	motor[RBack]=0;
	motor[LBack]=103;
	wait1Msec(600);
	motor[RFront]=93;
	motor[LFront]=93;
	motor[RBack]=93;
	motor[LBack]=93;
	wait1Msec(450);
	motor[RFront]=0;
	motor[LFront]=0;
	motor[RBack]=0;
	motor[LBack]=0;
	wait1Msec(500);
	motor[port6]=60;
	motor[port7]=60;
	wait1Msec(500);
	motor[port6]=0;
	motor[port7]=0;
	wait1Msec(50);
}
