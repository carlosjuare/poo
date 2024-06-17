#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento {
private:
    int cuerdas;

public:
    Guitarra();

    void sonar() const override;

    void setCuerdas(int c);
    int getCuerdas() const;
};

#endif // GUITARRA_H
