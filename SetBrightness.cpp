#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	if(argc==2)
	{
		ifstream file;
		file.open("/sys/class/backlight/acpi_video0/brightness");
		if(!file.is_open())
		{
			cout<<endl<<"This computer doesn't support changing brghtness."<<endl;
			return 0;
		}
		string command1 =" sudo echo \"";
		string command2 ="\" > /sys/class/backlight/acpi_video0/brightness";
		string final=command1+argv[1]+command2;
		system(final.c_str());
	}
	return 0;
}
