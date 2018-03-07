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
task main()
{

	while(SensorValue[LeftEncoder] > -1150)
	{
			motor[RSAMotor]= -127;
motor[LSAMotor]= -127;
wait1Msec(100);
motor[MGLiftMotorL]=70;
motor[MGLiftMotorR]=70;
motor[RDMotors]= 127;
motor[LDMotors]=127;
}
motor[MGLiftMotorL]=-70;
motor[MGLiftMotorR]=-70;
wait1Msec(600)
SensorValue[LeftEncoder]=0;
while(SensorValue[LeftEncoder]<1050)
{
		motor[RSAMotor]= 127;
motor[LSAMotor]= 127;
wait1Msec(100);

motor[RDMotors]= -127;
motor[LDMotors]=-127;
}
SensorValue[LeftEncoder]=0;

while(SensorValue[LeftEncoder]>-350)
{
motor[RDMotors]=-64
motor[LDMotors]=64
}
SensorValue[LeftEncoder]=0;
while(SensorValue[LeftEncoder]>-360)
{
motor[ClawMotor]=64;
motor[RSAMotor]=-127;
motor[LSAMotor]=-127;
}
SensorValue[LeftEncoder]=0;
while(SensorValue[LeftEncoder]>-100)
{
motor[RDMotors]=127
motor[LDMotors]=127
}
motor[MGLiftMotorL]=127;
motor[MGLiftMotorR]=127;
wait1Msec(750);
SensorValue[LeftEncoder]=0;
while(SensorValue[LeftEncoder]<550)
{
motor[RDMotors]=-127
motor[LDMotors]=-127
}
}
