#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	string AdbInstall="adb insall ";
    string command;
	command=AdbInstall+argv[1];
	system(command.c_str());
}
