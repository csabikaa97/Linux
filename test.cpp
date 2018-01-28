#include <iostream>
#include "Tools.hpp"
using namespace std;
int main() {
	string original="Hang vagy SSID: dsa";
	string removable="vagy";
	cout<<"Original: \t"<<original<<endl;
	cout<<"Removable: \t"<<removable<<endl;
	cout<<"RemoveString: \t"<<RemoveString(original,removable)<<endl;
	return 0;
}
