#include"login.h"
#include <QDebug>


#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
login::login(QWidget *parent) : QWidget(parent){
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
connect(boton, &QPushButton::clicked, this, &login::checkPassword);

}
void login::checkPassword() {
    QString enteredPassword = Eclave->text();
     QString enteredUser = Enombre->text();
    if ((enteredPassword == correctPassword)&&(enteredUser==correctUser)) {
        this->close();
        ini *inicio = new ini;

        inicio->show();
    } else {
      this->close();
    }
}
