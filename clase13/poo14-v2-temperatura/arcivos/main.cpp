#include <QApplication>
#include"log.h"
#include"formulario.h"
#include"admindb.h"

int main(int a,char*b[]){
    QApplication app(a,b);
    Login login;


    login.show();



        return app.exec();





}
