#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "admindb.h"

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "admindb.h"

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

    void mostrarUsuarios();

private slots:
    void editarItem(QTreeWidgetItem *item, int column);

private:
    QTreeWidget *treeWidget;
    AdminDB *adminDB;

    void setupTreeWidget();
    void cargarDatos();
};
#endif // VENTANA_H
