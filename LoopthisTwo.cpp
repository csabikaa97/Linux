#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main(int argc, char* argv[])
{
	if(argc==3)
	{
		while(true)
		{
			system(argv[1]);
			system(argv[2]);
			sleep(1);
		}
	}
	else
	{
		return 0;
	}
}
