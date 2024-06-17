#include <iostream>
#include <string>
#include <vector>

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
    std::string getMarca() const {
        return marca;
    }

    std::string getModelo() const {
        return modelo;
    }

    int getAnio() const {
        return anio;
    }

    float getPrecio() const {
        return precio;
    }

    // Método para mostrar la información del vehículo
    void mostrarInformacion() const {
        std::cout << "Marca: " << marca << std::endl;
        std::cout << "Modelo: " << modelo << std::endl;
        std::cout << "Año: " << anio << std::endl;
        std::cout << "Precio: $" << precio << std::endl;
    }
};

int main() {
    // Crear un vector para almacenar objetos de la clase Vehiculo
    std::vector<Vehiculo> vehiculos;

    // Crear algunos objetos de la clase Vehiculo y almacenarlos en el vector
    vehiculos.push_back(Vehiculo("Toyota", "Corolla", 2022, 25000.0));
    vehiculos.push_back(Vehiculo("Honda", "Civic", 2021, 22000.0));
    vehiculos.push_back(Vehiculo("Ford", "Mustang", 2023, 45000.0));

    // Mostrar la información de todos los vehículos almacenados en el vector
    for (const auto& vehiculo : vehiculos) {
        vehiculo.mostrarInformacion();
        std::cout << std::endl;
    }

    return 0;
}


