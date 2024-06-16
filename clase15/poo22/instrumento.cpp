#include "instrumento.h"

Instrumento::Instrumento() : marca("Yamaha") {}

Instrumento::~Instrumento() {}

void Instrumento::verlo() const {
    std::cout << "Marca: " << marca << std::endl;
}
