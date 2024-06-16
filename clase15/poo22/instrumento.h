#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H
#include <iostream>
#include <string>

class Instrumento {
protected:
    std::string marca;

public:
    Instrumento();
    virtual ~Instrumento();

    virtual void sonar() const = 0; // Función virtual pura
    virtual void verlo() const;
};

#endif // INSTRUMENTO_H
