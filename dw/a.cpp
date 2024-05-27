#include <QObject>
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
class Descargador : public QObject {
    Q_OBJECT

public:
    explicit Descargador(QObject *parent = nullptr) : QObject(parent) {
        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(descargaFinalizada(QNetworkReply*)));
    }

    void descargarImagen(const QString &url) {
        QUrl imageUrl(url);
        QNetworkRequest request(imageUrl);
        manager->get(request);
    }

signals:
    void imagenDescargada(const QImage &imagen);
    void error(const QString &mensaje);

private slots:
    void descargaFinalizada(QNetworkReply *reply) {
        if (reply->error() != QNetworkReply::NoError) {
            emit error(reply->errorString());
            reply->deleteLater();
            return;
        }

        QImage imagen = QImage::fromData(reply->readAll());
        if (imagen.isNull()) {
            emit error("Los datos descargados no forman una imagen válida");
            reply->deleteLater();
            return;
        }

        emit imagenDescargada(imagen);
        reply->deleteLater();
    }

private:
    QNetworkAccessManager *manager;
};
class PintorFondo : public QWidget {
    Q_OBJECT

public:
    explicit PintorFondo(QWidget *parent = nullptr) : QWidget(parent) {}

    void establecerImagenDeFondo(const QImage &imagen) {
        imagenFondo = imagen;
        update();
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        if (!imagenFondo.isNull()) {
            painter.setRenderHint(QPainter::SmoothPixmapTransform);
            painter.drawImage(rect(), imagenFondo, imagenFondo.rect());
        } else {
            painter.fillRect(rect(), Qt::white); // Cambia Qt::white por el color que desees
        }
    }

private:
    QImage imagenFondo;
};

class PantallaConFondo : public QWidget {
    Q_OBJECT

public:
    PantallaConFondo(QWidget *parent = nullptr) : QWidget(parent) {
        descargaimagen = new Descargador(this);
        connect(descargaimagen, SIGNAL(imagenDescargada(QImage)), this, SLOT(establecerFondo(QImage)));
        connect(descargaimagen, SIGNAL(error(QString)), this, SIGNAL(errorDescarga(QString)));

        urlImagen = "https://www.img2go.com/assets/dist/sample-files/img/convert_to_image.png";
        descargaimagen->descargarImagen(urlImagen);

        nombre = new QLabel("nombre");
        Enombre = new QLineEdit;
        clave = new QLabel("clave");
        Eclave = new QLineEdit;
        Eclave->setEchoMode(QLineEdit::Password);

        boton = new QPushButton("Iniciar sesión");
        connect(boton, SIGNAL(clicked()), this, SLOT(redirigir()));

        pantalla = new QGridLayout(this);
        pantalla->addWidget(nombre, 0, 0);
        pantalla->addWidget(Enombre, 0, 1);
        pantalla->addWidget(clave, 1, 0);
        pantalla->addWidget(Eclave, 1, 1);
        pantalla->addWidget(boton, 3, 0);
    }

signals:
    void errorDescarga(const QString &mensaje);

private slots:
    void establecerFondo(const QImage &imagen) {
        pintorFondo = new PintorFondo(this);
        pintorFondo->establecerImagenDeFondo(imagen);
    }

    void redirigir() {
        // Implementa la lógica para redirigir si es necesario
    }

private:
    Descargador *descargaimagen;
    PintorFondo *pintorFondo;
    QLabel *nombre;
    QLineEdit *Enombre;
    QLabel *clave;
    QLineEdit *Eclave;
    QPushButton *boton;
    QGridLayout *pantalla;
    QString urlImagen;
};
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    PantallaConFondo pantalla;
    pantalla.show();

    return a.exec();
}
