#include <iostream>
#include <vector>
#include <string>

using namespace std;

void orden(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<string> frases;


   frases.push_back("los dias largos");
    frases.push_back("las noches cortas");
     frases.push_back("el sol brillante");
      frases.push_back("y mas calor se nota");
       frases.push_back("verano");


    orden(frases);


    cout << "\nFrases ordenadas en orden alfabético:" << endl;
    for (const auto& frase : frases) {
        cout << frase << endl;
    }

    return 0;
}
