//Clear LCD
clearLCDLine(0);
clearLCDLine(1);
//Declare count variable to keep track of our choice
int count = 0;
//Loop while center button is not pressed
while(nLCDButtons != centerButton)
{
	//Switch case that allows the user to choose from 4 different options
	switch(count){
	case 0:
		//Display first choice
		displayLCDCenteredString(0, "Autonomous 1");
		displayLCDCenteredString(1, "<     Enter    >");
		waitForPress();
		//Increment or decrement "count" based on button press
		if(nLCDButtons == leftButton)
		{
			waitForRelease();
			count = 3;
		}
		else if(nLCDButtons == rightButton)
		{
			waitForRelease();
			count++;
		}
		break;
	case 1:
		//Display second choice
		displayLCDCenteredString(0, "Autonomous 2");
		displayLCDCenteredString(1, "<     Enter    >");
		waitForPress();
		//Increment or decrement "count" based on button press
		if(nLCDButtons == leftButton)
		{
			waitForRelease();
			count--;
		}
		else if(nLCDButtons == rightButton)
		{
			waitForRelease();
			count++;
		}
		break;
	case 2:
		//Display third choice
		displayLCDCenteredString(0, "Autonomous 3");
		displayLCDCenteredString(1, "<     Enter    >");
		waitForPress();
		//Increment or decrement "count" based on button press
		if(nLCDButtons == leftButton)
		{
			waitForRelease();
			count--;
		}
		else if(nLCDButtons == rightButton)
		{
			waitForRelease();
			count++;
		}
		break;
	case 3:
		//Display fourth choice
		displayLCDCenteredString(0, "Autonomous 4");
		displayLCDCenteredString(1, "<     Enter    >");
		waitForPress();
		//Increment or decrement "count" based on button press
		if(nLCDButtons == leftButton)
		{
			waitForRelease();
			count--;  // make sure this is --+ so that when the left button is pressed it decreases the count instead of looping back around to the last auto
		}
		else if(nLCDButtons == rightButton)
		{
			waitForRelease();
			count++;  //make sure this is ++ so that when the right button is pressed it increases the count instead of looping back around to the first auto
		}
		break;
	default:
		count = 0;
		break;

	case 4: //make sure to change to 1 above the last one
		//Display fourth choice
		displayLCDCenteredString(0, "Autonomous 5"); //change to one above last so it displays the right automous number
		displayLCDCenteredString(1, "<     Enter    >");
		waitForPress();
		//Increment or decrement "count" based on button press
		if(nLCDButtons == leftButton)
		{
			waitForRelease();
			count--; // make sure this is -- so that it can decrease the count
		}
		else if(nLCDButtons == rightButton)
		{
			waitForRelease();
			count = 0; // make sure this is 0 so that it loops back around to the first automous if the right button is pressed again
		}
		break;
	default:
		count = 0;
		break;
	}
}
