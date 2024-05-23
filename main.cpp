#include "ventana.h"
#include "login.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login r;

 r.show();


    return a.exec();
}
