#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QPainter>
#include<QSqlRecord>
#include <QMouseEvent>
#include<QSqlQuery>
#include<QDebug>
#include"admindb.h"
#include"linea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QWidget
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
    void setearvalores();
protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Principal *ui;
Linea linea;
};
#endif // PRINCIPAL_H
