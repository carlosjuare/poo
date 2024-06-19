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
#include "formulario.h"
#include "admindb.h"

class QTimer;

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

signals:
    void usuarioAutenticado(QString nombreUsuario);

private slots:
    void getWeather();
    void weatherReply(QNetworkReply *reply);
    void toggleTemperature();
    void descargaimg(QNetworkReply *reply);
    void cambiarFondo();
    void bloquearUsuario();
    void desbloquearUsuario();
    void updateTime();
    void bloquearClave();
    void desbloquearClave();
    void slot_validar();
    void iniciarSesion();
    void validar3();

protected:
    void paintEvent(QPaintEvent *);

private:
    QLabel *nombre;
    QLineEdit *Enombre;
    QLabel *clave;
    QLineEdit *Eclave;
    QPushButton *boton;
    QPushButton *botontemp;
    QGridLayout *pantalla;
    QPushButton *cambiarFondoBtn;
    QLineEdit *urlImagen;
    QString correctPassword = "1111";
    QString correctUsuario = "nahuel";
    int intentosFallidos = 0;
    int intentosUsuario = 0;
    QTimer *bloqueoUsuarioTimer;

    QLabel *temperatureLabel;
    QNetworkAccessManager *manager;
    QNetworkAccessManager *descargaimagen;
    QImage im;
    QTimer *timer;
    QDateTime horaguardada;
    QLabel *ttime;
    adminDB datbase;
    Formulario form;
    QPushButton *validar2;
    QPushButton *valdar3;
};

#endif // LOGIN_H


