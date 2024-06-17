#include <QApplication>
#include "manager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear el Manager para mostrar la ventana de inicio de sesión
    Manager manager;

    return app.exec();
}
