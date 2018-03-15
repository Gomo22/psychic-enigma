#pragma config(Sensor, in1,    liftpot,        sensorPotentiometer)
#pragma config(Sensor, in2,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, in8,    GYREEEEE,       sensorGyro)
#pragma config(Sensor, dgtl1,  SAencoder,      sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           DO_NUT_USE_Indeed, tmotorNone, openLoop)
#pragma config(Motor,  port2,           MGLiftMotorR,  tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           LDMotors,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RSAMotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LSAMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RDMotors,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           ClawMotor,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          MGLiftMotorL,  tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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


	if(SABack)
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

int lcount;
bool expanding = false;
bool up;
task expand()
{
	expanding = true;
	if(up)
	{
		motor[RLift]=127;
		motor[LLift]=127;
		while(SensorValue[liftpot] < lcount) wait1Msec(10);
		motor[RLift]=0;
		motor[LLift]=0;
	}
	else
	{
		motor[RLift]=-127;
		motor[LLift]=-127;
		while(SensorValue[liftpot] > lcount) wait1Msec(10);
		motor[RLift]=0;
		motor[LLift]=0;
	}
	expanding = false;
}


task main()
{
	///restart////////////////






















/*
	/////right side
	//Swings SA back, Deploys  MG out ,drives till MG(1350), retracts MG with MG
	SAback = true
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
	startTask(drive)
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
	while(driving) wait1Msec(10)
		in=true;
	lifttime=750;
	suck= false;
	sucktime=1500;
	startTask(claw);
	SAback=true;
	SAtime=1500;
	startTask(MoveSA)
	in=true;
	lifttime=900;
	startTask(MG);
	while(lifting) wait1Msec(10);
	while(SAMoving) wait1Msec(10);
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
*/


}
