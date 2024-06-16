#ifndef TECLADO_H
#define TECLADO_H
#include "instrumento.h"
#include "electronico.h"

class Teclado : public Instrumento, public Electrico {
private:
    int teclas;

public:
    Teclado();

    void sonar() const override;

    void setTeclas(int t);
    int getTeclas() const;
};
#endif // TECLADO_H
