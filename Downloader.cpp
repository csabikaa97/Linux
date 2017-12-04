#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;
int main()
{
	int counter=0;
	while(true)
	{
		counter++;
		//sample: "https://ncore.cc/torrents.php?action=download&id=2058977&key=86fb59a05081d47a692ecef6a31888a1"
		string token="86fb59a05081d47a692ecef6a31888a1";
		string base="https://ncore.cc/torrents.php?action=download&id=";
		string id="";
		string base2="&key=";
		cin>>id;
		if(id=="exit" or id=="")
		{
			return 0;	
		}
		string command1=base+id+base2+token;
		string command2="open \"";
		string finalcommand=command2+command1+"\"";
		cout<<counter<<": "<<finalcommand<<endl;
		system(finalcommand.c_str());
		usleep(1000000);
	}
}
