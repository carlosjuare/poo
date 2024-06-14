#include "master.h"

Master::Master(QObject *parent) : QObject(parent)
{
    login = new Login();
   ventana = new Ventana();
  ingresarUsuario = new IngresarUsuario();
    connect(login, &Login::loginSuccessful, this, &Master::onLoginSuccessful);
    connect(login, &Login::navigateToOtherWindow, this, &Master::onNavigateToOtherWindow);
}

Master::~Master()
{
    delete login;
    delete ventana;
     delete ingresarUsuario;
}

void Master::showLogin()
{
    login->show();
}

void Master::onLoginSuccessful()
{
    login->hide();
    ventana->show();
}

void Master::onNavigateToOtherWindow()
{
    login->hide();
    ingresarUsuario->show();
    // Lógica para mostrar otra ventana si fuera necesario
}
