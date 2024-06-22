#include <QApplication>
#include"masterwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crear e inicializar la ventana principal
   MasterWidget w;
    w.show();

    return a.exec();
}
