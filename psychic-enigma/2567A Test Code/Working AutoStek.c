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

int count;

/*


0


*/
task main()
{
	while(true)
	{

		if(vexRT[Btn7UXmtr2] == 1)
		{

			if(count == 0 && vexRT[Btn7LXmtr2] == 0)
			{

				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				untilPotentiometerLessThan(100, ClawPot);

				wait1Msec(50);
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[ClawMotor] = -127;
				wait1Msec(250);

				//-

				motor[ClawMotor] = 0;
				wait1Msec(5);



				wait1Msec(50);
				motor[LSAMotor] = 127;
				motor[RSAMotor] = 127;
				untilPotentiometerGreaterThan(3500, ClawPot);

				motor[MGLiftMotorL] = 0;
				motor[MGLiftMotorR] = 0;
				motor[LDMotors] = 0;
				motor[RDMotors] = 0;
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[LLift] = 0;
				motor[RLift] = 0;
				motor[ClawMotor] = 0;
				wait1Msec(5);

				count++;

			}

			else if(count == 1 && vexRT[Btn7LXmtr2] == 0)
			{

				motor[ClawMotor] = 127;
				wait1Msec(250);
				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				wait1Msec(100);



				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				untilPotentiometerLessThan(2000, ClawPot);

				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				motor[ClawMotor] = 0;
				untilPotentiometerLessThan(100, ClawPot);


				wait1Msec(50);
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[ClawMotor] = -127;
				wait1Msec(250);

				motor[LSAMotor] = 127;
				motor[RSAMotor] = 127;
				untilPotentiometerGreaterThan(3000, ClawPot);

				motor[MGLiftMotorL] = 0;
				motor[MGLiftMotorR] = 0;
				motor[LDMotors] = 0;
				motor[RDMotors] = 0;
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[LLift] = 0;
				motor[RLift] = 0;
				motor[ClawMotor] = 0;
				wait1Msec(5);

				count++;

			}

			else if(count == 2 && vexRT[Btn7LXmtr2] == 0)
			{

				motor[ClawMotor] = 127;
				wait1Msec(250);
				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				wait1Msec(100);



				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				untilPotentiometerLessThan(2000, ClawPot);

				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				motor[ClawMotor] = 0;
				untilPotentiometerLessThan(100, ClawPot);


				wait1Msec(50);
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[ClawMotor] = -127;
				wait1Msec(250);

				motor[LSAMotor] = 127;
				motor[RSAMotor] = 127;
				untilPotentiometerGreaterThan(3000, ClawPot);

				motor[MGLiftMotorL] = 0;
				motor[MGLiftMotorR] = 0;
				motor[LDMotors] = 0;
				motor[RDMotors] = 0;
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[LLift] = 0;
				motor[RLift] = 0;
				motor[ClawMotor] = 0;
				wait1Msec(5);

				count++;

			}

			else if(count == 3 && vexRT[Btn7LXmtr2] == 0)
			{

				motor[ClawMotor] = 127;
				wait1Msec(250);
				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				wait1Msec(100);



				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				untilPotentiometerLessThan(2000, ClawPot);

				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				motor[ClawMotor] = 0;
				untilPotentiometerLessThan(100, ClawPot);


				wait1Msec(50);
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[ClawMotor] = -127;
				wait1Msec(250);

				motor[LSAMotor] = 127;
				motor[RSAMotor] = 127;
				untilPotentiometerGreaterThan(3000, ClawPot);

				motor[MGLiftMotorL] = 0;
				motor[MGLiftMotorR] = 0;
				motor[LDMotors] = 0;
				motor[RDMotors] = 0;
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[LLift] = 0;
				motor[RLift] = 0;
				motor[ClawMotor] = 0;
				wait1Msec(5);

				count++;

			}


			else if(count == 4 && vexRT[Btn7LXmtr2] == 0)
			{

				motor[ClawMotor] = 127;
				wait1Msec(250);
				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				wait1Msec(100);



				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				untilPotentiometerLessThan(2000, ClawPot);

				motor[LSAMotor] = -127;
				motor[RSAMotor] = -127;
				motor[ClawMotor] = 0;
				untilPotentiometerLessThan(100, ClawPot);


				wait1Msec(50);
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[ClawMotor] = -127;
				wait1Msec(250);

				motor[LSAMotor] = 127;
				motor[RSAMotor] = 127;
				untilPotentiometerGreaterThan(3000, ClawPot);

				motor[MGLiftMotorL] = 0;
				motor[MGLiftMotorR] = 0;
				motor[LDMotors] = 0;
				motor[RDMotors] = 0;
				motor[LSAMotor] = 0;
				motor[RSAMotor] = 0;
				motor[LLift] = 0;
				motor[RLift] = 0;
				motor[ClawMotor] = 0;
				wait1Msec(5);

				count++;

			}

			else
			{
				motor[port1] = 0;
			}

		}


		///////////////////////////////////////////////////////////////////////////////////////////


		else if(vexRT[Btn7RXmtr2] == 1)
		{
			count = 0;
		}

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
}
