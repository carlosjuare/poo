#include "admindb.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QCryptographicHash>
#include <QDebug>

AdminDB::AdminDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool AdminDB::conectar(QString archivoSqlite) {
    db.setDatabaseName(archivoSqlite);

    if (db.open())
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB() {
    return db;
}

void AdminDB::consulta() {
    QSqlQuery query("SELECT usuario, clave FROM usuarios", db);

    while (query.next()) {
        qDebug() << query.value(0).toString() << " " << query.value(1).toString();
    }
}

QStringList AdminDB::validarUsuario(QString tabla, QString usuario, QString clave) {
    QStringList datosPersonales;

    if (!db.isOpen())
        return datosPersonales;

    QString claveMd5 = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();

    QSqlQuery query(db);
    query.exec("SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" + usuario +
               "' AND clave = '" + claveMd5 + "'");

    if (query.next()) {
        datosPersonales << query.value("nombre").toString();
        datosPersonales << query.value("apellido").toString();
    }

    return datosPersonales;
}

QVector<QStringList> AdminDB::select(QString comando) {
    QVector<QStringList> resultados;

    if (!db.isOpen())
        return resultados;

    QSqlQuery consulta(db);
    consulta.exec(comando);

    while (consulta.next()) {
        QStringList registro;
        int numCampos = consulta.record().count();
        for (int i = 0; i < numCampos; ++i) {
            registro << consulta.value(i).toString();
        }
        resultados.append(registro);
    }

    return resultados;
}

