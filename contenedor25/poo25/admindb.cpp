#include "admindb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>

AdminDB* AdminDB::instance = nullptr;

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase(dbName);
    // Obtener el directorio del proyecto
    QString projectDir = QCoreApplication::applicationDirPath();
    // Construir la ruta completa al archivo de base de datos
    QString pathToDb = QDir(projectDir).absoluteFilePath(dbPath);
    db.setDatabaseName(pathToDb);
    qDebug() << "Intentando abrir la base de datos en:" << db.databaseName();
    if (connectDB()) {
        // Realizar una consulta de prueba después de la conexión exitosa
        testQuery();
    }
}

AdminDB* AdminDB::getInstance()
{
    if (!instance) {
        instance = new AdminDB();
        if (!instance->connectDB()) {
            delete instance;
            instance = nullptr;
        }
    }
    return instance;
}

bool AdminDB::connectDB()
{
    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos:" << db.lastError().text();
        return false;
    }
    qDebug() << "Conexión exitosa a la base de datos SQLite";
    return true;
}

bool AdminDB::userExists(const QString &username, const QString &password)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM usuarios WHERE usuario = :username AND clave = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        return false;
    }
    return query.next();
}

bool AdminDB::addUser(const QString &username, const QString &password, const QString &nombre, const QString &apellido)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO usuarios (id, usuario, clave, nombre, apellido) VALUES (NULL, :username, :password, :nombre, :apellido)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":nombre", nombre);
    query.bindValue(":apellido", apellido);
    if (!query.exec()) {
        qDebug() << "Error al insertar usuario:" << query.lastError().text();
        return false;
    }
    qDebug() << "Usuario agregado correctamente a la base de datos";
    return true;
}

void AdminDB::testQuery()
{
    QSqlQuery query(db);
    query.prepare("SELECT id, usuario, clave, nombre, apellido FROM usuarios");
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta de prueba:" << query.lastError().text();
        return;
    }
    qDebug() << "Consulta de prueba ejecutada correctamente:";
    while (query.next()) {
        int id = query.value("id").toInt();
        QString username = query.value("usuario").toString();
        QString password = query.value("clave").toString(); // Agregamos la recuperación de la clave
        QString nombre = query.value("nombre").toString();
        QString apellido = query.value("apellido").toString();
        qDebug() << "ID:" << id << "Usuario:" << username << "Clave:" << password << "Nombre:" << nombre << "Apellido:" << apellido;
    }
}
