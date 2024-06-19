#ifndef MASTER_H
#define MASTER_H

#include <QObject>
#include "login.h"
#include "ventana.h"

class Master : public QObject
{
    Q_OBJECT
public:
    explicit Master(QObject *parent = nullptr);
    ~Master();

private:
    Login *login;
    Ventana *ventana;

public slots:
    void iniciar();

signals:
    void loginExitoso();

};

#endif // MASTER_H
