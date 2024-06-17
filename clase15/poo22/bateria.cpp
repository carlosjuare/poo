#include "bateria.h"

Bateria::Bateria() : tambores(5) {}

void Bateria::sonar() const {
    std::cout << "Batería suena..." << std::endl;
}

void Bateria::setTambores(int t) {
    tambores = t;
}

int Bateria::getTambores() const {
    return tambores;
}
