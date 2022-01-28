using namespace std;
#include <string>
#include <cstdlib> 

int main(int argc, char *argv[]) {
	string allArgs = "";
    for(int i=1; i<argc; i++)
        allArgs += " " + string(argv[i]);
    string shellCommand = "g++" + allArgs;
	system(shellCommand.c_str());
}