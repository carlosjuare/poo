#include "ventanadibujo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ventanadibujo w;
    w.show();
    return a.exec();
}
