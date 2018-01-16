#include <iostream>
#include <curses.h>
#include <cstdlib>
using namespace std;
int main() {
    initscr();
    
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
        char input = getch();
        move(0,0);
        printw("Input: %c",input);
        if(input=='Q') {
            endwin();
            return 0;
        }
        refresh();
    }
}
