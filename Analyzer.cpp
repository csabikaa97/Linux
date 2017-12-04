#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main()
{
	fstream phpfile;
	phpfile.open("hitnrun.php");
	if(!phpfile.is_open())
	{
		return 0;
	}
	int counter=0;
	int counter2=0;
	while(true)
	{
		counter++;
		string buffer="\0";
		getline(phpfile,buffer);
		if(counter==1000000)
		{
			break;
		}
		string temp="";
		string code="";
		for(int i=0; i<buffer.length(); i++)
		{
			temp="";
			for(int b=0; b<8; b++)
			{
				temp=temp+buffer[i+b];
			}
			//cout<<"Temp: "<<temp<<endl;
			if(temp=="torrent(")
			{
				counter2++;
				for(int d=0; d<7; d++)
				{
					char c=buffer[i+8+d];
					if(c=='1' or c=='2' or c=='3' or c=='4' or c=='5' or c=='6' or c=='7' or c=='8' or c=='9' or c=='0')
					{
						code=code+buffer[i+8+d];			
					}
				}
				if(counter2>23)
				{
					cout<<code<<endl;
				}
				//cout<<"Code found("<<counter2<<"): \""<<code<<"\"."<<endl;
			}
		}
	}
	return 0;
}
