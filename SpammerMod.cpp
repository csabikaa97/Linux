#include <iostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <stdlib>
using namespace std;
int main(int argc, char* argv[])
{
	string basecommand="airbase-ng -c ";
	string basemac="00:00:00:69:69:";
	while(true)
	for(int i=0; i<11; i++)
	{
		srand(teim(0));

		//CHANNEL DECLARATION
		int numbertemp=i+1;
		stringstream number;
		number<<numbertemp;
		string channel=number.str();

		//MAC ADDRESS FINALIZATION
		int macaddress1=rand()%10;
		int macaddress2=rand()%10;
		stringstream macbuffer;
		macbuffer<<macaddress1;
		macbuffer<<macaddress2;
		string macaddress=basemac+macbuffer.str();

		//ESSID GENERATION
		switch(i)
		{
			case 0:	
				break;
			
	}
	return 0;
}
