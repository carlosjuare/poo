#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>

#include "admindb.h"

class QTimer;

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

signals:
    void sesionIniciada();

private slots:

    void iniciarSesion();






private:
    QLabel *nombre;
    QLineEdit *Enombre;
    QLabel *clave;
    QLineEdit *Eclave;
    QPushButton *botonIniciarSesion;
    QPushButton *botontemp;
    QGridLayout *pantalla;

    adminDB datbase;

};


#endif // LOGIN_H


