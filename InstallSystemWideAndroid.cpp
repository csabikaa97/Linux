#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
	if(argc==2)
	{
		if(argv[1]=="")
		{
			return 0;
		}
		system("mount -o rw,remount -t ext4 /system");
		string cp="cp ";
		string systembin="/system/bin";
		string command1=cp+argv[1]+" "+systembin;
		string temp=argv[1];
		int space=0;
		for(int i=0; i<temp.length(); i++)
		{
			if(temp[i]=='/')
			{
				space=i;
			}
		}
		string executablename;
		string temp2;
		for(int i=0; i<temp.length()-space; i++)
		{
			temp2[i]=temp[space+i];
		}
		string command2;
		command2="chmod 777 "+systembin+executablename;
		system(command1.c_str());
		system(command2.c_str());
	}
	else
	{
		return 0;
	}
	return 0;
}
