#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "inicio.h"

class login: public QWidget{
       Q_OBJECT
public:
    login(QWidget *parent = nullptr);


public slots:
void checkPassword();
public:
    QLabel*nombre;
    QLineEdit*Enombre;
    QLabel*clave;
    QLineEdit*Eclave;
    QPushButton* boton;
    QGridLayout*pantalla;
 QString correctPassword = "1111";
  QString correctUser = "user";





};

#endif // LOGIN_H
