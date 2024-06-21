#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento {
private:
    int tambores;

public:
    Bateria();

    void sonar() const override;

    void setTambores(int t);
    int getTambores() const;
};
#endif // BATERIA_H
