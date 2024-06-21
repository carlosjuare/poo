#include "paser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Paser w;
    w.show();
    return a.exec();
}
