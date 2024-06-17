#include <QApplication>
#include <QPushButton>
#include "mapa.h"
#include "login.h"

int main( int argc, char** argv )  {
    QApplication a( argc, argv );
    QPushButton* boton = new QPushButton( "Salir" );

    QObject::connect( boton, SIGNAL( pressed() ), &a, SLOT( quit() ) );
    boton->setVisible( true );

    Login login;
    login.show();

    Mapa mapa;
    mapa.show();

    return a.exec();
}
