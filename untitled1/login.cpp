#include "login.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

VentanaLogin ::VentanaLogin(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");

    // Creamos etiquetas para los campos de nombre de usuario y contraseña
    labelUsuario = new QLabel("Usuario:");
    labelApellido = new QLabel("Apellido:");
    labelContrasena = new QLabel("Contraseña:");
    labelLegajo = new QLabel("Legajo:");

    // Creamos campos de entrada de texto para el nombre de usuario y la contraseña
    editUsuario = new QLineEdit;
    editContrasena = new QLineEdit;
    editLegajo = new QLineEdit;
    editApellido = new QLineEdit;
    editContrasena->setEchoMode(QLineEdit::Password); // Para ocultar la contraseña

    // Creamos un botón para iniciar sesión
    botonIniciarSesion = new QPushButton("Iniciar Sesión");

    // Creamos un layout de cuadrícula y añadimos los widgets
    layout = new QGridLayout(this);
    layout->addWidget(labelUsuario, 0, 0);
    layout->addWidget(editUsuario, 0, 1);
    layout->addWidget(labelApellido, 1, 0);
    layout->addWidget(editApellido, 1, 1);
    layout->addWidget(labelLegajo, 2, 0);
    layout->addWidget(editLegajo, 2, 1);
    layout->addWidget(labelContrasena, 3, 0);
    layout->addWidget(editContrasena, 3, 1);
    layout->addWidget(botonIniciarSesion, 4, 0, 1, 2); // El botón ocupa dos columnas

    connect(botonIniciarSesion, &QPushButton::clicked, this, &VentanaLogin::comprobarContrasena);
}

void VentanaLogin::comprobarContrasena() {
    QString contrasena = editContrasena->text();
    if (contrasena == "1111") {
        QLabel *labelNuevaContrasena = new QLabel("Nueva Contraseña:");
        QLineEdit *editNuevaContrasena = new QLineEdit;
        editNuevaContrasena->setEchoMode(QLineEdit::Password);

        // Añadir nuevo campo de entrada de texto para la nueva contraseña
        layout->addWidget(labelNuevaContrasena, 5, 0);
        layout->addWidget(editNuevaContrasena, 5, 1);

        // Quitar la contraseña actual
        layout->removeWidget(editContrasena);
        layout->removeWidget(labelContrasena);
        delete editContrasena;
        delete labelContrasena;
        editContrasena = nullptr;
        labelContrasena = nullptr;
    }
}
