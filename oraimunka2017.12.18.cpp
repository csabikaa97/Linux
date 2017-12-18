#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool ezszam(char a)
{
    if(a=='0' || a=='1' || a=='2' || a=='3' || a=='4' || a=='5' || a=='6' || a=='7' || a=='8' || a=='9') {
        return true;
    }
    return false;
}
int main() {
    fstream file;
    file.open("egyszamjatek.txt");
    if(!file.is_open()) {
        cout<<"File nem megnyithato.";
        return 0;
    }
    string tempszamok[9][10];
    int Szamok[9][10];
    string buffer;
    string Nevek[10];
    int counter1=0;
    while(getline(file,buffer)) {
        int counter=0;
        cout<<"Buffer: \""<<buffer<<"\""<<endl;
        for(int i=0; i<buffer.length(); i++) {
            if(ezszam(buffer[i])) {
               tempszamok[counter1][counter]+=buffer[i];
            }
            if(buffer[i]==' ') {
                counter++;
            }
            if(!ezszam(buffer[i]) && buffer[i]!=' ') {
                int counter2=0;
                while() {
                    
                }
                counter1++;
                break;
            }
        }
    }
    for(int i=0; i<9; i++){
        cout<<"Nevek["<<i<<"]: "<<Nevek[i]<<": ";
        for(int b=0; b<10; b++) {
            cout<<tempszamok[i][b]<<" ";
        }
    }
}
