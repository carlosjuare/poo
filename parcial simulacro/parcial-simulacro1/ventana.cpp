

#include "ventana.h"

#include <QPainter>
#include <QRect>

Ventana::Ventana() {
    im.load("D:/Usuario Lab/Documentos/imagenes/images.jpg");
       im = im.scaled(100,100, Qt::KeepAspectRatio);
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    // Obtener las dimensiones de la ventana
    int ventanaAncho = width();
    int ventanaAlto = height();

    // Obtener las dimensiones de la imagen
    int imagenAncho = im.width();
    int imagenAlto = im.height();

    // Calcular las coordenadas para centrar la imagen
    int x = (ventanaAncho - imagenAncho) / 2;
    int y = (ventanaAlto - imagenAlto) / 2;

    // Dibujar la imagen centrada
    painter.setPen(QPen(Qt::black, 2)); // Establecer el color y el grosor del borde
       painter.drawRect(x - 5, y - 5, imagenAncho + 10, imagenAlto + 10); // Dibujar el borde alrededor de la imagen

       // Dibujar la imagen centrada
       painter.drawImage(QRect(x, y, imagenAncho, imagenAlto), im);
}
