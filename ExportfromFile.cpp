#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
	if(argc==3)
	{
		string variable=argv[1];
		string file=argv[2];
		string command="export "+variable+"=\"$(more "+file+")\"";
		system(command.c_str());
	}
}
