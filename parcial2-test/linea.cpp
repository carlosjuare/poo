#include "linea.h"

Linea::Linea()
{




}

void Linea::Seter(int a, int b, int c, int d)
{

    x_inicial= a;
    y_inicial= b;
    x_final=  c;
    y_final = d;
}
int Linea::getXInicial() const {
    return x_inicial;
}

int Linea::getYInicial() const {
    return y_inicial;
}

int Linea::getXFinal() const {
    return x_final;
}

int Linea::getYFinal() const {
    return y_final;
}
