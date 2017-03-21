#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	string AdbInstall="adb install ";
    	string command;
	command=AdbInstall+argv[1];
	system(command.c_str());
	return 0;
}
