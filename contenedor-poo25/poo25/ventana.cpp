#include "ventana.h"
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Ventana::Ventana(QWidget *parent) : QWidget(parent), adminDB(AdminDB::getInstancia())
{
    setupTreeWidget();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(treeWidget);

    setLayout(layout);


    mostrarUsuarios();
}

Ventana::~Ventana()
{
    // No eliminamos adminDB aquí porque no somos propietarios de adminDB
}

void Ventana::mostrarUsuarios()
{
    if (!adminDB->conectar("../contenedor-poo25/usuariosDB.sqlite3")) {
        qDebug() << "Error al conectar a la base de datos.";
        return;
    }

    cargarDatos();
}

void Ventana::editarItem(QTreeWidgetItem *item, int column)
{
    if (item) {
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
}

void Ventana::setupTreeWidget()
{
    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(5);
    QStringList headers;
    headers << "ID" << "Nombre" << "Apellido" << "Nombre de usuario" << "Clave";
    treeWidget->setHeaderLabels(headers);

    connect(treeWidget, &QTreeWidget::itemDoubleClicked, this, &Ventana::editarItem);
}

void Ventana::cargarDatos()
{
    treeWidget->clear();

    QSqlDatabase db = adminDB->getDB();
    if (!db.isOpen()) {
        qDebug() << "La base de datos no está abierta.";
        return;
    }

    QSqlQuery query(db);
    QString consulta = "SELECT id, nombre, apellido, nusuario, clave FROM datosusuarios";
    if (query.exec(consulta)) {
        while (query.next()) {
            int id = query.value("id").toInt();
            QString nombre = query.value("nombre").toString();
            QString apellido = query.value("apellido").toString();
            QString nusuario = query.value("nusuario").toString();
            QString clave = query.value("clave").toString();

            QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
            item->setText(0, QString::number(id));
            item->setText(1, nombre);
            item->setText(2, apellido);
            item->setText(3, nusuario);
            item->setText(4, clave);

            treeWidget->addTopLevelItem(item);
        }
    } else {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
    }
}
