#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
using namespace std;
int main(int argc, char* argv[])
{
	string BaseBssid="00:0C:87:69:69:";

	cout<<"Argc: "<<argc<<endl;
	bool FixChannel=false;
	string Channel;
	bool FixEssid=false;
	string Essid;
	bool FixBssid=false;
	string Bssid;
	bool FixTimes=false;
	string TimesS;
	int Times=10;
	char CharBuffer;
	bool Security=false;
	string buffer;
	for(int i=0; i<argc; i++)
	{
		buffer=argv[i];
		CharBuffer=buffer[0];
		switch(CharBuffer)
		{
			case 'c':
				FixChannel=true;
				Channel=argv[i+1];
				cout<<"Channel: "<<Channel<<endl;
				break;
			case 'e':
				FixEssid=true;
				Essid=argv[i+1];
				cout<<"Essid: "<<Essid<<endl;
				break;
			case 'b':
				FixBssid=true;
				Bssid=argv[i+1];
				cout<<"Bssid: "<<Bssid<<endl;
				break;
			case 't':
				FixTimes=true;
				TimesS=argv[i+1];
				Times=atoi(TimesS.c_str());
				cout<<"Times: "<<Times<<endl;
				break;
			case 's':
				Security=true;
				break;
		}
	}
	cout<<endl<<"Argument initialization done!"<<endl;
	string BaseCommand;
	string FinalCommand;
	srand(time(0));
	int WaitTime=rand()%750+1;
	for(int i=0; i<Times; i++)
	{
		string iString;
		stringstream iToString;
		iToString<<i;
		iString=iToString.str();
		if(FixChannel!=true)
		{
			int TempChannel=rand()%11+1;
			stringstream TempChannelSS;
			TempChannelSS<<TempChannel;
			Channel=TempChannelSS.str();
		}
		if(FixBssid!=true)
		{
			int TempBssid1=rand()%10;
			int TempBssid2=rand()%10;
			stringstream TempBssidSS;
			TempBssidSS<<BaseBssid<<TempBssid1<<TempBssid2;
			Bssid=TempBssidSS.str();
		}
		if(FixEssid!=true)
		{
			int TempEssid=rand()%100000;
			stringstream TempEssidSS;
			TempEssidSS<<TempEssid;
			Essid=TempEssidSS.str();
		}
		if(i==0)
		{
			BaseCommand="airbase-ng -c "+Channel+" -e "+Essid+" -a "+Bssid+" ";
			if(Security==true)
			{
				BaseCommand=BaseCommand+"-Z 2";
			}
			BaseCommand=BaseCommand+" mon0";
			FinalCommand=BaseCommand;
		}
		else
		{
			FinalCommand=FinalCommand+" & SleepnRun-x64 \"airbase-ng -c "+Channel+" -e "+Essid+" -a "+Bssid+" ";
			if(Security==true)
			{
				FinalCommand=FinalCommand+" -Z 2";
			}
			FinalCommand=FinalCommand+" mon0\" "+iString;
		}
		usleep(WaitTime);
	}
	//FinalCommand=FinalCommand+" >> SpammerModReal.log";
	cout<<"Final command: "<<FinalCommand<<endl;
	system(FinalCommand.c_str());
	return 0;
}
