#include "admindb.h"

AdminDB* AdminDB::instancia = nullptr;

AdminDB::AdminDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

AdminDB* AdminDB::getInstancia() {
    if (instancia == nullptr) {
        instancia = new AdminDB;
    }
    return instancia;
}

bool AdminDB::conectar(const QString &archivoSqlite) {
    db.setDatabaseName(archivoSqlite);
    if (db.open()) {
        qDebug() << "Conexión a la base de datos exitosa.";
        return true;
    } else {
        qDebug() << "Error al abrir la base de datos:" << db.lastError().text();
        return false;
    }
}

QSqlDatabase AdminDB::getDB() {
    return db;
}

void AdminDB::mostrarDatosTabla() {
    if (db.isOpen()) {
        QSqlQuery query(db);
        QString consulta = "SELECT id, nombre, apellido, nusuario, clave FROM datosusuarios";
        if (query.exec(consulta)) {
            while (query.next()) {
                int id = query.value("id").toInt();
                QString nombre = query.value("nombre").toString();
                QString apellido = query.value("apellido").toString();
                QString nusuario = query.value("nusuario").toString();
                QString clave = query.value("clave").toString();

                qDebug() << "ID:" << id
                         << "Nombre:" << nombre
                         << "Apellido:" << apellido
                         << "Nombre de usuario:" << nusuario
                         << "Clave:" << clave;
            }
        } else {
            qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        }
    } else {
        qDebug() << "La base de datos no está abierta.";
    }
}
