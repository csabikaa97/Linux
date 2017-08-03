#include <iostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
	string basecommand="airbase-ng -c ";
	string basemac="00:00:00:69:69:";
	srand(time(0));
	while(true)
	for(int i=0; i<11; i++)
	{
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
		string essid;
		int bignumber=rand()%10000000;
		stringstream buffer;
		buffer<<bignumber;
		essid=buffer.str();

		//RUNNING THE SCRIPT
		string command="airbase-ng -c "+channel+" -e "+essid+" -a "+macaddress+" mon0";
		//cout<<endl<<command<<endl;
		system(command.c_str());
	}
	return 0;
}
