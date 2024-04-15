#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

class Ventana : public QWidget  {
    Q_OBJECT

public:
    Ventana();

private:
    QImage im;

protected:
    void paintEvent(QPaintEvent *);

};

#endif // VENTANA_H
