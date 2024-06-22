
#include "admindb.h"
#include <QCoreApplication>
#include <QDir>
adminDB::adminDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool adminDB::conectar(QString archivoSqlite)
{
    // Obtener el directorio del proyecto
      QString projectDir = QCoreApplication::applicationDirPath();

      // Construir la ruta completa al archivo de base de datos
      QString pathToDb = QDir(projectDir).absoluteFilePath("../atabase/db2.db");

      // Establecer el nombre de la base de datos
      db.setDatabaseName(pathToDb);

      // Intentar abrir la base de datos
      if (!db.open()) {
          qDebug() << "Error al abrir la base de datos:" ;
          return false;
      }

      qDebug() << "Conexión exitosa";
      return true;
}

QSqlDatabase adminDB::getDB()
{
    return db;
}

void adminDB::consulta()
{
    QSqlQuery query("SELECT nombre, apellido, usuario, clave, id FROM usuarios", db);

    while (query.next()) {
        qDebug() << "nombre:" << query.value("nombre").toString()
                 << "apellido:" << query.value("apellido").toString()
                 << "usuario:" << query.value("usuario").toString()
                 << "clave:" << query.value("clave").toString()
                 << "id:" << query.value("id").toString();
    }
}

QStringList adminDB::validarUsuario(QString tabla, QString usuario, QString clave)
{
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

QVector<QStringList> adminDB::select(QString comando)
{
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
