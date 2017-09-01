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
	//cout<<"argc: "<<argc<<endl;
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
	bool FixEssidBase=false;
	string FixEssidbase;
	string buffer;
	string buffer2;
	bool FixCharacters=false;
	string Fixcharacters;
	bool FileBasedEssid=false;
	string FileName;
	int counter2=0;
	srand(time(0));
	cout<<"Argument initialization start..."<<endl<<endl;
	for(int i=1; i<argc; i++)
	{
		cout<<"Argument: \""<<argv[i]<<"\""<<endl;
		buffer=argv[i];
		CharBuffer=buffer[0];
		switch(CharBuffer)
		{
			case 'c':
				FixChannel=true;
				Channel=argv[i+1];
				cout<<"\tChannel: "<<Channel<<endl;
				i++;
				break;
			case 'e':
				FixEssid=true;
				Essid=argv[i+1];
				cout<<"\tEssid: \""<<Essid<<"\""<<endl;
				i++;
				break;
			case 'p':
				FixCharacters=true;
				Fixcharacters=argv[i+1];
				cout<<"Prefix characters: \""<<Fixcharacters<<"\""<<endl;
				i++;
				break;
			case 'b':
				FixBssid=true;
				Bssid=argv[i+1];
				cout<<"\tBssid: "<<Bssid<<endl;
				i++;
				break;
			case 't':
				FixTimes=true;
				TimesS=argv[i+1];
				Times=atoi(TimesS.c_str());
				cout<<"\tTimes: "<<Times<<endl;
				i++;
				break;
			case 'l':
				FixEssidBase=true;
				FixEssidbase=argv[i+1];
				cout<<"\tESSID base: \""<<FixEssidbase<<"\""<<endl;
				i++;
				break;
			case 'f':
				FileBasedEssid=true;
				FileName=argv[i+1];
				cout<<"ESSID File name: "<<FileName<<endl;
				break;
		}
		if(buffer[0]=='s' && Security!=true)
		{
			cout<<"\tSecurity: true"<<endl;
			Security=true;
		}
	}
	cout<<endl<<"Argument initialization done!"<<endl<<endl;
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
			if(FixEssidBase==true)
			{
				int TempEssid=rand()%1000000;
				stringstream TempEssidSS;
				TempEssidSS.str("");
				TempEssidSS<<TempEssid;
				Essid=FixEssidbase+"-"+TempEssidSS.str();
				cout<<"Essid: "<<Essid<<endl;
			}
			if(FixCharacters==true)
			{
				Essid="\0";
				buffer2=Fixcharacters;
				bool FREE[Fixcharacters.length()];
				for(int c=0; c<Fixcharacters.length(); c++)
				{
					FREE[c]=true;
				}
				for(int b=0; b<Fixcharacters.length(); b++)
				{
					while(true)
					{
						int buffer4=Fixcharacters.length()-b;
						int buffer3=rand()%buffer4;
						if(FREE[buffer3]==true)
						{
							Essid=Essid+buffer2[buffer3];
							break;
						}
					}
				}
				cout<<"Essid: "<<Essid<<endl;
			}
			if(FileBasedEssid==true)
			{
				int counter1=0;
				string buffer5;
				fstream EssidFile;
				EssidFile.open(FileName.c_str());
				while(getline(EssidFile,buffer5))
				{
					if(counter1==counter2)
					{
						Essid=buffer5;
						if(buffer5=="")
						{
							counter2=0;
						}
						break;
					}
					counter1++;
				}
				counter2++;
				cout<<"File Essid["<<counter2<<"]: "<<buffer5<<endl;
				Essid=buffer5;
			}
		}
		if(i==0)
		{
			BaseCommand="airbase-ng -c "+Channel+" -e \""+Essid+"\" -a "+Bssid+" ";
			if(Security==true)
			{
				BaseCommand=BaseCommand+"-Z 2 ";
			}
			BaseCommand=BaseCommand+"mon0";
			FinalCommand=BaseCommand;
		}
		else
		{
			FinalCommand=FinalCommand+" & SleepnRun \"airbase-ng -c "+Channel+" -e \\\""+Essid+"\\\" -a "+Bssid+" ";
			if(Security==true)
			{
				FinalCommand=FinalCommand+"-Z 2 ";
			}
			else
			FinalCommand=FinalCommand+"mon0\" "+iString;
		}
		usleep(WaitTime);
	}
	//FinalCommand=FinalCommand+" >> SpammerModReal.log";
	cout<<"Final command: "<<FinalCommand<<endl;
	system(FinalCommand.c_str());
	return 0;
}
