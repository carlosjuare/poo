#include "login.h"
#include "ui_login.h"
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->iniciars, SIGNAL(clicked()), this, SLOT(iniciar_secion()));
}

Login::~Login()
{
    delete ui;
}

bool Login::conectar(QString archivoSqlite)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(archivoSqlite);

    if (db.open())
        return true;

    return false;
}

QSqlDatabase Login::getDB()
{
    return db;
}

void Login::consulta()
{
    QSqlQuery query("SELECT usuario, clave FROM usuarios", db);

    while (query.next()) {
        qDebug() << query.value(0).toString() << " " << query.value(1).toString();
    }
    db.close();
}

void Login::iniciar_secion()
{
    QString usuario = ui->user->text();
    QString clave = ui->key->text();

    if (conectar("C:/Users/Lab/Desktop/ccontenedorapoo21/db2.db")) {
        QSqlQuery query(db);

        query.prepare("SELECT nombre, apellido FROM usuarios WHERE usuario = :usuario AND clave = :clave");
        query.bindValue(":usuario", usuario);
        query.bindValue(":clave", QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex());

        if (query.exec() && query.next()) {
            QString nombre = query.value(0).toString();
            QString apellido = query.value(1).toString();

            qDebug() << "Nombre:" << nombre << ", Apellido:" << apellido;
            QMessageBox::information(this, "Conexión exitosa", "Usuario válido");
             db.close();
            this->hide();
            ventanilla->setLogin(this);
            ventanilla->show();
        } else {
            QMessageBox::critical(this, "Error de inicio de sesión", "Usuario o contraseña incorrectos");
        }
    } else {
        QMessageBox::critical(this, "Error de conexión", "No se pudo conectar a la base de datos");
    }


}
