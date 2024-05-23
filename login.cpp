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

void Login::iniciar_secion() {

     this->hide();
    ventanilla->setLogin(this);
    ventanilla->show();



}
