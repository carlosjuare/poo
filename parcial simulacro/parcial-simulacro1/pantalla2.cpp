#include "Pantalla2.h"
#include <QDebug>

pantalla2::pantalla2(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Ventana");
    QPixmap imagen("C:/Users/LAB400-PCXX/Download/images.jpg");
    if(imagen.isNull()) {
        qDebug() << "Error al cargar la imagen";
    }
  QLabel* im=new QLabel;
   im->setPixmap(imagen);
    p2 = new QGridLayout;
    p2->addWidget(im, 0, 1);
    setLayout(p2);
}
