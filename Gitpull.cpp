#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
	if(argc==3)
	{
		string username = argv[1];
		string repository = argv[2];
		string command1 = "git clone http://github.com/"+username+"/"+repository;
		system(command1.c_str());
		return 0;
	}
	else
	{
		return 0;
	}
}
