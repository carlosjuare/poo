#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QStringList>
#include <QVector>
#include <QDebug>
#include <QObject>

#include <QDialog>

class AdminDB
{
public:
    static AdminDB& getInstance() {
        static AdminDB instance;
        return instance;
    }

    bool conectar(const QString& archivoSqlite);
    QSqlDatabase getDB();

private:
    AdminDB();
    AdminDB(const AdminDB&) = delete;
    AdminDB& operator=(const AdminDB&) = delete;
    ~AdminDB() = default;

    QSqlDatabase db;
};

#endif // ADMINDB_H
