#include <iostream>
#include <string>

using namespace std;

// Declaración de la clase Persona
class Persona {
private:
    string nombre;
    string apellido;

public:
    Persona(string nombre, string apellido) : nombre(nombre), apellido(apellido) {}

    // Función para mostrar los datos de la persona
    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
    }
};

// Declaración de la clase Poste
class Poste {
private:
    double alto;
    double ancho;

public:
    Poste(double alto, double ancho) : alto(alto), ancho(ancho) {}

    // Función para mostrar los datos del poste
    void mostrarDatos() {
        cout << "Alto: " << alto << " metros" << endl;
        cout << "Ancho: " << ancho << " metros" << endl;
    }
};

// Sobrecarga de funciones para mostrar datos de cualquier objeto
void mostrarDatosGenericos(Persona persona) {
    persona.mostrarDatos();
}

void mostrarDatosGenericos(Poste poste) {
    poste.mostrarDatos();
}

int main() {
    // Crear objetos de las clases Persona y Poste
    Persona persona("Juan", "Perez");
    Poste poste(5.0, 0.3);

    // Mostrar los datos llamando a las funciones específicas
    cout << "Datos de la persona:" << endl;
    mostrarDatosGenericos(persona);

    cout << "\nDatos del poste:" << endl;
    mostrarDatosGenericos(poste);

    return 0;
}


