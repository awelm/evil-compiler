#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if(argc >= 2) {
        string fileName = argv[1];
        string computeHashCmd = "sha256sum " + fileName;
        system(computeHashCmd.c_str());
    }
}