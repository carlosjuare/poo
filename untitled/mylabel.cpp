#include "mylabel.h"
#include <QPixmap>

MyLabel::MyLabel(const QString &imagePath, QWidget *parent) : QLabel(parent) {
    // Cargar la imagen desde el archivo especificado en la ruta
    QPixmap image(imagePath);
    if (!image.isNull()) {
        setPixmap(image.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}
