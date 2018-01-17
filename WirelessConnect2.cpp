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
	WCinterface.open("/etc/WirelessConnect.pref");
	if(!WCinterface.is_open()) {
		move(0,0);
		printw("Preference file can't be loaded.");
		move(1,0);
		printw("Create new preference file? (Y/N): ");
		refresh();
		if(char c=getch()=='y' or c=='Y') {
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
	clear();
	move(1,30);
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
	else {
		int counter=0;
		string iwscans[100];
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
		while(true) {
			int counter2=0;
			for(int i=0; i<counter; i++) {
				move(i+2,0);
				if(current==i) {
					printw("  *");
				}
				else {
					printw("   ");
				}
				PrintStringNcurses(iwscans[i]);
				counter2=i;
			}
			refresh();
			move(counter2+3,0);
			printw("input: ");
			refresh();
			int b = getch();
			printw("         -         %d",b);
			switch(b) {
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
