// log.h
#ifndef LOG_H
#define LOG_H

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

#include "formulario.h"

class ven : public QWidget {
    Q_OBJECT

public:
    ven(QWidget *parent = nullptr);

public slots:
    void checkPassword();
    void getWeather();
    void weatherReply(QNetworkReply *reply);
    void toggleTemperature();
    void descargaimg(QNetworkReply*reply);
     void cambiarFondo();

private:
    QLabel *nombre;
    QLineEdit *Enombre;
    QLabel *clave;
    QLineEdit *Eclave;
    QPushButton *boton;
    QPushButton *botontemp;
    QGridLayout *pantalla;

    QPushButton *cambiarFondoBtn; // Nuevo botón para cambiar el fondo
    QLineEdit *urlImagen;

    QString correctPassword = "1111";

    QLabel *temperatureLabel;
    QNetworkAccessManager *manager;
    QNetworkAccessManager *descargaimagen;
    QImage im;
protected:
   void paintEvent(QPaintEvent *);


};

#endif // LOG_H


