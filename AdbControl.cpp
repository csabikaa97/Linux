#include <iostream>
#include <curses.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <string>
using namespace std;
bool isnumber(char a) {
	if(a=='0' || a=='1' || a=='2' or a=='3' or a=='4' or a=='5' or a=='6' or a=='7' or a=='8' or a=='9') {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int x;
	int y;
    /*fstream adbfilecheck;
    adbfilecheck.open("/usr/bin/adb");
    if(!adbfilecheck.is_open()) {
        printw("Couldn't open ADB.");
	refresh();
	endwin();
	return 0;
    }
	adbfilecheck.close();
    */
	initscr();
    move(5,0);
    printw("P - Power");
    move(6,0);
    printw("H - Home");
    move(7,0);
    printw("B - Back");
    move(8,0);
    printw("W,A,S,D - Swipe eventek");
    move(9,0);
    printw("Nyilak - Dpad emu");
    move(10,0);
    printw("Enter");
    move(11,0);
    printw("Num (-) - Hang le");
    move(12,0);
    printw("Num (+) - Hang fel");
    refresh();
    while(true) {
	move(0,0);
        printw("Input: ");
	int input = getch();
	move(1,10);
	printw("    -    %d",input);
	printw("      ");
        if(input==81) {
            endwin();
            return 0;
        }
	if(input==114) {
		system("adb shell wm size >> /tmp/adbcontrol.txt");
		fstream wmsizetmp;
		wmsizetmp.open("/tmp/adbcontrol.txt");
		if(!wmsizetmp.is_open()) {
			move(17,0);
			printw("The tmp file can't be accessed.");
			refresh();
			break;
		}
		string buffer;
		getline(wmsizetmp,buffer);
		move(14,0);
		bool wasx=false;
		string xstring="\0";
		string ystring="\0";
		for(int i=0; i<buffer.length(); i++) {
			if(buffer[i]=='x') {
				wasx=true;
			}
			if(isnumber(buffer[i]) && wasx==false) {
				xstring=xstring+buffer[i];
			}
			if(isnumber(buffer[i]) && wasx==true) {
				ystring=ystring+buffer[i];
			}
		}
		istringstream str(xstring);
		str >> x;
		istringstream str2(ystring);
		str2>> y;
		move(18,0);
		printw("X: \"%d\"\tY: \"%d\"",x,y);
		refresh();
		wmsizetmp.close();
		system("rm /tmp/adbcontrol.txt");
	}
        if(input==112) {
            system("adb shell input keyevent KEYCODE_POWER");
        }
        if(input==104) {
            system("adb shell input keyevent KEYCODE_HOME");
        }
        if(input==98) {
            system("adb shell input keyevent KEYCODE_BACK");
        }
        if(input==65) {
            system("adb shell input keyevent KEYCODE_DPAD_UP");
        }
        if(input==66) {
            system("adb shell input keyevent KEYCODE_DPAD_DOWN");
        }
        if(input==68) {
            system("adb shell input keyevent KEYCODE_DPAD_LEFT");
        }
        if(input==67) {
            system("adb shell input keyevent KEYCODE_DPAD_RIGHT");
        }
        if(input==10) {
            system("adb shell input keyevent KEYCODE_ENTER");
        }
        if(input==117) {
            system("adb shell input keyevent 66");
        }
	stringstream tmp5;
	tmp5.str("\0");
	tmp5<<x-1;
	string xstring=tmp5.str();
	tmp5.str("\0");
	tmp5<<y-1;
	string ystring=tmp5.str();
	int xcenteri=x/2;
	int ycenteri=y/2;
	stringstream tmp3;
	tmp3.str("\0");
	tmp3<<xcenteri;
	string xcenter=tmp3.str();
	stringstream tmp4;
	tmp4.str("\0");
	tmp4<<ycenteri;
	string ycenter=tmp4.str();
	string commande;
        if(input==100) {
		commande="adb shell input swipe "+xstring+" "+ycenter+" 1 "+ycenter;
            system(commande.c_str());
        }
        if(input==119) {
		commande="adb shell input swipe "+xcenter+" "+ystring+" "+xcenter+" 1";
            system(commande.c_str());
        }
        if(input==97) {
		commande="adb shell input swipe 1 "+ycenter+" "+xstring+" "+ycenter;
            system(commande.c_str());
        }
        if(input==115) {
		commande="adb shell input swipe "+xcenter+" 1 "+xcenter+" "+ystring;
            system(commande.c_str());
        }
        if(input==43) {
            system("adb shell input keyevent VOLUME_UP");
        }
        if(input==45) {
            system("adb shell input keyevent VOLUME_DOWN");
	}
        refresh();
    }
}
