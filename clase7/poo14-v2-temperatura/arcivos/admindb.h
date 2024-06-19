


#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QObject>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QVector>

class adminDB : public QObject {
    Q_OBJECT

public:
    adminDB();
    bool conectar(QString archivoSqlite);
    QSqlDatabase getDB();
    void consulta();

    QStringList validarUsuario(QString tabla, QString usuario, QString clave);
    QVector<QStringList> select(QString comando);

private:
    QSqlDatabase db;
};
#endif // ADMINDB_H
