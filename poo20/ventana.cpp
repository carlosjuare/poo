#include "ventana.h"
#include "ui_ventana.h"
#include <QPainter>

ventana::ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ventana)
{
    ui->setupUi(this);

     ui->boton1->colorear(Boton::Teal);
    ui->boton2->colorear(Boton::Verde);
    ui->boton3->colorear(Boton::Azul);
    ui->boton4->colorear(Boton::Magenta);
    ui->boton5->colorear(Boton::Azul);


    ui->boton1->setTexto( "Mi dentista" );
    ui->boton2->setTexto( "Visitas" );
    ui->boton3->setTexto( "Tecnicas de higiene" );
    ui->boton4->setTexto( "Mi boca" );
    ui->boton5->setTexto( "Hora de cepillarse" );

    ui->boton1->setWindowOpacity(0.5);

     fondo = QImage("D:/Usuario Lab/Documentos/poo20/fondo1.jpg");
    connect(ui->boton1, SIGNAL(signal_click()), this,SLOT(close()));
}

ventana::~ventana()
{
    delete ui;
}

void ventana::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawImage(0, 0, fondo.scaled(size()));
}
