#include "master.h"

Master::Master(QObject *parent) : QObject(parent)
{
    login = new Login();
    ventana = new Ventana();

    connect(login, &Login::accepted, this, &Master::iniciar);
    connect(this, &Master::loginExitoso, login, &Login::hide);
    connect(this, &Master::loginExitoso, ventana, &Ventana::show);

    login->show();
}

Master::~Master()
{
    delete login;
    delete ventana;
}

void Master::iniciar()
{
    emit loginExitoso();
}
