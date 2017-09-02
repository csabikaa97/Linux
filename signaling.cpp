#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>

volatile sig_atomic_t flag=0;

void my_handler(int sig)
{
	flag=1;
}
int main()
{
	signal(SIGINT,my_handler);
	while(true)
	{
		if(flag)
		{
			std::cout<<"CAUGHT SIGINT!!!"<<std::endl;
		}
		flag=0;
	}
	return 0;
}
