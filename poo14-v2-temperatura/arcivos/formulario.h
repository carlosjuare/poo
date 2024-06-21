#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include"admindb.h"
class Formulario : public QWidget {
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
signals:
    void contraseaCambiada(const QString& nuevaContrasea);
private:
     QLabel*hola;
     QLineEdit* edit;
     QPushButton*editar;
      QGridLayout*pantalla2;


};

#endif // FORMULARIO_H
