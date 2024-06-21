#include "otraventana.h"
#include <QPainter>
#include <QDebug>

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    descargaimagen = new QNetworkAccessManager(this);
    connect(descargaimagen, SIGNAL(finished(QNetworkReply*)), this, SLOT(descargaimg(QNetworkReply*)));

    cambiarFondo();
}

void Ventana::descargaimg(QNetworkReply *reply) {
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

void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if (!im.isNull()) {
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.drawImage(rect(), im, im.rect());
    } else {
        painter.fillRect(rect(), Qt::white);
    }
}

void Ventana::cambiarFondo() {
    QUrl imageUrl(urlImagen2);
    QNetworkRequest request(imageUrl);
    descargaimagen->get(request);
}
