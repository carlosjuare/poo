#include "admindb.h"

AdminDB::AdminDB()
{

}

bool AdminDB::conectar(const QString& archivoSqlite)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(archivoSqlite);

    if (db.open())
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()
{
    return db;
}
