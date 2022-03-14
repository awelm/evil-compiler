// su.cpp
using namespace std;
#include <iostream>

int main() {
    string enteredPassword;
    cin >> enteredPassword;
    if(enteredPassword == "test123")    
        cout << "Successfully logged in as root" << endl;
    else
        cout << "Wrong password, try again." << endl;
}