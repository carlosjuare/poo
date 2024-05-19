#include "login.h"
#include "admindb.h"
#include <QMessageBox>
#include <QDebug>

Login::Login(QObject *parent) : QObject(parent) {}

void Login::iniciarSesion(QString nombreUsuario, QString clave) {
    AdminDB adminDB;

    qDebug() << "Intentando iniciar sesión para el usuario:" << nombreUsuario;

    if (adminDB.conectar("../db2.db")) {
        qDebug() << "Conexión a la base de datos exitosa.";

        QStringList datos = adminDB.validarUsuario("usuarios", nombreUsuario, clave);
        if (!datos.isEmpty()) {
            emit usuarioAutenticado(nombreUsuario);
            qDebug() << "Inicio de sesión exitoso para el usuario:" << nombreUsuario;
        } else {
            qDebug() << "Nombre de usuario o contraseña incorrectos.";
        }
    } else {
        qDebug() << "No se pudo conectar a la base de datos";
    }
}
