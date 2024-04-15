#include"login.h"
#include"Pantalla2.h"

Login::Login(QWidget *parent) : QWidget(parent){
    setWindowTitle("Login");
    //variables para texto
    nombre= new QLabel("usuario");
    clave= new QLabel("clave");

    //variables para ingresar
    Enombre=new QLineEdit;
    Eclave=new QLineEdit;
    Eclave->setEchoMode(QLineEdit::Password);

    //boton
    boton=new QPushButton("ingresar");
    ventanalog=new QGridLayout(this);

    //dibujo en la ventanalog this
    ventanalog->addWidget(nombre,0,0);
    ventanalog->addWidget(clave,1,0);
    ventanalog->addWidget(Enombre,0,1);
    ventanalog->addWidget(Eclave,1,1);
    ventanalog->addWidget(boton,2,2);

    ventana = new Ventana;

    connect(boton,&QPushButton::clicked,this,&Login::check);


}
void Login::check(){
    QString Claveingre=Eclave->text();
    QString Useringre=Enombre->text();
    pantalla2 * pa2= new pantalla2;
    if((Claveingre==vclave)&&(Useringre==vnombre)){
        this->close();
        ventana->show();


//        pa2->resize(100,100);
//        pa2->show();

    }else if(a<3){
        a++;
    }
        else if(a==3){
            this->close();
        }
     Eclave->clear();
    }



