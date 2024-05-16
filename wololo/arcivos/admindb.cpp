#include "admindb.h"

adminDB::adminDB()
{
 db = QSqlDatabase::addDatabase( "QSQLITE" );
}
bool adminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

QSqlDatabase adminDB::getDB()  {
    return db;
}

void adminDB::consulta()
{
    QSqlQuery query("SELECT usuario, clave FROM usuarios", db);

      while (query.next()) {
          qDebug() << query.value(0).toString() << " " << query.value(1).toString();
      }
}
QStringList adminDB::validarUsuario( QString tabla, QString usuario, QString clave )  {

    QStringList datosPersonales;

    if ( ! db.isOpen() )
        return datosPersonales;

    QSqlQuery * query = new QSqlQuery( db );
    QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(),
                                                 QCryptographicHash::Md5 ).toHex();

    query->exec( "SELECT nombre, apellido FROM " +
                 tabla + " WHERE usuario = '" + usuario +
                 "' AND clave = '" + claveMd5 + "'" );

    while( query->next() )  {
        QSqlRecord registro = query->record();

        datosPersonales << query->value( registro.indexOf( "nombre" ) ).toString();
        datosPersonales << query->value( registro.indexOf( "apellido" ) ).toString();
    }

    return datosPersonales;
}



