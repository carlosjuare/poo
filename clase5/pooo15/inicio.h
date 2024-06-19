#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class ini : public QWidget {
    Q_OBJECT
public:
    ini(QWidget *parent = nullptr);

public slots:
void salir();
private:
     QLabel*nombre;
      QLabel*apellido;
       QLabel*legajo;

        QLineEdit*Enombre;
        QLineEdit*Eapellido;
        QLineEdit*Elegajo;
        QLineEdit*Ecapcha;

       QLabel*nalt;
       QPushButton* bot;
    QGridLayout*pantala;


};
#endif // INICIO_H
