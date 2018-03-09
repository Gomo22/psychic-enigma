#ifndef auton
#define auton

#include "Movements.h"

task main()
{
	SApostion = -50;
	startTask(MoveSA);
	while(SAmoving) wait1Msec(10);
	dist=1250;
	startTask(drive);
	SApostion = -220;
	startTask(MoveSA);
	in=false;
	lifttime=750;
	startTask(MG);
	while(driving) wait1Msec(10);
	while(lifting) wait1Msec(10);
	while(SAmoving) wait1Msec(10);
	/////step 2
	in=true;
	lifttime=750;
	startTask(MG);
	while(lifting) wait1Msec(10);
	dist = -1050;
	startTask(drive);
	SApostion=270;
	startTask(MoveSA);
	suck= false;
	sucktime=500;
	startTask(claw);
	while(lifting) wait1Msec(10);
	while(driving) wait1Msec(10);
	while(grabbing) wait1Msec(10);
	///////STEP 3//////////
	turncount=720;
	startTask(rotate);
	while(driving) wait1Msec(10);
	//////////STEP 4////////////
	dist=360;
	startTask(drive);
	while(driving) wait1Msec(10);
	turncount=360;
	startTask(rotate);
	while(driving) wait1Msec(10);
	in=false;
	lifttime=750;
	startTask(MG);
	dist=-1000;
	startTask(drive);
	while(driving) wait1Msec(10);



	SApostion = -50;
	startTask(MoveSA);
	while(SAmoving) wait1Msec(10);
	dist=1250;
	startTask(drive);
	SApostion = -220;
	startTask(MoveSA);
	in=false;
	lifttime=750;
	startTask(MG);
	while(driving) wait1Msec(10);
	while(lifting) wait1Msec(10);
	while(SAmoving) wait1Msec(10);
	/////step 2
	in=true;
	lifttime=750;
	startTask(MG);
	while(lifting) wait1Msec(10);
	dist = -1050;
	startTask(drive);
	SApostion=270;
	startTask(MoveSA);
	suck= false;
	sucktime=500;
	startTask(claw);
	while(lifting) wait1Msec(10);
	while(driving) wait1Msec(10);
	while(grabbing) wait1Msec(10);
	///////STEP 3//////////
	turncount=-720;
	startTask(rotate);
	while(driving) wait1Msec(10);
	//////////STEP 4////////////
	dist=360;
	startTask(drive);
	while(driving) wait1Msec(10);
	turncount=-360;
	startTask(rotate);
	while(driving) wait1Msec(10);
	in=false;
	lifttime=750;
	startTask(MG);
	dist=-1000;
	startTask(drive);
	while(driving) wait1Msec(10);

//////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////


SApostion = -50;
	startTask(MoveSA);
	while(SAmoving) wait1Msec(10);
	dist=1250;
	startTask(drive);
	SApostion = -220;
	startTask(MoveSA);
	in=false;
	lifttime=750;
	startTask(MG);
	while(driving) wait1Msec(10);
	while(lifting) wait1Msec(10);
	while(SAmoving) wait1Msec(10);
	/////step 2
	in=true;
	lifttime=750;
	startTask(MG);
	while(lifting) wait1Msec(10);
	dist = -1050;
	startTask(drive);
	SApostion=270;
	startTask(MoveSA);
	suck= false;
	sucktime=500;
	startTask(claw);
	while(lifting) wait1Msec(10);
	while(driving) wait1Msec(10);
	while(grabbing) wait1Msec(10);
	///////STEP 3//////////
	turncount=720;
	startTask(rotate);
	while(driving) wait1Msec(10);
	//////////STEP 4////////////
	dist=360;
	startTask (drive);
	while(driving) wait1Msec(10);
	turncount=360;
	startTask(rotate);
	while(driving) wait1Msec(10);
	dist=720;
	startTask(drive);
	while(driving) wait1Msec(10);
	in=false;
	lifttime=750;
	startTask(MG);
	dist=-1000;
	startTask(drive);
	while(driving) wait1Msec(10);
//////////////////////////////////
/////////////////////////////////
	//////////////////////////////
	//////////////////////////
	///////////////////////////



	SApostion = -50;
	startTask(drive);
	while(SAmoving) wait1Msec(10);
	dist=1250;
	startTask(drive);
	SApostion = -220;
	startTask(MoveSA);
	in=false;
	lifttime=750;
	startTask(MG);
	while(driving) wait1Msec(10);
	while(lifting) wait1Msec(10);
	while(SAmoving) wait1Msec(10);
	/////step 2
	in=true;
	lifttime=750;
	startTask(MG);
	while(lifting) wait1Msec(10);
	dist = -1050;
	startTask(drive);
	SApostion=270;
	startTask(MoveSA);
	suck= false;
	sucktime=500;
	startTask(claw);
	while(lifting) wait1Msec(10);
	while(driving) wait1Msec(10);
	while(grabbing) wait1Msec(10);
	///////STEP 3//////////
	turncount=-720;
	startTask(rotate);
	while(driving) wait1Msec(10);
	//////////STEP 4////////////
	dist=360;
	startTask(drive);
	while(driving) wait1Msec(10);
	turncount=-360;
	startTask(rotate);
	while(driving) wait1Msec(10);
	dist=720;
	startTask(drive);
	while(driving) wait1Msec(10);
	in=false;
	lifttime=750;
	startTask(MG);
	dist=-1000;
	startTask(drive);
	while(driving) wait1Msec(10);
///////////////////////////////////////
	//////////////////////////////////////////////
	/////////////////////////////////////////
	///////////////////////////////
	///////////////////////////////////



SApostion = -50;
	startTask(MoveSA);
	while(SAmoving) wait1Msec(10);
	dist=1250;
	startTask(drive);
	SApostion = -220;
	startTask(MoveSA);
	in=false;
	lifttime=750;
	startTask(MG);
	while(driving) wait1Msec(10);
	while(lifting) wait1Msec(10);
	while(SAmoving) wait1Msec(10);
	/////step 2
	in=true;
	lifttime=750;
	startTask(MG);
	while(lifting) wait1Msec(10);
	dist = -1050;
	startTask(drive);
	SApostion=270;
	startTask(MoveSA);
	suck= false;
	sucktime=500;
	startTask(claw);
	while(lifting) wait1Msec(10);
	while(driving) wait1Msec(10);
	while(grabbing) wait1Msec(10);
	///////STEP 3//////////
	turncount=720;
	startTask(rotate);
	while(driving) wait1Msec(10);
	//////////STEP 4////////////
	dist=360;
	startTask(drive);
	while(driving) wait1Msec(10);
	turncount=360;
	startTask(rotate);
	while(driving) wait1Msec(10);
	in=false;
	lifttime=750;
	startTask(MG);
	dist=-1000;
	startTask(drive);
	while(driving) wait1Msec(10);



}


#endif
