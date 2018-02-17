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



task main
{
	motor[LSAMotor] = -127;
	motor[RSAMotor] = -127; //Extends Swing Arm
	wait1Msec(100);

	//-

	motor[MGLiftMotorL] = 127; // extends mobile goal lift
	motor[MGLiftMotorR] = 117;
	wait1Msec(850);

	//-

	motor[LSAMotor] = -15;
	motor[RSAMotor] = -15; //Extends Swing Arm
	wait1Msec(500);
	motor[MGLiftMotorL] = 0;  // stops mobile goal
	motor[MGLiftMotorR] = 0;
	wait1Msec(50);

	//-

	motor[LDMotors] = 127; //move forward till swing arm is 45 degrees
	motor[RDMotors] = 127;
	untilEncoderCounts(1350, LeftEncoder);

	//-

	wait1Msec(10);
	motor[LDMotors] = 0;
	motor[RDMotors] = 0;

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[MGLiftMotorL] = -96;
	motor[MGLiftMotorR] = -96;
	wait1Msec(2500);
	motor[MGLiftMotorL] = 0;
	motor[MGLiftMotorR] = 0;

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = 30; //move forward till swing arm is 45 degrees
	motor[RDMotors] = 30;

	//-

	wait1Msec(10);
	motor[LDMotors] = 0;
	motor[RDMotors] = 0;

	//-

	motor[LSAMotor] = 127;
	motor[RSAMotor] = 127; //Extends Swing Arm
	wait1Msec(500);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;
	wait1Msec(50);

	//-

	motor[LDMotors] = -127;
	motor[RDMotors] = -127;
	untilEncoderCounts(-750, LeftEncoder);

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = 127;
	motor[RDMotors] = -127;
	untilEncoderCounts(525, LeftEncoder);
	wait1Msec(50);

	motor[LDMotors] = -15;
	motor[RDMotors] = 15;
	wait1Msec(5);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = 127;
	motor[RDMotors] = 127;
	untilEncoderCounts(350, LeftEncoder);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = 0;
	motor[RDMotors] = 0;
	motor[LSAMotor] = -127;
	motor[RSAMotor] = -127;
	wait1Msec(500);

	//-

	motor[LSAMotor] = 0;
	motor[RSAMotor] = 0;
	wait1Msec(5);

	//-

	motor[LDMotors] = 127;
	motor[RDMotors] = -64;
	wait1Msec(750);

	//-

	motor[LDMotors] = 127;
	motor[RDMotors] = 127;
	wait1Msec(550);

	//-

	motor[LDMotors] = 0;
	motor[RDMotors] = 0;
	motor[MGLiftMotorL] = 127;
	motor[MGLiftMotorR] = 127;
	wait1Msec(1200);

	//-

	motor[LDMotors] = -127;
	motor[RDMotors] = -127;
	wait1Msec(599);

	//-

	motor[MGLiftMotorL] = -127;
	motor[MGLiftMotorR] = -127;
	wait1Msec(500);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = -96;
	motor[RDMotors] = 127;
	untilEncoderCounts(-500, LeftEncoder);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = 127;
	motor[RDMotors] = 127;
	untilEncoderCounts(500, LeftEncoder);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[MGLiftMotorR] = 127;
	motor[MGLiftMotorL] = 127;
	wait1Msec(750);

	//-

	motor[MGLiftMotorR] = 0;
	motor[MGLiftMotorL] = 0;
	motor[LDMotors] = 127;
	motor[RDMotors] = 127;
	untilEncoderCounts(500, LeftEncoder);

	//-

	motor[MGLiftMotorR] = -127;
	motor[MGLiftMotorL] = -127;
	wait1Msec(1200);

	//-

	motor[MGLiftMotorR] = 0;
	motor[MGLiftMotorL] = 0;
	wait1Msec(5);

	//-

	motor[RSAMotor] = 127;
	motor[LSAMotor] = 127;
	wait1Msec(200);

	//-

	motor[RSAMotor] = 0;
	motor[LSAMotor] = 0;
	wait1Msec(5);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = -127;
	motor[RDMotors] = 127;
	untilEncoderCounts(-500, LeftEncoder);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = 127;
	motor[RDMotors] = 127;
	untilEncoderCounts(200, LeftEncoder);

	//-

	motor[RSAMotor] = -127;
	motor[LSAMotor] = -127;
	wait1Msec(250);

	//-

	motor[RSAMotor] = -15;
	motor[LSAMotor] = -15;
	motor[MGLiftMotorL] = 127;
	motor[MGLiftMotorR] = 127;
	wait1Msec(750);

	//-

	motor[MGLiftMotorL] = 0;
	motor[MGLiftMotorR] = 0;
	wait1Msec(5);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = -127;
	motor[RDMotors] = -127;
	untilEncoderCounts(-750, LeftEncoder);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = 127;
	motor[RDMotors] = -96;
	untilEncoderCounts(500, LeftEncoder);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[MGLiftMotorL] = 127;
	motor[MGLiftMotorR] = 127;
	motor[LDMotors] = 127;
	motor[RDMotors] = 127;
	untilEncoderCounts(200, LeftEncoder);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[MGLiftMotorL] = 0;
	motor[MGLiftMotorR] = 0;
	motor[LDMotors] = 127;
	motor[RDMotors] = 127;
	untilEncoderCounts(300, LeftEncoder);

	//-

	motor[MGLiftMotorL] = -127;
	motor[MGLiftMotorR] = -127;
	wait1Msec(750);

	//-

	motor[MGLiftMotorL] = 0;
	motor[MGLiftMotorR] = 0;
	motor[LSAMotor] = 127;
	motor[RSAMotor] = 127;
	wait1Msec(50);

	//-

	motor[LSAMotor] = 0;
	motor[RSAMotor] = 0;
	wait1Msec(5);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = 127;
	motor[RDMotors] = -127;
	untilEncoderCounts(500, LeftEncoder);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = 127;
	motor[RDMotors] = 127;
	untilEncoderCounts(200, LeftEncoder);

	//-

	motor[LSAMotor] = -127;
	motor[RSAMotor] = -127;
	wait1Msec(200);

	//-

	motor[MGLiftMotorL] = 127;
	motor[MGLiftMotorR] = 127;
	motor[LSAMotor] = -15;
	motor[RSAMotor] = -15;
	wait1Msec(750);

	//-

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	//-

	motor[LDMotors] = -127;
	motor[RDMotors] = -127;
	motor[MGLiftMotorL] = 0;
	motor[MGLiftMotorR] = 0;
	untilEncoderCounts(-300, LeftEncoder);

	//-

	motor[MGLiftMotorL] = 0;
	motor[MGLiftMotorR] = 0;
	motor[LDMotors] = 0;
	motor[RDMotors] = 0;
	motor[LSAMotor] = 0;
	motor[RSAMotor] = 0;
	motor[LLift] = 0;
	motor[RLift] = 0;
	motor[ClawMotor] = 0;
}
