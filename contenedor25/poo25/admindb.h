#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>

class AdminDB : public QObject
{
    Q_OBJECT

public:
    static AdminDB* getInstance();
    bool connectDB();
    bool userExists(const QString& username, const QString& password);
    bool addUser(const QString& username, const QString& password, const QString& nombre, const QString& apellido);
   void testQuery();
private:
    explicit AdminDB(QObject *parent = nullptr);
    static AdminDB* instance;
    QSqlDatabase db;
    QString dbPath = "../base/db2.db ";
    QString dbName = "QSQLITE";
};

#endif // ADMINDB_H
