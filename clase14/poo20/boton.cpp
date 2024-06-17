#include "boton.h"
#include <QPainter>

#include <QHBoxLayout>

Boton::Boton(QWidget *parent) : QWidget(parent), color_(Azul) {

    QHBoxLayout *layout = new QHBoxLayout(this);
    lTexto = new QLabel("Sin setear", this);
    layout->addWidget(lTexto);
    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);

}

void Boton::colorear(Color color) {
    color_ = color;
    update();
}

void Boton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), colorForEnum(color_));
}

void Boton::mousePressEvent(QMouseEvent *event)
{
    emit signal_click();
}

QColor Boton::colorForEnum(Color color) const {
    switch(color) {
        case Azul:
           return QColor(     43,87,151, 128);

        case Verde:
              return QColor(   153,180,51, 128);

        case Magenta:
           return QColor( 96,60,186, 128);

    case Teal:
         return QColor(0,171,169, 128);

        default:
            return Qt::black; // Default color
    }
}


void Boton::setTexto(QString texto)
{
    lTexto->setText( texto );
      lTexto->setStyleSheet("color: white;");
}


