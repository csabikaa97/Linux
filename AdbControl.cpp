#include <iostream>
#include <curses.h>
#include <cstdlib>
#include <fstream>
using namespace std;
int main() {
    fstream adbfilecheck;
    adbfilecheck.open("/usr/bin/adb");
    if(!adbfilecheck.is_open()) {
        printw("Couldn't open ADB.");
	refresh();
	endwin();
	return 0;
    }
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
    move(13,0);
    printw("T - APK install");
    move(14,0);
    printw("Shift + S - shell");
    refresh();
    while(true) {
	move(0,0);
        printw("Input: ");
	int input = getch();
        if(input==81) {
            endwin();
            return 0;
        }
	if(input==105) {
            cout<<endl<<"Szöveg: ";
            cin>>text;
            text=b+text;
            system(text.c_str());
        }
        if(input==112) {
            system("adb shell input keyevent KEYCODE_POWER");
        }
        if(input==116)
        {
            cout<<endl<<"APK helye: ";
            cin>>TempPATH;
            string command2="adb install "+TempPATH;
            system(command2.c_str());
            cout<<endl;
        }
        if(input==83)
        {
            cout<<endl;
            system("adb shell");
        }
        if(input==104)
        {
            system("adb shell input keyevent KEYCODE_HOME");
        }
        if(input==98)
        {
            system("adb shell input keyevent KEYCODE_BACK");
        }
        if(input==72)
        {
            system("adb shell input keyevent KEYCODE_DPAD_UP");
        }
        if(input==80)
        {
            system("adb shell input keyevent KEYCODE_DPAD_DOWN");
        }
        if(input==75)
        {
            system("adb shell input keyevent KEYCODE_DPAD_LEFT");
        }
        if(input==77)
        {
            system("adb shell input keyevent KEYCODE_DPAD_RIGHT");
        }
        if(input==13)
        {
            system("adb shell input keyevent KEYCODE_ENTER");
        }
        if(input==117)
        {
            system("adb shell input keyevent 66");
        }
        if(input==110)
        {
            system("adb shell input swipe 360 1 360 1280");
        }
        if(input==119)
        {
            system("adb shell input swipe 360 1279 360 1");
        }
        if(input==97)
        {
            system("adb shell input swipe 1 640 719 640");
        }
        if(input==115)
        {
            system("adb shell input swipe 719 1 719 1279");
        }
        if(input==100)
        {
            system("adb shell input swipe 719 640 1 640");
        }
        if(input==43)
        {
            system("adb shell input keyevent VOLUME_UP");
        }
        if(input==45)
        {
            system("adb shell input keyevent VOLUME_DOWN");
	}
        refresh();
    }
}
