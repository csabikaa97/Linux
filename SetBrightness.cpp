#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
	if(argc==2)
	{
		string command1 =" sudo echo \"";
		string command2 ="\" > /sys/class/backlight/acpi_video0/brightness";
		string final=command1+argv[1]+command2;
		system(final.c_str());
	}
	return 0;
}
