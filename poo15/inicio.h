#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include <QGridLayout>
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
    QLabel *nombreLabel;
    QLabel *apellidoLabel;
    QLabel *legajoLabel;
    QLabel *naltLabel;
    QLineEdit *Enombre;
    QLineEdit *Eapellido;
    QLineEdit *Elegajo;
    QLineEdit *Ecapcha;
    QPushButton *bot;
    QGridLayout *pantala;

};
#endif // INICIO_H
