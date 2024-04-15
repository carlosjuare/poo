#include <QApplication>
#include"login.h"
#include"Pantalla2.h"
int main(int a,char*b[]){
    QApplication app(a,b);
    Login log;
    log.resize(250,120);
    log.show();
    return app.exec();
}
