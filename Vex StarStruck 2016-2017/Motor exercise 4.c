#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl10, redLED,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, yellowLED,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, greenLED,       sensorLEDtoVCC)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Project Title: motor exercise 1
Team Members:
Date:
Section:


Task Description:

Psuedocode:
*/

task main()
{
	startMotor(2, 127);
	wait(6);
	stopMotor(2);
	wait(3);
	startMotor(3, 127);
	wait(3);
	stopMotor(3);


}
