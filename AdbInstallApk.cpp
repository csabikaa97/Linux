#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		cout<<"Incorrect amount of arguments passed"<<endl;
		return 0;
	}
	fstream File;
	string Filename=argv[1];
	File.open(Filename.c_str());
	if(!File.is_open())
	{
		cout<<"Input file can't be opened."<<endl;
		return 0;
	}
	string AdbInstall="adb install ";
    	string command;
	command=AdbInstall+Filename;
	system(command.c_str());
	return 0;
}
