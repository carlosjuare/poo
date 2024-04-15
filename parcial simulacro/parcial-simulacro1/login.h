#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "ventana.h"
class Login: public QWidget{
    Q_OBJECT

public:
    Login(QWidget*parent=nullptr);
    QLabel*nombre;
    QLabel*clave;
    QLineEdit*Enombre;
    QLineEdit*Eclave;
    QGridLayout* ventanalog;
    QPushButton*boton;
    QString vclave="332";
    QString vnombre="44347332";
    int a=0;

private:
    Ventana * ventana;

public slots:
    void check();

};

#endif // LOGIN_H
