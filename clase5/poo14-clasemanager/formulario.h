#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "log.h"

class Formulario : public QWidget {
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);

signals:
    void nuevaClave(const QString& nuevaClave);

private:
    QLabel* hola;
    QLineEdit* edit;
    QPushButton* editar;
    QGridLayout* pantalla2;
    ven* venObj;
};

#endif // FORMULARIO_H



