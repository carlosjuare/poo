#include <iostream>
#include <string>

using namespace std;


class Persona {
private:
    string nombre;
    string apellido;

public:
    Persona(string nombre, string apellido) : nombre(nombre), apellido(apellido) {}


    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
    }
};


class Poste {
private:
    double alto;
    double ancho;

public:
    Poste(double alto, double ancho) : alto(alto), ancho(ancho) {}


    void mostrarDatos() {
        cout << "Alto: " << alto << " metros" << endl;
        cout << "Ancho: " << ancho << " metros" << endl;
    }
};


void mostrarDatosGenericos(Persona persona) {
    persona.mostrarDatos();
}

void mostrarDatosGenericos(Poste poste) {
    poste.mostrarDatos();
}

int main() {

    Persona persona("Juan", "Perez");
    Poste poste(5.0, 0.3);


    cout << "Datos de la persona:" << endl;
    mostrarDatosGenericos(persona);

    cout << "\nDatos del poste:" << endl;
    mostrarDatosGenericos(poste);

    return 0;
}


