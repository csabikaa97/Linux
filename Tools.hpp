#include <fstream>
#include <curses.h>
#include <sstream>
#include <string>
using namespace std;
void PrintStringNcurses(string a) {
	for(int i=0; i<a.length(); i++) {
		printw("%c",a[i]);
	}
}
string ReadStringFromNcurses() {
	string a;
	for(int i=0; i<64; i++) {
		char b = getch();
		if(b!='\n') {
			a=a+b;
		}
		else {
			break;
		}
	}
	return a;
}
bool IsNumber(char a) {
	if(a=='0' or a=='1' or a=='2' or a=='3' or a=='4' or a=='5' or a=='6' or a=='7' or a=='8' or a=='9') {
		return true;
	}
	else {
		return false;
	}
}
int StringToInt(string a) {
	for(int i=0; i<a.length(); i++) {
		if(!IsNumber(a[i])) {
			a[i]='\0';
		}
	}
	istringstream tmp(a);
	int r;
	tmp>>r;
	return r;
}
string IntToString(int a) {
	stringstream tmp;
	tmp<<a;
	return tmp.str();
}
