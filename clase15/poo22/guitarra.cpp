#include "guitarra.h"

Guitarra::Guitarra() : cuerdas(6) {}

void Guitarra::sonar() const {
    std::cout << "Guitarra suena..." << std::endl;
}

void Guitarra::setCuerdas(int c) {
    cuerdas = c;
}

int Guitarra::getCuerdas() const {
    return cuerdas;
}
