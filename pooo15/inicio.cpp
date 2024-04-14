#include"inicio.h"
#include <QDebug>

#include <QRandomGenerator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

ini::ini(QWidget *parent) : QWidget(parent){
setWindowTitle("ventana");
int numeroAleatorio = QRandomGenerator::global()->bounded(10001);
nalt=new QLabel(QString::number(numeroAleatorio));
nombre= new QLabel("nombre:");
apellido= new QLabel("apellido:");
legajo= new QLabel("legajo");
Enombre= new QLineEdit("Nahuel");
Eapellido= new QLineEdit("juarez");
Elegajo= new QLineEdit("12345");
Ecapcha= new QLineEdit(QString::number(numeroAleatorio));
bot=new QPushButton("alta");



   pantala = new QGridLayout(this);
   pantala->addWidget(nombre,0,0);
   pantala->addWidget(apellido,1,0);
   pantala->addWidget(legajo,2,0);
    pantala->addWidget(Enombre,0,1);
    pantala->addWidget(Eapellido,1,1);
    pantala->addWidget(Elegajo,2,1);

    pantala->addWidget(bot,3,1);
      pantala->addWidget(nalt, 3, 0);
      pantala->addWidget(Ecapcha, 4, 0);


 connect(bot, &QPushButton::clicked, this, &ini::salir);




}
void ini::salir(){

    this->close();

}
