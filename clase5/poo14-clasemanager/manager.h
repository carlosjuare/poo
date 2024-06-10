#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "log.h"
#include "formulario.h"
class Manager : public QObject {
    Q_OBJECT

public:
    Manager();

    // Métodos para mostrar y ocultar la ventana de inicio de sesión
    void mostrarVentanaLogin();
    void ocultarVentanaLogin();
private slots:
    void cambiarClave(const QString& nuevaClave);
private:
    ven* ventanaLogin;
      Formulario* formulario;
};

#endif // MANAGER_H
