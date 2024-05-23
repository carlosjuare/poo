#ifndef LOGIN_H
#define LOGIN_H

#include <QSqlDatabase>
#include <QStringList>
#include <QVector>
#include <QDebug>
#include <QObject>
#include "ventana.h"
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
    bool conectar(QString archivoSqlite);
    QSqlDatabase getDB();
    void consulta();

public slots:
    void iniciar_secion();

private:
    Ui::Login *ui;
    QSqlDatabase db;
    Ventana * ventanilla;
};

#endif // LOGIN_H
