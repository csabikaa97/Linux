#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main()
{
	while(true)
	{
		system("sensors");
		sleep(1);
	}
}