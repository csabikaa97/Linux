#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
string ssid;
string password;
string security;
int main(int argc, char* argv[]) {
	if(argc!=1) {
		ssid=argv[1];
		cout<<"SSID: "<<argv[1]<<endl;
		password=argv[2];
		cout<<"Password: "<<argv[2]<<endl;
		security=argv[3];
		cout<<"Security: "<<security<<endl;
	}
	fstream adbexistcheck;
	cout<<"Killing old ADB processes...";
	system("killall adb");
	/*adbexistcheck.open("/usr/bin/adb");
	if(!adbexistcheck.is_open()) {
		cout<<"Adb can't be opened."<<endl;
		return 0;
	}*/
	cout<<"Plug in your Android device with ADB turned on.";
	system("adb wait-for-device");
	cout<<endl<<"Allow ADB device for connection!";
	cout<<endl<<"Starting ADB in TCP/IP mode..."<<endl;
	system("adb tcpip 5555");
	system("adb wait-for-device");
	system("adb install app-debug.apk");
	if(ssid=="\0") {
		cout<<endl<<"WiFI SSID: ";
		cin>>ssid;
		cout<<endl<<"Security mode? ( WPA | WEP ): ";
		cin>>security;
		if(security=="WPA") {
			cout<<endl<<"Password: ";
			cin>>password;
		}
	}
	string command1="adb shell am start -n com.steinwurf.adbjoinwifi/.MainActivity -e ssid "+ssid+" -e password_type "+security+" -e password "+password;
	system(command1.c_str());
	usleep(20000);
	system("adb uninstall com.steinwurf.adbjoinwifi");
	system("adb shell ifconfig wlan0");
	return 0;
}
