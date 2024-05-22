#include "ventana.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ventana w;
    Login r;

    r.show();
    return a.exec();
}
