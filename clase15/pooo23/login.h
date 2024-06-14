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
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

#include "formulario.h"

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

public slots:
    void checkPassword();
    void getWeather();
    void weatherReply(QNetworkReply *reply);
    void toggleTemperature();

private:
    QLabel *nombre;
    QLineEdit *Enombre;
    QLabel *clave;
    QLineEdit *Eclave;
    QPushButton *boton;
    QPushButton *botontemp;
    QGridLayout *pantalla;

    QLabel *errorLabel; // Para mostrar mensajes de error

    QLabel *temperatureLabel;
    QNetworkAccessManager *manager;

    QString correctUser = "admin";
    QString correctPassword = "1111";
};

#endif // LOGIN_H
