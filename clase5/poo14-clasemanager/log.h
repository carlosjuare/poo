#ifndef LOG_H
#define LOG_H

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



class ven : public QWidget {
    friend class Formulario;
    Q_OBJECT

public:
    ven(QWidget *parent = nullptr);


public slots:
    void checkPassword();
    void getWeather();
    void weatherReply(QNetworkReply *reply);
    void toggleTemperature();
     void cambiarClave(const QString& nuevaClave);
signals:
     void passwordCorrect();
private:
    QLabel *nombre;
    QLineEdit *Enombre;
    QLabel *clave;
    QLineEdit *Eclave;
    QPushButton *boton;
    QPushButton *botontemp;
    QGridLayout *pantalla;

    QString correctPassword = "1111";

    QLabel *temperatureLabel;
    QNetworkAccessManager *manager;
};

#endif // LOG_H
