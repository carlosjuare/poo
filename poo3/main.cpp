#include <iostream>
#include <string>
using namespace std;
namespace espacio {
string getVersion() {
    return "v0.0.2 - 666666";
}
}

int main() {
    string version = espacio::getVersion();
    cout << "Version: " << version << endl;
    return 0;
}
