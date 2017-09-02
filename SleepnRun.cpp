#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;
int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		return 0;
	}
	string command=argv[1];
	string time=argv[2];
	int timeINT=atoi(time.c_str());
	sleep(timeINT);
	system(command.c_str());
	return 0;
}
