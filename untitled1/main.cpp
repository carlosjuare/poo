#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    VentanaLogin ventana;
    ventana.show();

    return app.exec();
}

