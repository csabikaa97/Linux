#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
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
	cout<<endl<<"Starting ADB in TCP/IP mode...";
	system("adb tcpip 5555");
	system("adb install wifinject.apk");
	cout<<endl<<"WiFI SSID: ";
	string ssid;
	cin>>ssid;
	cout<<endl<<"Security mode? ( WPA | WEP ): ";
	string security;
	cin>>security;
	string password;
	if(security=="WPA") {
		cout<<endl<<"Password: ";
		cin>>password;
	}
	string command1="adb shell am start -n com.steinwurf.adbjoinwifi/.MainActivity -e ssid "+ssid+" -e password_type "+security+" -e password "+password;
	system(command1.c_str());
	return 0;
}
