#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <unistd.h>
using namespace std;
int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		cout<<"Too few arguments!\t";
		return 0;
	}
	string command=argv[1];
	string times=argv[2];
	int timesINT=atoi(times.c_str());
	srand(time(NULL));
	for(int i=0; i<timesINT; i++)
	{
		usleep(rand()%2);
		system(command.c_str());
	}
	return 0;
}
