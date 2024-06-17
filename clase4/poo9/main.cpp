#include<iostream>
#include<algorithm> // Para std::sort
#include<functional>
using namespace std;
template < class T > void imprimir( T * v, int cantidad, bool mayor_a_menor ){

    if (mayor_a_menor) {
            sort(v, v + cantidad, greater<T>());
        } else {
            sort(v, v + cantidad, less<T>());
        }

        for (int i = 0; i < cantidad; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
}
int main(){
    int v[5]{3,4,6,1,6};


    float ve[5]{0.5,99.2,20.1,0.99,54.3};
     cout << "Orden ascendente: ";
    imprimir(v,5,false);
     cout << "Orden descendente: ";
    imprimir(ve,5,true);
}
