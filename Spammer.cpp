#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;
int main()
{
	string basecommand="airbase-ng -c ";
	string basemac="00:00:00:69:69:6";
	while(true)
	for(int i=0; i<10; i++)
	{
		string secondary;
		switch(i)
		{
			case 0:	secondary="Gepipari1";
				break;
			case 1:	secondary="Gepipari2";
				break;
			case 2:	secondary="Gepipari3";
				break;
			case 3:	secondary="Gepipari4";
				break;
			case 4:	secondary="Gepipari5";
				break;
			case 5:	secondary="Gepipari0";
				break;
			case 6:	secondary="Gepipari6";
				break;
			case 7:	secondary="Gepipari7";
				break;
			case 8:	secondary="Gepipari8";
				break;
			case 9:	secondary="Gepipari9";
				break;
		}
		stringstream buffer2;
		buffer2<<i;
		string szam2=buffer2.str();
		int temp=i+1;
		string szam;
		stringstream buffer;
		buffer.str("");
		buffer<<temp;
		szam=buffer.str();
		string modmac=basemac+szam2;
		string final=basecommand+szam+" -e \""+secondary+"\" -a "+modmac+" mon0";
		system(final.c_str());
		cout<<endl<<final<<endl;
	}
	return 0;
}
