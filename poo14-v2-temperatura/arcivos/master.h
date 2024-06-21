#ifndef MASTER_H
#define MASTER_H

#include <QWidget>
#include "log.h"
#include "formulario.h"

class Master : public QWidget
{
    Q_OBJECT

public:
    explicit Master(QWidget *parent = nullptr);

private slots:
    void gestionarInicioSesion();

private:
    Login *login;
    Formulario *formulario;
};

#endif // MASTER_H
