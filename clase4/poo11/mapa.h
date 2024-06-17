#ifndef MAPA_H
#define MAPA_H
#include <QtWidgets>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPainter>

class Mapa : public QWidget {
    Q_OBJECT // Agrega esta línea

protected:
    void paintEvent(QPaintEvent * e);
private:
    QImage image;
public:
    Mapa(QWidget *parent = nullptr);

};

#endif // MAPA_H

