#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // para std::max_element
#include <iterator> // para std::distance

using namespace std;

int main()
{
    int num[30];
    int frequency[15] = {0};
    int b = 0;

    srand(time(nullptr));
    for (int i = 0; i < 30; ++i) {
        num[i] = rand() % 15 + 1;
        frequency[num[i] - 1]++;
    }


    auto max_freq_iter = std::max_element(std::begin(frequency), std::end(frequency));
    int max_freq = *max_freq_iter;
    int max_freq_index = std::distance(std::begin(frequency), max_freq_iter) + 1;
    if (max_freq == 1) {

        cout << "Ningún número se repite más de una vez. Mostrando todos los números:" << endl;
        for (int i = 0; i < 30; ++i) {
            cout << num[i] << endl;
        }
    } else {

        cout << "El número más repetido (" << max_freq_index << ") aparece " << max_freq << " veces:" << endl;
        for (int i = 0; i < 30; ++i) {
            if (num[i] == max_freq_index) {
                cout << num[i] << endl;
            }
        }
    }

    return 0;
}
