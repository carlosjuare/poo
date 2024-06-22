#include <QApplication>
#include "master.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Master master;
    master.showLogin();

    return a.exec();
}
