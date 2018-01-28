#include <fstream>
#include <curses.h>
#include <sstream>
#include <string>
using namespace std;
string RemoveString(string original, string removable) {
	int counter=0;
	int counter7=0;
	for(int i=0; i<original.length(); i++) {
		if(original[i]==removable[0]) {
			for(int c=0; c<removable.length(); c++) {
				if(counter==removable.length()) {
				}
				if(original[c]==removable[c]) {
					counter++;
				}
				else {
					counter=0;
				}
			}
		}
	}
	return original+"XDD";
}
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
bool DoesThisContaintAnyOfThis(char a, string b) {
	for(int i=0; i<b.length(); i++) {
		if(a==b[i]) {
			return true;
		}
	}
	return false;
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
