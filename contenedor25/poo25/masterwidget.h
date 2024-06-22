#ifndef MASTERWIDGET_H
#define MASTERWIDGET_H

#include <QWidget>
#include "login.h"
#include "listawindow.h"

class MasterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MasterWidget(QWidget *parent = nullptr);

private slots:
    void onLoginSuccessful();

private:
    Login *login;
    ListaWindow *listaWindow;
};

#endif // MASTERWIDGET_H
