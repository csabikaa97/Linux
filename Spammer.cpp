#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
using namespace std;
bool CheckFileAvailablity(string filename)
{
	fstream check;
	check.open("/tmp/tmpfile");
	if(check.is_open())
	{
		check.close();
		system("rm /tmp/tmpfile");
	}
	string tempcommand1="chmod 777 "+filename;
	string tempcommand2="ls -l \""+filename+"\" >> /tmp/tmpfile";
	system(tempcommand1.c_str());
	system(tempcommand2.c_str());
	fstream temporary;
	temporary.open("/tmp/tmpfile");
	if(temporary.is_open())
	{
		string tempbuffer;
		getline(temporary,tempbuffer);
		if(tempbuffer[0]=='l' && tempbuffer[1]=='r' && tempbuffer[2]=='w' && tempbuffer[3]=='x')
		{
			//cout<<endl<<"Tempbuffer: "<<tempbuffer<<endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
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
	string Interface;
	bool FixInterface;
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
			case 'i':
				FixInterface=true;
				Interface=argv[i+1];
				cout<<"\tInterface: "<<Interface<<endl;
				i++;
				break;
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
				cout<<"\tPrefix characters: \""<<Fixcharacters<<"\""<<endl;
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
				Times=atoi (TimesS.c_str());
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
				cout<<"\tESSID File name: "<<FileName<<endl;
				break;
		}
		if(buffer[0]=='s' && Security!=true)
		{
			cout<<"\tSecurity: true"<<endl;
			Security=true;
		}
	}
	cout<<endl<<"Argument initialization done!"<<endl<<endl;
	cout<<endl<<"Checking wireless devices..."<<endl;
	/*fstream WirelessCheck;
	WirelessCheck.open("/tmp/WirelessDevices");
	if(WirelessCheck.is_open())
	{
		WirelessCheck.close();
		system("rm /tmp/WirelessDvices");
		cout<<endl<<"Config file already exist."<<endl;
	}
	cout<<endl<<"Generating config file."<<endl;
	system("ifconfig | grep mon0 >> /tmp/WirelessDevices");
	system("chmod 777 /tmp/WirelessDevices");
	fstream WirelessDevices;
	WirelessDevices.open("/tmp/WirelessDevices");
	if(!WirelessDevices.is_open());
	{
		cout<<endl<<"Can't open wiresless configuration log."<<endl;
		return 0;
	}
	if(WirelessDevices.is_open())
	{
		string buffer6;
		getline(WirelessDevices,buffer6);
		if(buffer6=="")
		{
			cout<<endl<<"Empty file. Buffer6: \""<<buffer6<<"\""<<endl;
		}
		else
		{
			cout<<endl<<"File not empty. Buffer6: \""<<buffer6<<"\""<<endl;
		}
		return 0;
	}*/
	if(FixInterface==false)
	{
		if(CheckFileAvailablity("/sys/class/net/wlan0"))
		{
			Interface="wlan0";
			FixInterface=true;
			cout<<endl<<"Interface wlan0 found, set as deault interface."<<endl;
		}
		if(CheckFileAvailablity("/sys/class/net/wlp1s0"))
		{
			Interface="wlp1s0";
			FixInterface=true;
			cout<<endl<<"Interface wlp1s0 found, set as default interface."<<endl;
		}
	}
	system("ls -l /sys/class/net/mon0 >> mon0type");
	fstream WirelessCheck;
	WirelessCheck.open("mon0type");
	string buffer7;
	getline(WirelessCheck,buffer7);
	//cout<<endl<<"mon0 up: "<<WirelessCheck.is_open()<<endl<<buffer7<<endl;
	if(buffer7[0]=='l' && buffer7[1]=='r' && buffer7[2]=='w' && buffer7[3]=='x')
	{
		cout<<endl<<"mon0 interface is up!"<<endl;
	}
	else
	{
		cout<<endl<<"mon0 interface is down!"<<endl;
		if(FixInterface==true)
		{
			string command3="ls -l /sys/class/net/"+Interface+" >> "+Interface+"check";
			system(command3.c_str());
			fstream InterfaceCheck2;
			string Interfacecheck=Interface+"check";
			InterfaceCheck2.open(Interfacecheck.c_str());
			string buffer8;
			getline(InterfaceCheck2,buffer8);
			if(buffer8[0]=='l' && buffer8[1]=='r' && buffer8[2]=='w' && buffer8[3]=='x')
			{
				cout<<endl<<"Interface "<<Interface<<" is up!"<<endl;
			}
			else
			{
				cout<<endl<<"Interface "<<Interface<<" is not available."<<endl<<"Check interface argument for typos and check if interface is up."<<endl;
				return 0;
			}
			cout<<endl<<"Running airmon-ng on interface \""<<Interface<<"\"."<<endl;
			system("airmon-ng check kill");
			string commando="airmon-ng start "+Interface;
			system(commando.c_str());
			string buffer9="rm "+Interface+"check";
			system(buffer9.c_str());
		}
		else
		{
			cout<<endl<<"Can't set monitor mode as wi-fi interface is unknown."<<endl<<"Set interface with the \"i <interface>\" argument."<<endl;
			return 0;
		}
	}
	//cout<<endl<<"buffer7: "<<buffer07<<endl;
	system("rm mon0type");
	cout<<endl<<"Checking wireless devices done."<<endl;
	string BaseCommand;
	string FinalCommand;
	srand(time(0));
	int WaitTime=rand()%750+1;
	cout<<endl<<"Generating ESSID names..."<<endl;
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
			if(FixEssid!=true && FileBasedEssid!=true && FixCharacters!=true && FixEssidBase!=true)
			{
				int tempessidint=rand()%1000000;
				stringstream TempEssidSS;
				TempEssidSS<<tempessidint;
				Essid=TempEssidSS.str();
				cout<<"Random ESSID: "<<Essid<<endl;
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
	cout<<endl<<"Generating ESSID names done."<<endl;
	cout<<endl<<"Running airbase-ng..."<<endl;
	//FinalCommand=FinalCommand+" >> SpammerModReal.log";
	//cout<<"Final command: "<<FinalCommand<<endl;
	system(FinalCommand.c_str());
	return 0;
}
