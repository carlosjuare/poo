#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QStringList>
#include <QVector>
#include <QDebug>

class AdminDB {
public:
    AdminDB();
    bool conectar(QString archivoSqlite); // Modificado el prototipo de la función conectar
    QStringList validarUsuario(QString tabla, QString usuario, QString clave);
    QVector<QStringList> select(QString comando);
    QSqlDatabase getDB();
    void consulta();
private:
    QSqlDatabase db;
};

#endif // ADMINDB_H#ifndef LOGIN_H
