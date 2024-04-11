#include"log.h"
#include <QDebug>


#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

ven::ven(QWidget *parent) : QWidget(parent){
setWindowTitle("ventana");
nombre= new QLabel("nombre");
Enombre= new QLineEdit;
clave= new QLabel("clave");
Eclave= new QLineEdit;
Eclave->setEchoMode(QLineEdit::Password);
boton= new QPushButton("edit");
    pantalla = new QGridLayout(this);
    pantalla->addWidget(nombre,0,0);
    pantalla->addWidget(Enombre,0,1);
    pantalla->addWidget(clave,1,0);
    pantalla->addWidget(Eclave,1,1);
    pantalla->addWidget(boton,2,0);
     connect(boton, &QPushButton::clicked, this, &ven::checkPassword);

}
void ven::checkPassword() {
    QString enteredPassword = Eclave->text();
    if (enteredPassword == correctPassword) {
        this->close();
        Formulario *formulario = new Formulario;
        connect(formulario, &Formulario::contraseaCambiada, this, [this](const QString& nuevaContrasea) {
            // Actualizar la contraseña correcta con la nueva contraseña ingresada
            correctPassword = nuevaContrasea;
            qDebug() << "Contraseña cambiada exitosamente a:" << correctPassword;
        });
        formulario->show();
    } else {
        qDebug() << "Contraseña incorrecta. Acceso denegado.";
    }
}
