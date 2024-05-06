#include <QApplication>
#include"log.h"
#include"formulario.h"
#include<admindb.h>

int main(int a,char*b[]){
    QApplication app(a,b);
    ven login;


    login.show();
    adminDB aadminDB;
    if (aadminDB.conectar( "D:/Usuario Lab/Documentos/base-poo/mi_base_de_datos.db" ) )
        qDebug() << "Conexion exitosa";
    else
        qDebug() << "Conexion NO exitosa";
    aadminDB.consulta();


        return app.exec();





}
