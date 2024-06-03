#ifndef LINEA_H
#define LINEA_H


class Linea
{
public:
    Linea();
    void Geter();
    void Seter(int a,int b,int c,int d);
    int getXInicial() const;
        int getYInicial() const;
        int getXFinal() const;
        int getYFinal() const;
private:
    int x_inicial, y_inicial, x_final, y_final ;



};

#endif // LINEA_H
