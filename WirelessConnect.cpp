#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
	/*
		ifconfig wlp1s0 up
		wpa_supplicant -D wext -B -i wlp1s0 -c <file>
		dhclient
	*/
	if(argc == 3)
	{
		cout<<endl;
		string interface=argv[1];
		string configfile=argv[2];
		fstream cfgfile;
		cfgfile.open(configfile.c_str());
		if(!cfgfile.is_open())
		{
			cout<<endl<<"Can't open configuration file."<<endl;
			return 0;
		}
		else
		{
			cout<<endl<<"Configuration file successfully opened."<<endl;
		}
		string command1="sudo ifconfig "+interface+" up";
		system(command1.c_str());
		string command2="wpa_supplicant -D wext -B -i "+interface+" -c "+configfile;
		system(command2.c_str());
		system("dhclient");
		cout<<endl;
		system("ifconfig | grep \"inet addr\"");
		cout<<endl;
		system("ping google.com -c 1");
		cout<<endl;
		cout<<endl;
	}
	else
	{
		cout<<"Too few arguments."<<endl;
	}
}
