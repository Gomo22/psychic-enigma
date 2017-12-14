
task main()
{
SensorValue[gyroSensor] = 0;
wait1Msec(2000);

	while(sensorValue[gyroSensor] < 900) //this is a clockwise turn or a right
	{
motor[port7] = -96
motor[port6] = 96
}
motor[port7] = 15;
motor[port6] = -15;
wait1Msec(50);
motor[port7] = 0;
motor[port6] = 0;
wait1Msec(1000);

	while(sensorValue[gyroSensor] < 1800) //this is a clockwise turn or a right
	{
motor[port7] = -96
motor[port6] = 96
}
motor[port7] = 15;
motor[port6] = -15;
wait1Msec(50);
motor[port7] = 0;
motor[port6] = 0;


}
