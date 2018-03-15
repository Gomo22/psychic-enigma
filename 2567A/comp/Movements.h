#ifndef movements
#define movements


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


int SApostion;
bool SAmoving = false;
bool SAback;
task MoveSA()
{
	SAmoving = true;

	SensorValue[SAencoder] = 0;

if(SApostion>0)
{
	motor[LSAMotor]=-127;
	motor[RSAMotor]=-127;
	while(SensorValue[SAencoder] < SApostion) wait1Msec(5);
	motor[LSAMotor]=0;
	motor[RSAMotor]=0;
}
else
{
	motor[LSAMotor]=127;
	motor[RSAMotor]=127;
	while(SensorValue[SAencoder] > SApostion) wait1Msec(5);
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
	motor[ClawMotor]=127;
	wait1Msec(sucktime);
	motor[ClawMotor]=0;
}
else
{
	motor[ClawMotor]=-127;
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
		motor[RDMotors]= -64;
		motor[LDMotors]=64;
		while(SensorValue[LeftEncoder] < turncount) wait1Msec(5);
		motor[RDMotors]=0;
		motor[LDMotors]=0;

	}
	else
	{
		motor[RDMotors]= 64;
		motor[LDMotors]=-64;
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

#endif
