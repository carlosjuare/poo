#include <QApplication>
#include"Login.h"
#include"inicio.h"
int main(int a,char*b[]){
    QApplication app(a,b);
    login log;


    log.show();

        return app.exec();




}
