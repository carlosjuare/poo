#ifndef OTRAVENTANA_H
#define OTRAVENTANA_H
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


class Ventana : public QWidget {
    Q_OBJECT

   public:
       Ventana(QWidget *parent = nullptr);

   protected:
       void paintEvent(QPaintEvent *) override;

   private slots:
       void descargaimg(QNetworkReply* reply);
       void cambiarFondo();

   private:
       QNetworkAccessManager *descargaimagen;
       QImage im;
       QString urlImagen2 = "https://img.freepik.com/fotos-premium/imagen-jpg-alta-resolucion-fondo-degradado-textura-papel-ruidoso-retro_820074-1555.jpg?size=626&ext=jpg&ga=GA1.1.1687694167.1713657600&semt=sph";
   };

#endif // OTRAVENTANA_H
