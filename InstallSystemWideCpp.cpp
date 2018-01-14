#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[]) {
	bool Found=false;
	int counter2=0;
	if(argc!=2) {
		cout<<"Too few arguments passed."<<endl;
		return 0;
	}
	string SourceFilename=argv[1];
	string Filename;
	for(int i=0; i<SourceFilename.length(); i++) {
		if(SourceFilename[i]=='.' && SourceFilename[i+1]=='c' && SourceFilename[i+2]=='p' && SourceFilename[i+3]=='p') {
			int NeededLength=i;
			for(int b=0; b<NeededLength; b++) {
				Filename=Filename+SourceFilename[b];
			}
			fstream Source;
			Source.open(SourceFilename.c_str());
			if(Source.is_open()) {
				cout<<endl<<"Source file initialized."<<endl;
				cout<<"Compiled filename: "<<Filename<<endl;
				Found=true;
			}
			else {
				cout<<endl<<"Source file can't be opened."<<endl;
				return 0;
			}
		}
	}
	if(Found==false) {
		cout<<endl<<"Wrong source file format (must be \".cpp\")."<<endl;
		return 0;
	}
	string Command1="sudo g++ "+SourceFilename+" -o "+Filename;
	system(Command1.c_str());
	fstream CompiledFile;
	CompiledFile.open(Filename.c_str());
	if(!CompiledFile.is_open()) {
		cout<<endl<<"There was an error in the compilation process.\tCompiled file can't be accessed."<<endl;
		return 0;
	}
	else {
		string Command2="sudo cp "+Filename+" /usr/local/bin/";
		system(Command2.c_str());
		string Command3="sudo chmod 777 /usr/local/bin/"+Filename;
		system(Command3.c_str());
		string Command4="sudo rm "+Filename;
		system(Command4.c_str());
		cout<<endl<<"All done!"<<endl;
	}
	return 0;
}
