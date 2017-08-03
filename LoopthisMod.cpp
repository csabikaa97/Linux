#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
    if(argc==3)
    {
        string lel=argv[1];
	string lel2=argv[2];
	int number=atoi(lel2.c_str());
        while(true)
        {
            system(lel.c_str());
            usleep(number);
        }
    }
    else
    {
        return 0;
    }
}
