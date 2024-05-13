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
    QSqlQuery query("SELECT nombre, apellido FROM usuarios", db);

      while (query.next()) {
          qDebug() << query.value(0).toString() << " " << query.value(1).toString();
      }
}


