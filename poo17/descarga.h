
#ifndef DESCARGA_H
#define DESCARGA_H

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


class QLineEdit;

class ven : public QWidget {
    Q_OBJECT

public:
    ven(QWidget *parent = nullptr);

private slots:
    void descargaimg(QNetworkReply* reply);

public slots:
    void redirigir();
    void cambiarFondo();
private:

    QLabel *nombre;
     QLineEdit *Enombre;
     QLabel *clave;
     QLineEdit *Eclave;
     QPushButton *boton;
     QGridLayout *pantalla;

      QString correctPassword = "1111";


    QNetworkAccessManager *descargaimagen;
    QImage im;
    QString urlImagen;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // DESCARGA_H
