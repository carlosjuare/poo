#ifndef MASTER_H
#define MASTER_H

#include <QObject>
#include "login.h"
#include "ventana.h"
#include "ingresarusuario.h"
class Master : public QObject
{
    Q_OBJECT

public:
    explicit Master(QObject *parent = nullptr);
    ~Master();

    void showLogin();
    void showMainWidget();
    void showOtherWindow();

private slots:
    void onLoginSuccessful();
    void onNavigateToOtherWindow();

private:
    Login *login;
    Ventana *ventana;
     IngresarUsuario *ingresarUsuario;
};
#endif // MASTER_H
