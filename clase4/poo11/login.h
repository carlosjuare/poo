#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Login : public QWidget {
    Q_OBJECT

private:
    QLabel * Usuario, *Clave;
    QLineEdit *leUsuario, *leClave;
    QPushButton *Entrar;
    QGridLayout * layout;

private slots:
    void slot_validarUsuario();

public:
    Login();
};

#endif // LOGIN_H
