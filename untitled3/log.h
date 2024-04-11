#ifndef LOG_H
#define LOG_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class ven: public QWidget{
       Q_OBJECT
public:
    ven(QWidget *parent = nullptr);
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




};

#endif // LOG_H
