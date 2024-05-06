


#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QObject>
#include <QSqlQuery>

class adminDB : public QObject {
    Q_OBJECT

public:
    adminDB();
    bool conectar(QString archivoSqlite);
    QSqlDatabase getDB();
    void consulta();

private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
