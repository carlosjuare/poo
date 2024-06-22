#ifndef LISTAWINDOW_H
#define LISTAWINDOW_H




#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>

class ListaWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ListaWindow(QWidget *parent = nullptr);

private:
    QTreeWidget *treeWidget;
    QPushButton *closeButton;
     QPushButton *saveButton;
    void setupUI();
    void loadDataFromDatabase();

private slots:
    void closeApplication();
};

#endif // LISTAWINDOW_H
