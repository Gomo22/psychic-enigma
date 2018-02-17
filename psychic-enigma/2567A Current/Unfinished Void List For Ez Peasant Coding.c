#pragma config(Sensor, in1,    gyroSensor,     sensorGyro)
#pragma config(Sensor, in2,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl7,  ClawEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           DO_NUT_USE_Indeed,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           MGLiftMotorR,  tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           LDMotors,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RSAMotor,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LSAMotor,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           RDMotors,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           ClawMotor,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          MGLiftMotorL,  tmotorVex393_HBridge, openLoop)



//------------------------------------------------------------------------------------


/*

void FFSUEC(float Count)	//Forwards Full Speed Until Encoder Counts
{
motor[RDMotors] = 127;
motor[LDMotors] = 127;
untilEncoderCounts(Count, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void FTQSUEC(float Count)	//Forwards Three Quarters Speed Until Encoder Counts
{
motor[RDMotors] = 96;
motor[LDMotors] = 96;
untilEncoderCounts(Count, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void FHSUEC(float Count)	//Forwards Half Speed Until Encoder Counts
{
motor[RDMotors] = 64;
motor[LDMotors] = 64;
untilEncoderCounts(Count, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void FQSUEC(float Count)	//Forwards Quarter Speed Until Encoder Counts
{
motor[RDMotors] = 32;
motor[LDMotors] = 32;
untilEncoderCounts(Count, LEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void FQSTOP()	//Forwards Quick Stop
{
motor[RDMotors] = -96;
motor[LDMotors] = -96;
wait1Msec(50);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}



//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------



void BFSUEC(float Count)	//Backwards Full Speed Until Encoder Counts
{
motor[RDMotors] = -127;
motor[LDMotors] = -127;
untilEncoderCounts(Count, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void BTQSUEC(float Count)	//Backwards Three Quarters Speed Until Encoder Counts
{
motor[RDMotors] = -96;
motor[LDMotors] = -96;
untilEncoderCounts(Count, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void BHSUEC(float Count)	//Backwards Half Speed Until Encoder Countsk
{
motor[RDMotors] = -64;
motor[LDMotors] = -64;
untilEncoderCounts(Count, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void BQSUEC(float Count)	//Backwards Quarter Speed Until Encoder Counts
{
motor[RDMotors] = -32;
motor[LDMotors] = -32;
untilEncoderCounts(Count, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void BQSTOP()	//Backwards Quick Stop
{
motor[RDMotors] = 127;
motor[LDMotors] = 127;
wait1Msec(50);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}



//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------



void SwingArmVoidPlzRememberThis()
{
motor[LSAMotor] = 0;
motor[RSAMotor] = 0;
}



//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------



void MGLOFS()	//Mobile Goal Lift Out Full Speed
{
motor[MGLiftMotorL] = 127;
motor[MGLiftMotorR] = 127;
wait1Msec(500);
motor[MGLiftMotorL] = 0;
motor[MGLiftMotorR] = 0;
}
void MGLOTQS()	//Mobile Goal Lift Out Three Quarters Speed
{
motor[MGLiftMotorL] = 96;
motor[MGLiftMotorR] = 96;
wait1Msec(500);
motor[MGLiftMotorL] = 0;
motor[MGLiftMotorR] = 0;
}


//------------------------------------------------------------------------------------


void MGLIFS()	//Mobile Goal Lift In Full Speed
{
motor[MGLiftMotorL] = -127;
motor[MGLiftMotorR] = -127;
wait1Msec(500);
motor[MGLiftMotorL] = 0;
motor[MGLiftMotorR] = 0;
}
void MGLITQS()	//Mobile Goal Lift In Three Quarters Speed
{
motor[MGLiftMotorL] = -96;
motor[MGLiftMotorR] = -96;
wait1Msec(500);
motor[MGLiftMotorL] = 0;
motor[MGLiftMotorR] = 0;
}



//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------



void ClawIntake(float time)
{
motor[ClawMotor] = 127;
wait1Msec(time);
motor[ClawMotor] = 0;
}
void ClawOutPut(float time)
{
motor[ClawMotor] = -127;
wait1Msec(time);
motor[ClawMotor] = 0;
}



//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------



void CLEV()
{
SensorValue[LeftEncoder] = 0;
SensorValue[RightEncoder] = 0;
}



//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------



void ST90DL()	//Swing Turn 90 Degrees Left
{
	motor[RDMotors] = 127;
	motor[LDMotors] = 0;
	untilEncoderCounts(225, LeftEncoder);
	motor[RDMotors] = 0;
	motor[LDMotors] = 0;
}
void ST90DR()	//Swing Turn 90 Degrees Right
{
	motor[RDMotors] = 0;
	motor[LDMotors] = 127;
	untilEncoderCounts(-225, LeftEncoder);
	motor[RDMotors] = 0;
	motor[LDMotors] = 0;
}


//------------------------------------------------------------------------------------


void ST180DL()	//Swing Turn 180 Degrees Left
{
motor[RDMotors] = 127;
motor[LDMotors] = 0;
untilEncoderCounts(YOUNEEDTOFINDTHEENCODERCOUNTLOL, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void ST180DR()	//Swing Turn 180 Degrees Right
{
motor[RDMotors] = 0;
motor[LDMotors] = 127;
untilEncoderCounts(YOUNEEDTOFINDTHEENCODERCOUNTLOL, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}


//------------------------------------------------------------------------------------


void ST270DL()	//Swing Turn 270 Degrees Left
{
motor[RDMotors] = 127;
motor[LDMotors] = 0;
untilEncoderCounts(YOUNEEDTOFINDTHEENCODERCOUNTLOL, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void ST270DR()	//Swing Turn 270 Degrees Right
{
motor[RDMotors] = 0;
motor[LDMotors] = 127;
untilEncoderCounts(YOUNEEDTOFINDTHEENCODERCOUNTLOL, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}



//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

*/

void PT90DL()	//Point Turn 90 Degrees Left
{
motor[RDMotors] = 127;
motor[LDMotors] = -127;
untilEncoderCounts(200, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void PT90DR()	//Point Turn 90 Degrees Right
{
motor[RDMotors] = -127;
motor[LDMotors] = 127;
untilEncoderCounts(-225, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}

/*
//------------------------------------------------------------------------------------


void PT180DL()	//Point Turn 180 Degrees Left
{
motor[RDMotors] = 127;
motor[LDMotors] = -127;
untilEncoderCounts(YOUNEEDTOFINDTHEENCODERCOUNTLOL, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void PT180DR()	//Point Turn 180 Degrees Right
{
motor[RDMotors] = -127;
motor[LDMotors] = 127;
untilEncoderCounts(YOUNEEDTOFINDTHEENCODERCOUNTLOL, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}


//------------------------------------------------------------------------------------


void PT270DL()	//Point Turn 270 Degrees Left
{
motor[RDMotors] = 127;
motor[LDMotors] = -127;
untilEncoderCounts(YOUNEEDTOFINDTHEENCODERCOUNTLOL, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
void PT270DR()	//Point Turn 270 Degrees Right
{
motor[RDMotors] = -127;
motor[LDMotors] = 127;
untilEncoderCounts(YOUNEEDTOFINDTHEENCODERCOUNTLOL, LeftEncoder);
motor[RDMotors] = 0;
motor[LDMotors] = 0;
}
*/


//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------


void STAHP()
{
	motor[MGLiftMotorL] = 0;
	motor[MGLiftMotorR] = 0;
	motor[LDMotors] = 0;
	motor[RDMotors] = 0;
	motor[LSAMotor] = 0;
	motor[RSAMotor] = 0;
	motor[LLift] = 0;
	motor[RLift] = 0;
	motor[ClawMotor] = 0;
	untilEncoderCounts(238703241089713289714328970132, LeftEncoder);
}


//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------


void RECB()
{
SensorValue[LeftEncoder] = 0;
SensorValue[RightEncoder] = 0;
}


//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

task main()
{

RECB();
	PT90DR();
STAHP();

}
