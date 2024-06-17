#include "mapa.h"

Mapa::Mapa(QWidget *parent) : QWidget(parent)
{
   image.load("D:\Usuario Lab\Descargas\images.jpg"); // Carga la imagen en la ruta especificada
}

void Mapa::paintEvent(QPaintEvent *event) {
   QPainter painter(this);
   painter.drawLine(0, 0, width(), height()); // Dibuja una línea diagonal de la esquina superior izquierda a la inferior derecha
   painter.drawImage(0, 0, image); // Dibuja la imagen en la esquina superior izquierda del widget
}
