#include "Tools.hpp"
#include <iostream>
#include <cstdlib>
#include <curses.h>
#include <fstream>
using namespace std;
int main() {
	initscr();
	string interface;
	fstream WCinterface;
	//opening preference file
	WCinterface.open("/etc/WirelessConnect.pref");
	if(!WCinterface.is_open()) {
		move(0,0);
		printw("Preference file can't be loaded.");
		move(1,0);
		printw("Create new preference file? (Y/N): ");
		refresh();
		if(char c=getch()=='y' or c=='Y') {
			//making new preference file
			system("touch /etc/WirelessConnect.pref");
			WCinterface.open("/etc/WirelessConnect.pref");
			move(3,0);
			printw("Enter the wireless interface to use with this app: ");
			refresh();
			interface=ReadStringFromNcurses();
			WCinterface<<interface;
			WCinterface.close();
			WCinterface.open("/etc/WirelessConnect.pref");
			string temp;
			getline(WCinterface,temp);
			if(temp==interface) {
				move(4,0);
				printw("Save succesful.\nPress any key to continue...");
				refresh();
				getch();
			}
			else {
				move(4,0);
				printw("Save unsuccessful.\nPress any key to continue...");
				refresh();
				getch();
			}
		}
		else {
			move(5,0);
			printw("Enter the wireless interface to use with this app: ");
			refresh();
			interface=ReadStringFromNcurses();
		}
		WCinterface.close();
	}
	else {
		getline(WCinterface,interface);
		WCinterface.close();
	}
	//checking interface
	string makeinterfaceonline="ifconfig "+interface+" up";
	system(makeinterfaceonline.c_str());
	clear();
	move(1,1);
	printw("interface: ");
	PrintStringNcurses(interface);
	system("rm /tmp/iw.scan");
	string command="iw "+interface+" scan | grep SSID >> /tmp/iw.scan";
	system(command.c_str());
	fstream iw;
	iw.open("/tmp/iw.scan");
	if(!iw.is_open()) {
		printw("Can't open iw scan file.");
		refresh();
		endwin();
		return 0;
	}
	//running program main part
	else {
		int counter=0;
		string iwscans[100];
		//reading file contents into variables
		for(int i=0; i<100; i++) {
			string buffer;
			getline(iw,buffer);
			if(buffer!="\0") {
				iwscans[i]=buffer;
			}
			else {
				counter=i;
				break;
			}
		}
		int current=0;
		//outputting file content;
		while(true) {
			int counter2=0;
			string formattediwnames[counter];
			for(int i=0; i<counter; i++) {
				move(i+2,0);
				string temp;
				int counter321=0;
				for(int cec=0; cec<iwscans[i].length(); cec++) {
					if(counter321==0 && iwscans[i][cec]==' ') {
						cec++;
						counter321++;
					}
					if(DoesThisContaintAnyOfThis(iwscans[i][cec],"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,*-_\\\"\'<>.: ")) {
						temp=temp+iwscans[i][cec];
					}
				}
				for(int cec=0; cec<temp.length(); cec++) {
					if(temp[cec]=='S' && temp[cec+1]=='S' && temp[cec+2]=='I' && temp[cec+3]=='D' && temp[cec+4]==':' ) {
						for(int cec2=0; cec2<5; cec2++) {
							temp[cec+cec2]='\0';
						}
					}
				}
				if(current==i) {
					printw("*\t\"");
				}
				else {
					printw(" \t\"");
				}
				PrintStringNcurses(temp);
				formattediwnames[i]=temp;
				printw("\"");
				counter2=i;
			}
			refresh();
			move(counter2+6,0);
			printw("Press enter to connect to a network.");
			move(counter2+4,0);
			printw("input: ");
			refresh();
			int b = getch();
			switch(b) {
				case 10:
					move(counter2+8,0);
					printw("Enter password for network(\"");
					PrintStringNcurses(formattediwnames[current]);
					printw("\"): ");
					refresh();
					string command1="wpa_passphrase >> "+formattediwnames[current]+".cfg";
					system(command1.c_str());
					string filename="formattediwnames[current]+".cfg";
					fstream file;
					file.open(filename.c_str());
					if(!file.is_open()) {
						printw("Couldn't open configuration file.");
						refresh();
						getch();
						endwin();
						return 0;
					}
					else {
						printw("Save successful.");
						getch();
					}
					break;
				case 66:
					if(current!=counter2)
						current++;
					break;
				case 65:
					if(current!=0)
						current=current-1;
					break;
			}
		}
	}
	endwin();
	return 0;
}
