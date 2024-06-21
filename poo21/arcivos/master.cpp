#include "master.h"

Master::Master(QWidget *parent)
    : QWidget(parent)
{
    loginWidget = new Login(this);        // Crear instancia de Login
    formularioWidget = new Formulario(this); // Crear instancia de Formulario

    // Conectar la señal sesionIniciada de Login al slot mostrarFormulario de Master
    connect(loginWidget, &Login::sesionIniciada, this, &Master::mostrarFormulario);

    // Conectar la señal volverClicked de Formulario al slot mostrarLogin de Master
    connect(formularioWidget, &Formulario::volverClicked, this, &Master::mostrarLogin);

    // Mostrar login y ocultar formulario por defecto
    loginWidget->show();
    formularioWidget->hide();
}

void Master::mostrarLogin()
{
    formularioWidget->hide(); // Ocultar el widget de formulario
    loginWidget->show();      // Mostrar el widget de login
}

void Master::mostrarFormulario()
{
    loginWidget->hide();        // Ocultar el widget de login
    formularioWidget->show();   // Mostrar el widget de formulario
}
