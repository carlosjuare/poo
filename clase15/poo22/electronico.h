#ifndef ELECTRONICO_H
#define ELECTRONICO_H
#include <iostream>

class Electrico {
protected:
    int voltaje;

public:
    Electrico();
    virtual ~Electrico();

    void setVoltaje(int v);
    int getVoltaje() const;
};

#endif // ELECTRONICO_H
