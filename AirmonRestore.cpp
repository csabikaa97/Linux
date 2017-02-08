#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	system("sudo service wpa_supplicant restart");
	system("sudo service NetworkManager restart");
	return 0;
}