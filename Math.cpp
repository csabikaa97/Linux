#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
	if(argc==4) {
		string szam1s=argv[1];
		string szam2s=argv[3];
		string muvelet=argv[2];
		if(muvelet=="x" || muvelet=="/" || muvelet=="+" || muvelet=="-")
		{
			int szam1i=atoi(szam1s.c_str());
			float szam1=szam1i;
			int szam2i=atoi(szam2s.c_str());
			float szam2=szam2i;
			cout<<"("<<szam1<<" "<<muvelet<<" "<<szam2<<") = ";
			switch(muvelet[0])
			{
				case '/':	cout<<szam1/szam2; break;
				case 'x':	cout<<szam1*szam2; break;
				case '+':	cout<<szam1+szam2; break;
				case '-':	cout<<szam1-szam2; break;
			}
			cout<<endl;
		}
	}
	else cout<<"TERMED";
}
