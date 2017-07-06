#include <iostream>
#include <cstdlib>
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
		string interface=argv[1];
		string configfile=argv[2];
		string command1="sudo ifconfig "+interface+" up";
		cout<<command1<<endl;
		system(command1.c_str());
		string command2="wpa_supplicant -D wext -B -i "+interface+" -c "+configfile;
		cout<<command2<<endl;
		system(command2.c_str());
		system("dhclient");
	}
	else
	{
		cout<<"Too few arguments."<<endl;
	}
}
