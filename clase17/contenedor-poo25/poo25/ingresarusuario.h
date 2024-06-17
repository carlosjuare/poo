#ifndef INGRESARUSUARIO_H
#define INGRESARUSUARIO_H


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "admindb.h"

class IngresarUsuario : public QWidget
{
    Q_OBJECT

public:
    explicit IngresarUsuario(QWidget *parent = nullptr);
    ~IngresarUsuario();

private slots:
    void agregarUsuario();

private:
    QLineEdit *nombreLineEdit;
    QLineEdit *apellidoLineEdit;
    QLineEdit *nusuarioLineEdit;
    QLineEdit *claveLineEdit;
    QPushButton *agregarButton;
    AdminDB *adminDB;

    void limpiarCampos();
};

#endif // INGRESARUSUARIO_H
