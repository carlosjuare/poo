#include "teclado.h"

Teclado::Teclado() : teclas(61) {}

void Teclado::sonar() const {
    std::cout << "Teclado suena..." << std::endl;
}

void Teclado::setTeclas(int t) {
    teclas = t;
}

int Teclado::getTeclas() const {
    return teclas;
}
