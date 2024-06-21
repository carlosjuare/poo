#include <QApplication>
#include"descarga.h"
#include"otraventana.h"

int main(int a,char*b[]){
    QApplication app(a,b);
    ven log;
    log.resize(250,120);
    log.show();
    return app.exec();
}
