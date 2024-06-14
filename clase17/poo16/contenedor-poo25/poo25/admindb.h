#ifndef ADMINDB_H
#define ADMINDB_H
#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlError>

class AdminDB : public QObject
{
    Q_OBJECT

public:
    static AdminDB *getInstancia();
    bool conectar(const QString &archivoSqlite);
    QSqlDatabase getDB();
    void mostrarDatosTabla();

private:
    explicit AdminDB();
    static AdminDB *instancia;
    QSqlDatabase db;
};
#endif // ADMINDB_H
