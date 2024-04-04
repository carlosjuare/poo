#include <iostream>
#include <string>

class Vehiculo {
private:
    std::string marca;
    std::string modelo;
    int anio;
    float precio;

public:
    // Constructor predeterminado
    Vehiculo() {
        marca = "Desconocida";
        modelo = "Desconocido";
        anio = 0;
        precio = 0.0;
    }

    // Constructor con parámetros
    Vehiculo(std::string marca, std::string modelo, int anio, float precio) {
        this->marca = marca;
        this->modelo = modelo;
        this->anio = anio;
        this->precio = precio;
    }

    // Métodos para establecer los valores de los atributos
    void setMarca(std::string marca) {
        this->marca = marca;
    }

    void setModelo(std::string modelo) {
        this->modelo = modelo;
    }

    void setAnio(int anio) {
        this->anio = anio;
    }

    void setPrecio(float precio) {
        this->precio = precio;
    }

    // Métodos para obtener los valores de los atributos
    std::string getMarca() {
        return marca;
    }

    std::string getModelo() {
        return modelo;
    }

    int getAnio() {
        return anio;
    }

    float getPrecio() {
        return precio;
    }

    // Método para mostrar la información del vehículo
    void mostrarInformacion() {
        std::cout << "Marca: " << marca << std::endl;
        std::cout << "Modelo: " << modelo << std::endl;
        std::cout << "Año: " << anio << std::endl;
        std::cout << "Precio: $" << precio << std::endl;
    }
};

int main() {
    // Crear objetos de la clase Vehiculo
    Vehiculo vehiculo1; // Usando constructor predeterminado
    Vehiculo vehiculo2("Toyota", "Corolla", 2022, 25000.0); // Usando constructor con parámetros

    // Mostrar información de los vehículos
    std::cout << "Información del Vehículo 1:" << std::endl;
    vehiculo1.mostrarInformacion();
    std::cout << std::endl;

    std::cout << "Información del Vehículo 2:" << std::endl;
    vehiculo2.mostrarInformacion();
    std::cout << std::endl;

    return 0;
}

