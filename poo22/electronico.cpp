#include "electronico.h"

Electrico::Electrico() : voltaje(220) {}

Electrico::~Electrico() {
    std::cout << "Desenchufado" << std::endl;
}

void Electrico::setVoltaje(int v) {
    voltaje = v;
}

int Electrico::getVoltaje() const {
    return voltaje;
}
