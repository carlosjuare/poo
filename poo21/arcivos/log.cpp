
#include "log.h"
#include <QPainter>
#include <QDebug>
#include <QResizeEvent>

Login::Login(QWidget *parent) : QWidget(parent) {
    if (datbase.conectar("db2.db"))
        qDebug() << "Conexion exitosa";
    else
        qDebug() << "Conexion NO exitosa";
    datbase.consulta();



    setWindowTitle("ventana");

    nombre = new QLabel("nombre");
    Enombre = new QLineEdit;
    clave = new QLabel("clave");
    Eclave = new QLineEdit;
    Eclave->setEchoMode(QLineEdit::Password);

    botonIniciarSesion = new QPushButton("Iniciar sesión");



    pantalla = new QGridLayout(this);
    pantalla->addWidget(nombre, 0, 0);
    pantalla->addWidget(Enombre, 0, 1);
    pantalla->addWidget(clave, 1, 0);
    pantalla->addWidget(Eclave, 1, 1);

    pantalla->addWidget(botonIniciarSesion, 3, 0, 1, 2);



    connect(botonIniciarSesion, SIGNAL(clicked()), this, SLOT(iniciarSesion())); // Conexión del botón







}


void Login::iniciarSesion() {
    QString nombreUsuario = Enombre->text();
    QString claveUsuario = Eclave->text();

    qDebug() << "Intentando iniciar sesión para el usuario:" << nombreUsuario;

    if (datbase.conectar("db2.db")) {
        qDebug() << "Conexión a la base de datos exitosa.";

        QStringList datos = datbase.validarUsuario("usuarios", nombreUsuario, claveUsuario);
        if (!datos.isEmpty()) {

            qDebug() << "Inicio de sesión exitoso para el usuario:" << nombreUsuario;
             emit sesionIniciada();

        }
    }
}

