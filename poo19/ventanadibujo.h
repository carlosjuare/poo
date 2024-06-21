#ifndef VENTANADIBUJO_H
#define VENTANADIBUJO_H

#include <QWidget>
#include<QDebug>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class ventanadibujo; }
QT_END_NAMESPACE

class ventanadibujo : public QWidget
{
    Q_OBJECT

public:
    ventanadibujo(QWidget *parent = nullptr);
    ~ventanadibujo();

private:
    Ui::ventanadibujo *ui;
     QVector<QPoint> puntos;
       QColor colorPintura;
       int tampincel=0;
protected:
    virtual void mouseMoveEvent( QMouseEvent * event );

     virtual void paintEvent( QPaintEvent * event );
     virtual void keyPressEvent( QKeyEvent * event );


};
#endif // VENTANADIBUJO_H
