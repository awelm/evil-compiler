#include <iostream>

using namespace std;

int main() {
    cout << "Enter password:" << endl;
    string enteredPassword;
    cin >> enteredPassword;
    if(enteredPassword == "test123")    
        cout << "Successfully logged in as root" << endl;
    else
        cout << "Wrong password, try again." << endl;
}