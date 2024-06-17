#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

#include "basewidget.h"

class Login;

class Formulario : public QWidget, public BaseWidget {
    Q_OBJECT
    friend class Login; // Login puede acceder a los miembros privados de Formulario

public:
    explicit Formulario(QWidget *parent = nullptr);

    inline void showWidget() override {
        this->show();
    }

signals:
    void contraseaCambiada(const QString& nuevaContrasea);

private:
    QLabel *hola;
    QLineEdit *edit;
    QPushButton *editar;
    QGridLayout *pantalla2;
};

#endif // FORMULARIO_H
