#pragma config(Motor,  port1,           LExtraBarMotor, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           LBack,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           LFront,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           LBarMotors,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           RBarMotors,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LClawMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           RClawMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RBack,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           RFront,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          RExtraBarMotor, tmotorVex393_HBridge, openLoop)


task main()
{
	motor[port6]=-73;
	motor[port7]=-73;
	wait1Msec(100);
	motor[port6]=0;
	motor[port7]=0;



}
