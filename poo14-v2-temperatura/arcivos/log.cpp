// log.cpp
#include "log.h"
#include <QPainter>
#include <QDebug>
#include <QResizeEvent>

ven::ven(QWidget *parent) : QWidget(parent) {

    descargaimagen = new QNetworkAccessManager(this);
    connect(descargaimagen, SIGNAL(finished(QNetworkReply*)), this, SLOT(descargaimg(QNetworkReply*)));




    setWindowTitle("ventana");

    nombre = new QLabel("nombre");
    Enombre = new QLineEdit;
    clave = new QLabel("clave");
    Eclave = new QLineEdit;
    Eclave->setEchoMode(QLineEdit::Password);

    boton = new QPushButton("Iniciar sesión");
    botontemp = new QPushButton("Mostrar/Ocultar temperatura");

    cambiarFondoBtn = new QPushButton("Cambiar Fondo"); // Nuevo botón para cambiar el fondo
    urlImagen = new QLineEdit; // Nuevo campo de texto para ingresar la URL de la imagen
    urlImagen->setPlaceholderText("Ingrese URL de la imagen");



    pantalla = new QGridLayout(this);
    pantalla->addWidget(nombre, 0, 0);
    pantalla->addWidget(Enombre, 0, 1);
    pantalla->addWidget(clave, 1, 0);
    pantalla->addWidget(Eclave, 1, 1);
    pantalla->addWidget(botontemp, 2, 0); // Botón para mostrar/ocultar temperatura
    pantalla->addWidget(boton, 3, 0); // Botón para iniciar sesión

    pantalla->addWidget(urlImagen, 4, 0, 1, 2); // Campo de texto para ingresar la URL de la imagen
    pantalla->addWidget(cambiarFondoBtn, 5, 0, 1, 2); // Nuevo botón para cambiar el fondo



    temperatureLabel = new QLabel("Temperatura de Córdoba: Cargando...");
    pantalla->addWidget(temperatureLabel, 2, 1); // Etiqueta de temperatura

    connect(boton, &QPushButton::clicked, this, &ven::checkPassword);
    connect(botontemp, &QPushButton::clicked, this, &ven::toggleTemperature);
     connect(cambiarFondoBtn, &QPushButton::clicked, this, &ven::cambiarFondo); // Conectar el nuevo botón

    // Inicialmente obtener la temperatura
    getWeather();
}

void ven::checkPassword() {
    QString enteredPassword = Eclave->text();
    if (enteredPassword == correctPassword) {
        this->close();
        Formulario *formulario = new Formulario;
        connect(formulario, &Formulario::contraseaCambiada, this, [this](const QString& nuevaContrasea) {
            // Actualizar la contraseña correcta con la nueva contraseña ingresada
            correctPassword = nuevaContrasea;
            qDebug() << "Contraseña cambiada exitosamente a:" << correctPassword;
        });
        formulario->show();
    } else {
        qDebug() << "Contraseña incorrecta. Acceso denegado.";
    }
}

void ven::getWeather() {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &ven::weatherReply);
    QUrl url("http://api.openweathermap.org/data/2.5/weather?q=Cordoba&appid=1f101cc43962da830035160fe4f2202c");
    manager->get(QNetworkRequest(url));
}



void ven::weatherReply(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(responseData);
        QJsonObject obj = json.object();
        QJsonObject main = obj["main"].toObject();
        double temperature = main["temp"].toDouble() - 273.15; // Kelvin a Celsius
        temperatureLabel->setText(QString("Temperatura de Córdoba: %1 °C").arg(temperature));
    } else {
        qDebug() << "Error al obtener la temperatura:" << reply->errorString();
    }

    reply->deleteLater();
}

void ven::toggleTemperature() {
    temperatureLabel->setVisible(!temperatureLabel->isVisible());
}




void ven::descargaimg(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error al descargar la imagen:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    im = QImage::fromData(reply->readAll());
    if (im.isNull()) {
        qDebug() << "Error: Los datos descargados no forman una imagen válida";
        reply->deleteLater();
        return;
    }

    reply->deleteLater();
    update(); // Actualiza la interfaz de usuario para mostrar la imagen
}



void ven::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if (!im.isNull()) {
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.drawImage(rect(), im, im.rect());
    }
}

void ven::cambiarFondo() {
    QUrl imageUrl(urlImagen->text());
    QNetworkRequest request(imageUrl);
    descargaimagen->get(request);
}



