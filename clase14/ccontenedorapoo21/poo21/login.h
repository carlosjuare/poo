#ifndef LOGIN_H
#define LOGIN_H

#include <QSqlDatabase>
#include <QStringList>
#include <QVector>
#include <QDebug>
#include <QObject>

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool conectar(QString archivoSqlite); // Modificado el prototipo de la función conectar
       QSqlDatabase getDB();

public slots:
void iniciar_secion();
private:
    Ui::Login *ui;
       QSqlDatabase db;
};

#endif // LOGIN_H
