#include "listawindow.h"
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QHeaderView>
#include <QPushButton>
#include <QApplication>
#include <QMessageBox> // Necesario para mostrar un mensaje de confirmación al salir

ListaWindow::ListaWindow(QWidget *parent) : QWidget(parent)
{
    setupUI();
    loadDataFromDatabase();
}

void ListaWindow::setupUI()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(4);

    QStringList headers;
    headers << "ID" << "Usuario" << "Nombre" << "Apellido";
    treeWidget->setHeaderLabels(headers);

    // Permitir edición en todos los ítems
    treeWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

    // Botón para cerrar la aplicación
    saveButton = new QPushButton("Cerrar aplicación", this);
    connect(saveButton, &QPushButton::clicked, this, &ListaWindow::closeApplication);

    layout->addWidget(treeWidget);
    layout->addWidget(saveButton);
}

void ListaWindow::loadDataFromDatabase()
{
    QSqlDatabase db = QSqlDatabase::database();

    QSqlQuery query(db);
    query.prepare("SELECT id, usuario, nombre, apellido FROM usuarios");

    if (!query.exec()) {
        qDebug() << "Error al ejecutar consulta:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString id = query.value(0).toString();
        QString usuario = query.value(1).toString();
        QString nombre = query.value(2).toString();
        QString apellido = query.value(3).toString();

        // Crear un nuevo ítem para cada fila
        QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
        item->setText(0, id);
        item->setText(1, usuario);
        item->setText(2, nombre);
        item->setText(3, apellido);

        // Permitir la edición visual pero no permitir la modificación en la base de datos
        for (int i = 0; i < 4; ++i) {
            if (i > 0) { // Permitir edición solo en las columnas 1 a 3 (usuario, nombre, apellido)
                item->setFlags(item->flags() | Qt::ItemIsEditable);
            }
        }

        treeWidget->addTopLevelItem(item);
    }
}

void ListaWindow::closeApplication()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cerrar aplicación", "¿Estás seguro de que deseas cerrar la aplicación?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}
