#ifndef auton
#define auton

#include "Movements.h"


void left20()
{
		////left 20
			SAback=true;
			SApostion=1700;
			startTask(MoveSA);
			in=true;
			lifttime=650;
			startTask(MG);
			while(SAmoving) wait1Msec(10);
			wait1Msec(750);
			dist=1350;
			startTask(drive);
			while(driving) wait1Msec(10);
			while(lifting) wait1Msec(10);
			in=false;
			lifttime=100;
			startTask(MG);
			/////step 2
			in=false;
			lifttime=700;
			startTask(MG);
			while(lifting) wait1Msec(10);
			SAback=false;
			SApostion=1700;
			startTask(MoveSA);
			while(SAmoving) wait1Msec(10);
			dist = -1050;
			startTask(drive);
			suck= false;
			sucktime=1000;
			startTask(claw);
			while(lifting) wait1Msec(10);
			while(driving) wait1Msec(10);
			while(grabbing) wait1Msec(10);
			///////STEP 3//////////
			turncount=380;
			startTask(rotate);
			while(driving) wait1Msec(10);
			//////////STEP 4////////////
			dist=350;
			startTask(drive);
			while(driving) wait1Msec(10);
			turncount=550;
			startTask(rotate);
			while(driving) wait1Msec(10);
			dist=650;
			startTask(drive);
			while(driving) wait1Msec(10);
			in=true;
			lifttime=750;
			suck= true;
			sucktime=1500;
			startTask(claw);
			SAback=true;
			SApostion=1500;
			startTask(MoveSA);
			in=true;
			lifttime=900;
			startTask(MG);
			while(lifting) wait1Msec(10);
			while(SAmoving) wait1Msec(10);
			in=false;
			lifttime=150;
			startTask(MG);
			while(lifting) wait1Msec(10);
			dist=50;
			startTask(drive);
			while(driving) wait1Msec(10);
			in=false;
			lifttime=250;
			startTask(MG);
			while(lifting) wait1Msec(10);
			dist=-500;
			startTask(drive);
			while(driving) wait1Msec(10);
}

void Right20()
{
	/////right side
				//Swings SA back, Deploys  MG out ,drives till MG(1350), retracts MG with MG
				SAback = true;
				SApostion = 1000;
				startTask(MoveSA);
				in=true;
				lifttime=650;
				startTask(MG);
				while(SAmoving) wait1Msec(10);
				wait1Msec(750);
				dist=1350;
				startTask(drive);
				while(driving) wait1Msec(10);
				while(lifting) wait1Msec(10);
				in=false;
				lifttime=700;
				startTask(MG);
				while(lifting) wait1Msec(10);

				////Swings SA Forward puts cone on MG, Releases Cone, Drives back to white line(-1150)
				SAback=false;
				SApostion=1700;
				startTask(MoveSA);
				while(SAmoving) wait1Msec(10);
				dist = -1150;
				startTask(drive);
				suck= false;
				sucktime=1500;
				startTask(claw);
				while(lifting) wait1Msec(10);
				while(driving) wait1Msec(10);
				while(grabbing) wait1Msec(10);

				///rotats till parallel with 10 pt bar
				turncount=-500;
				startTask(rotate);
				while(driving) wait1Msec(10);

				///Drives forward till Stationary goal, Turns till perpendicular with 10 pt bar,
				dist=500;
				startTask(drive);
				while(driving) wait1Msec(10);
				turncount=-200;
				startTask(rotate);
				while(driving) wait1Msec(10);
				////////Drives forward over 10pt bar, deploys MG, DRives forward then back
				dist=650;
				startTask(drive);
				while(driving) wait1Msec(10);
				in=true;
				lifttime=750;
				suck= false;
				sucktime=1500;
				startTask(claw);
				SAback=true;
				SApostion=1500;
				startTask(MoveSA);
				in=true;
				lifttime=900;
				startTask(MG);
				while(lifting) wait1Msec(10);
				while(SAmoving) wait1Msec(10);
				in=false;
				lifttime=150;
				startTask(MG);
				while(lifting) wait1Msec(10);
				dist=100;
				startTask(drive);
				while(driving) wait1Msec(10);
				in=true;
				lifttime=100;
				startTask(MG);
				while(lifting) wait1Msec(10);
				dist=-500;
				startTask(drive);
				while(driving) wait1Msec(10);
}
//////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////

void left10()
 {
/////right side
			//Swings SA back, Deploys  MG out ,drives till MG(1350), retracts MG with MG
			SAback = true;
			SApostion = 1000;
			startTask(MoveSA);
			in=true;
			lifttime=650;				startTask(MG);
			while(SAmoving) wait1Msec(10);
			wait1Msec(750);
			dist=1350;
			startTask(drive);
			while(driving) wait1Msec(10);
			while(lifting) wait1Msec(10);
			in=false;
			lifttime=700;
			startTask(MG);
			while(lifting) wait1Msec(10);

			////Swings SA Forward puts cone on MG, Releases Cone, Drives back to white line(-1150)
			SAback=false;
			SApostion=1700;
			startTask(MoveSA);
			while(SAmoving) wait1Msec(10);
			dist = -1150;
			startTask(drive);
			suck= true;
			sucktime=500;
			startTask(claw);
			while(lifting) wait1Msec(10);
			while(driving) wait1Msec(10);
			while(grabbing) wait1Msec(10);

			///rotats till parallel with 10 pt bar
			turncount=800;
			startTask(rotate);
			while(driving) wait1Msec(10);

			////////Drives forward over 10pt bar, deploys MG, DRives forward then back
			suck= true;
			sucktime=3000;
			startTask(claw);
			SAback=true;
			SApostion=1500;
			startTask(MoveSA);
			in=true;
			lifttime=900;
			startTask(MG);
			while(lifting) wait1Msec(10);
			in=true;
			lifttime=200;
			startTask(MG);
			while(lifting) wait1Msec(10);
			dist=-500;
			startTask(drive);
			while(driving) wait1Msec(10);
			motor[RDMotors]=0;
			motor[LDMotors]=0;
}
//////////////////////////////////
/////////////////////////////////
	//////////////////////////////
	//////////////////////////
	///////////////////////////


void right10()
{
/////right side
			//Swings SA back, Deploys  MG out ,drives till MG(1350), retracts MG with MG
			SAback = true;
			SApostion = 1000;
			startTask(MoveSA);
			in=true;
			lifttime=650;
			startTask(MG);
			while(SAmoving) wait1Msec(10);
			wait1Msec(750);
			dist=1350;
			startTask(drive);
			while(driving) wait1Msec(10);
			while(lifting) wait1Msec(10);
			in=false;
			lifttime=700;
			startTask(MG);
			while(lifting) wait1Msec(10);

			////Swings SA Forward puts cone on MG, Releases Cone, Drives back to white line(-1150)
			SAback=false;
			SApostion=1700;
			startTask(MoveSA);
			while(SAmoving) wait1Msec(10);
			dist = -1050;
			startTask(drive);
			suck= false;
			sucktime=1500;
			startTask(claw);
			while(lifting) wait1Msec(10);
			while(driving) wait1Msec(10);
			while(grabbing) wait1Msec(10);

			///rotats till parallel with 10 pt bar
			turncount=-800;
			startTask(rotate);
			while(driving) wait1Msec(10);

			////////Drives forward over 10pt bar, deploys MG, DRives forward then back
			suck= false;
			sucktime=1500;
			startTask(claw);
			SAback=true;
			SApostion=1500;
			startTask(MoveSA);
			in=true;
			lifttime=900;
			startTask(MG);
			while(lifting) wait1Msec(10);
			dist=-500;
			startTask(drive);
			while(driving) wait1Msec(10);
			motor[RDMotors]=0;
			motor[LDMotors]=0;
}
///////////////////////////////////////
	//////////////////////////////////////////////
	/////////////////////////////////////////
	///////////////////////////////
	///////////////////////////////////
#endif
