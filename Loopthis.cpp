#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main(int argc, char* argv[])
{
    if(argc==2)
    {
        string lel=argv[1];
        while(true)
        {
            system(lel.c_str());
            sleep(1);
        }
    }
    else
    {
        return 0;
    }
}
