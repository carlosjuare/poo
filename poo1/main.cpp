#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  srand(time(nullptr));
  for (int i = 0; i < 10; ++i) {
         int numero = rand() % 19 + 2; // Genera un número aleatorio en el intervalo [2, 20]
         cout << numero <<endl; // Imprime el número en la consola
     }

     return 0;
}
