#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Login; // Declaración anticipada de la clase Login

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();
    void volverlogin();

    void setLogin(Login *log);

private:
    Ui::Ventana *ui;
    Login *log;
};

#endif // VENTANA_H

