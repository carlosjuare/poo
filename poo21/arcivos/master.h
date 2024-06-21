#ifndef MASTER_H
#define MASTER_H

#include <QWidget>
#include "log.h"        // Incluir el header de Login
#include "formulario.h" // Incluir el header de Formulario

class Master : public QWidget {
    Q_OBJECT

public:
    Master(QWidget *parent = nullptr);

public slots:
    void mostrarLogin();      // Slot para mostrar la ventana de Login
    void mostrarFormulario(); // Slot para mostrar la ventana de Formulario

private:
    Login *loginWidget;        // Instancia de la clase Login
    Formulario *formularioWidget; // Instancia de la clase Formulario
};

#endif // MASTER_H
