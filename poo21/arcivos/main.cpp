#include <QApplication>
#include "master.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Master master;
    master.show(); // Mostrar el widget principal (Master)

    return a.exec();
}
