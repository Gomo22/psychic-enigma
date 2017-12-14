#pragma config(Sensor, in1,    gyroSensor,     sensorGyro)
#pragma config(Sensor, in2,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl7,  ClawEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           idek,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           MGLiftMotorR,  tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RDMotors,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           RTLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RBLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LBLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LTLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LDMotors,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           ClawMotors,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          MGLiftMotorL,  tmotorVex393_HBridge, openLoop)

task main
{

	if (vexRT[Btn7R] == 1)
	{

		/*
		motor[RTLift] = 0;
		motor[RBLift] = 0;
		motor[LBLift] = 0;
		motor[LTLift] = 0;
		motor[MGLiftMotorL] = 0;
		motor[MGLiftMotorR] = 0;
		motor[RDMotors] = 0;
		motor[LDMotors] = 0;
		wait1Msec();
		*/

		motor[RTLift] = 127;
		motor[RBLift] = 127;
		motor[LBLift] = 127;
		motor[LTLift] = 127;
		wait1Msec(1000);

		motor[RTLift] = 0;
		motor[RBLift] = 0;
		motor[LBLift] = 0;
		motor[LTLift] = 0;
		wait1Msec(50);

		motor[MGLiftMotorL] = -54;
		motor[MGLiftMotorR] = -64;
		wait1Msec(100);

		motor[MGLiftMotorL] = 0;
		motor[MGLiftMotorR] = 0;
		wait1Msec(50);

		motor[RDMotors] = -127;
		motor[LDMotors] = -127;
		wait1Msec(1500);

		motor[RDMotors] = 0;
		motor[LDMotors] = 0;
		wait1Msec(50);

		motor[MGLiftMotorL] = 117;
		motor[MGLiftMotorR] = 127;
		wait1Msec(500);

		motor[MGLiftMotorL] = 0;
		motor[MGLiftMotorR] = 0;
		wait1Msec(50);

		motor[RDMotors] = 127;
		motor[LDMotors] = 127;
		wait1Msec(1500);

		motor[RDMotors] = 0;
		motor[LDMotors] = 0;
		wait1Msec(50);

		motor[RDMotors] = 96;
		motor[LDMotors] = -64;
		wait1Msec(500);

		motor[RDMotors] = 0;
		motor[LDMotors] = 0;
		wait1Msec(50);

		motor[RDMotors] = -96;
		motor[LDMotors] = -96;
		wait1Msec(250);

		motor[MGLiftMotorL] = -86;
		motor[MGLiftMotorR] = -96;
		wait1Msec(200);

		motor[RDMotors] = 127;
		motor[LDMotors] = 127;
		motor[MGLiftMotorL] = 54;
		motor[MGLiftMotorR] = 64;
		wait1Msec(250);

		motor[RTLift] = 0;
		motor[RBLift] = 0;
		motor[LBLift] = 0;
		motor[LTLift] = 0;
		motor[MGLiftMotorL] = 0;
		motor[MGLiftMotorR] = 0;
		motor[RDMotors] = 0;
		motor[LDMotors] = 0;
		wait1Msec(500);

	}
}
