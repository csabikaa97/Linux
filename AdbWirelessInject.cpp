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
		cout<<"SSID: \t\t"<<argv[1]<<endl;
		password=argv[2];
		cout<<"Password: \t"<<argv[2]<<endl;
		security=argv[3];
		cout<<"Security: \t"<<security<<endl;
	}
	fstream adbexistcheck;
	cout<<"Killing old ADB processes..."<<endl;
	system("killall adb");
	adbexistcheck.open("/usr/bin/adb");
	if(!adbexistcheck.is_open()) {
		cout<<"Adb can't be opened."<<endl;
		return 0;
	}
	adbexistcheck.close();
	fstream apkexistcheck;
	apkexistcheck.open("app-debug.apk");
	if(!apkexistcheck.is_open()) {
		cout<<"Apk file can't be opened."<<endl;
		return 0;
	}
	apkexistcheck.close();
	system("adb start-server");
	cout<<"Plug in your Android device with ADB turned on."<<endl;
	system("adb wait-for-device");
	cout<<endl<<"Starting ADB in TCP/IP mode..."<<endl;
	system("adb tcpip 5555");
	cout<<"Waiting for device to reconnect..."<<endl;
	usleep(2000000);
	system("adb wait-for-device");
	system("adb start-server");
	cout<<"Installing app..."<<endl;
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
	cout<<"Running WiFi network join script..."<<endl;
	string command1="adb shell am start -n com.steinwurf.adbjoinwifi/.MainActivity -e ssid "+ssid+" -e password_type "+security+" -e password "+password;
	system(command1.c_str());
	cout<<"Waiting for device to finish joining the network..."<<endl;
	usleep(5000000);
	cout<<"Uninstalling app..."<<endl;
	system("adb uninstall com.steinwurf.adbjoinwifi");
	cout<<"Reading device IP from ifconfig..."<<endl;
	system("adb shell ifconfig wlan0");
	cout<<"Connections for ADB are allowed to the device over network."<<endl;
	return 0;
}
