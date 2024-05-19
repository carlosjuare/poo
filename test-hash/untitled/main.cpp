#include <QCoreApplication>
#include <QDebug>
#include "login.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Creamos una instancia de la clase Login
    Login login;

    // Simulamos un proceso de inicio de sesión
    QString nombreUsuario = "usuario1";
    QString clave = "password1";

    // Llamamos a la función iniciarSesion de la instancia de Login
    login.iniciarSesion(nombreUsuario, clave);

    return a.exec();
}
