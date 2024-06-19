#include <QApplication>
#include"login.h"
#include"formulario.h"

int main(int a,char*b[]){
    QApplication app(a,b);
    Login login;


    login.show();


        return app.exec();




}
