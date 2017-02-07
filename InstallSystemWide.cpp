#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    string Argv1String=argv[0];
    size_t LastPer=Argv1String.find_last_of("/");
    string ExecutableName=Argv1String.substr(LastPer+1);
    string ExecutablePath=argv[1];
    string cp="sudo cp ";
    string usrlocalbin="/usr/local/bin/";
    string chmod="sudo chmod 777 ";
    string command1=cp+ExecutablePath+" "+usrlocalbin;
    string command2=chmod+usrlocalbin+ExecutableName;
    cout<<"Copying file..."<<endl;
    system(command1.c_str());
    cout<<"Setting permissions..."<<endl;
    system(command2.c_str());
    ifstream file;
    file.open(ExecutablePath.c_str());
    if(file.is_open())
    {
        cout<<"All done!"<<endl;
        file.close();
    }
    else
    {
        cout<<"Can't write to /usr/local/bin/"<<endl;
        cout<<"Check superuser rights."<<endl;
        file.close();
    }
}
