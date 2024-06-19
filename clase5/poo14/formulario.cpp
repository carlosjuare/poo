 #include"formulario.h"
#include <QDebug>


#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

Formulario::Formulario(QWidget *parent) : QWidget(parent){
setWindowTitle("ventana");
hola= new QLabel("ingresar nueva contraseña");
edit=new QLineEdit;
editar=new QPushButton("cambiar ");


    pantalla2 = new QGridLayout(this);
    pantalla2->addWidget(hola,0,0);
     pantalla2->addWidget(edit,0,1);
      pantalla2->addWidget(editar,1,0);

      connect(editar, &QPushButton::clicked, this, [this]() {
             emit contraseaCambiada(edit->text());
         });



}
