#include "ventanadibujo.h"
#include "ui_ventanadibujo.h"
#include <QDebug>

#include <QMouseEvent>

ventanadibujo::ventanadibujo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ventanadibujo)
{
    ui->setupUi(this);
}

ventanadibujo::~ventanadibujo()
{
    delete ui;
}



void ventanadibujo::mouseMoveEvent(QMouseEvent *event)
{
    puntos.append(event->pos());

           // Indica que el widget necesita ser repintado para mostrar el nuevo punto
    update();
}



void ventanadibujo::paintEvent(QPaintEvent *event)
{
    // Llama al método base
        QWidget::paintEvent(event);

        // Crea un objeto QPainter para dibujar en el widget
        QPainter painter(this);

        // Establece el pincel en azul
        painter.setPen(QPen(colorPintura,tampincel));

        // Dibuja todos los puntos almacenados
        for (const QPoint &punto : puntos) {
                  painter.drawPoint(punto);
              }
}

void ventanadibujo::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_R) {
        colorPintura = Qt::red;
                  update();

     }else if(event->key() == Qt::Key_G){
        colorPintura = Qt::yellow;
                  update();
    }else if(event->key() == Qt::Key_B){
        colorPintura = Qt::blue;
                  update();
    }else if(event->key() == Qt::Key_Escape){
        puntos.clear();
                   update();
    }else if(event->key() == Qt::Key_Plus){
       tampincel += 1;
    }else if(event->key() == Qt::Key_Minus){
         tampincel -= 1;
    }
}



