#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QLabel>

class Boton : public QWidget {
    Q_OBJECT

public:
    enum Color { Azul, Verde, Magenta, Teal };

    Boton(QWidget *parent = nullptr);

    void colorear(Color color);
    void setTexto( QString texto );

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QColor colorForEnum(Color color) const;

    Color color_;
    QLabel * lTexto;

signals:
    void signal_click();

};

#endif // BOTON_H
