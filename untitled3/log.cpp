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
void ven::checkPassword(){
    QString enteredPassword = Eclave->text();
       if (enteredPassword == correctPassword) {
           // La contraseña ingresada es correcta
           qDebug() << "¡Contraseña correcta! Acceso permitido.";
       } else {
           // La contraseña ingresada es incorrecta
           qDebug() << "Contraseña incorrecta. Acceso denegado.";
       }
}
