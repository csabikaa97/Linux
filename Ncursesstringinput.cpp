#include <string>
#include <curses.h>
using namespace std;
int main() {
	string a;
	initscr();
	printw("Enter a string: \"");
	refresh();
	for(int i=0; i<32; i++) {
		char b = getch();
		if(b!='\n') {
			a=a+b;
		}
		else {
			break;
		}
	}
	move(1,0);
	printw("\"\n Full string: \"");
	for(int i=0; i<a.length(); i++) {
		printw("%c",a[i]);
	}
	refresh();
	endwin();
	return 0;
}
