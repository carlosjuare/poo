#include "descarga.h"
#include "otraventana.h" // Suponiendo que Ventana está definida en otraentana.h

#include <QPainter>
#include <QDebug>

ven::ven(QWidget *parent) : QWidget(parent) {
    descargaimagen = new QNetworkAccessManager(this);
    connect(descargaimagen, SIGNAL(finished(QNetworkReply*)), this, SLOT(descargaimg(QNetworkReply*)));

    urlImagen = "https://www.img2go.com/assets/dist/sample-files/img/convert_to_image.png";
    cambiarFondo(); // Descargar la imagen desde la URL

    nombre = new QLabel("nombre");
    Enombre = new QLineEdit;
    clave = new QLabel("clave");
    Eclave = new QLineEdit;
    Eclave->setEchoMode(QLineEdit::Password);

    boton = new QPushButton("Iniciar sesión");

    pantalla = new QGridLayout(this);
    pantalla->addWidget(nombre, 0, 0);
    pantalla->addWidget(Enombre, 0, 1);
    pantalla->addWidget(clave, 1, 0);
    pantalla->addWidget(Eclave, 1, 1);
    pantalla->addWidget(boton, 3, 0);

    connect(boton, SIGNAL(clicked()), this, SLOT(redirigir()));
}

void ven::descargaimg(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error al descargar la imagen:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    im = QImage::fromData(reply->readAll());
    if (im.isNull()) {
        qDebug() << "Error: Los datos descargados no forman una imagen válida";
        reply->deleteLater();
        return;
    }

    reply->deleteLater();
    update();
}

void ven::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if (!im.isNull()) {
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.drawImage(rect(), im, im.rect());
    } else {
        // Si no se ha descargado ninguna imagen, puedes pintar un color de fondo alternativo
        painter.fillRect(rect(), Qt::white); // Cambia Qt::white por el color que desees
    }
}
void ven::cambiarFondo() {
    QUrl imageUrl(urlImagen);
    QNetworkRequest request(imageUrl);
    descargaimagen->get(request);
}

void ven::redirigir() {
    // Verificar si la clave ingresada es correcta
    if (Eclave->text() == correctPassword) {
        // Ocultar la ventana actual (ven)
        hide();

        // Crear una instancia de la nueva ventana (Ventana)
        Ventana *nuevaVentana = new Ventana();

        // Mostrar la nueva ventana (Ventana)
        nuevaVentana->show();
    }
}
