#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
	if(argc == 3) {
		cout<<endl;
		string interface=argv[1];
		string configfile=argv[2];
		fstream cfgfile;
		cfgfile.open(configfile.c_str());
		if(!cfgfile.is_open()) {
			cout<<endl<<"\tCan't open configuration file."<<endl;
			return 0;
		}
		else {
			cout<<endl<<"\tConfiguration file successfully opened.\n\n";
		}
		string interfacenamefull="/sys/class/net/"+interface+"/type";
		fstream interfacecheck;
		string command99="chmod 777 "+interfacenamefull;
		system(command99.c_str());
		interfacecheck.open(interfacenamefull.c_str());
		if(!interfacecheck.is_open()) {
			cout<<"\tSpecified interface ("<<interface<<") can't be opened.\n";
			return 0;
		}
		cout<<"Setting interface "<<interface<<" up.\n\n";
		string command1="sudo ifconfig "+interface+" up";
		system(command1.c_str());
		string command2="wpa_supplicant -D wext -B -i "+interface+" -c "+configfile;
		cout<<"\tRunning \""<<command2<<"\"...\n\n";
		system(command2.c_str());
		cout<<"\tGetting IP address...\n\n";
		system("dhclient");
		cout<<endl;
		cout<<"\tReading IP address from ifconfig...";
		cout<<endl;
		system("ifconfig | grep \"inet addr\"");
		cout<<endl<<"\tRunning ping on google.com..."<<endl;
		system("ping google.com -c 1");
		cout<<"\""<<endl;
		cout<<endl;
	}
	else {
		cout<<"\tToo few arguments."<<endl;
	}
}
