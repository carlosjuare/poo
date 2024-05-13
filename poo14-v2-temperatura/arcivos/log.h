#ifndef LOG_H
#define LOG_H
#include<QMessageBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>
#include <QTimer>
#include "formulario.h"
#include"admindb.h"

class QTimer;

class ven : public QWidget {
    Q_OBJECT

public:
    ven(QWidget *parent = nullptr);

public slots:

    void getWeather();
    void weatherReply(QNetworkReply *reply);
    void toggleTemperature();
    void descargaimg(QNetworkReply*reply);
    void cambiarFondo();
   void bloquearUsuario();
   void desbloquearUsuario();
   void updateTime();
   void bloquearClave();
   void desbloquearClave();
   void slot_validar();

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

protected:
    void paintEvent(QPaintEvent *);
};

#endif // LOG_H


