#include "ventana.h"
#include "login.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login r;
    if (r.conectar("C:/Users/Lab/Desktop/ccontenedorapoo21/db2.db")) {
        r.consulta();
 r.show();
    } else {
        qDebug() << "Error al conectar a la base de datos";
    }

    return a.exec();
}
