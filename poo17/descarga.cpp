#include "descarga.h"
#include "otraventana.h"

#include <QPainter>
#include <QDebug>

ven::ven(QWidget *parent) : QWidget(parent) {
    descargaimagen = new QNetworkAccessManager(this);
    connect(descargaimagen, SIGNAL(finished(QNetworkReply*)), this, SLOT(descargaimg(QNetworkReply*)));

    urlImagen = "https://www.img2go.com/assets/dist/sample-files/img/convert_to_image.png";
    cambiarFondo();

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

        painter.fillRect(rect(), Qt::white);
    }
}
void ven::cambiarFondo() {
    QUrl imageUrl(urlImagen);
    QNetworkRequest request(imageUrl);
    descargaimagen->get(request);
}

void ven::redirigir() {

    if (Eclave->text() == correctPassword) {

        hide();


        Ventana *nuevaVentana = new Ventana();


        nuevaVentana->show();
    }
}
