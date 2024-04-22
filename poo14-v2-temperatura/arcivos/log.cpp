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

    cambiarFondoBtn = new QPushButton("Cambiar Fondo");
    urlImagen = new QLineEdit;
    urlImagen->setPlaceholderText("Ingrese URL de la imagen");

    ttime = new QLabel();
    ttime->setText("Hora actual: ");

    pantalla = new QGridLayout(this);
    pantalla->addWidget(nombre, 0, 0);
    pantalla->addWidget(Enombre, 0, 1);
    pantalla->addWidget(clave, 1, 0);
    pantalla->addWidget(Eclave, 1, 1);
    pantalla->addWidget(botontemp, 2, 0);
    pantalla->addWidget(boton, 3, 0);

    pantalla->addWidget(urlImagen, 4, 0, 1, 2);
    pantalla->addWidget(cambiarFondoBtn, 5, 0, 1, 2);

    pantalla->addWidget(ttime, 0, 3);

    temperatureLabel = new QLabel("Temperatura de Córdoba: Cargando...");
    pantalla->addWidget(temperatureLabel, 2, 1);

    connect(boton, &QPushButton::clicked, this, &ven::checkPassword);
    connect(botontemp, &QPushButton::clicked, this, &ven::toggleTemperature);
    connect(cambiarFondoBtn, &QPushButton::clicked, this, &ven::cambiarFondo);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ven::updateTime);
    timer->start(1000);

    bloqueoUsuarioTimer = new QTimer(this);
    connect(bloqueoUsuarioTimer, &QTimer::timeout, this, &ven::desbloquearUsuario);
    bloqueoUsuarioTimer->setSingleShot(true);
}

void ven::checkPassword() {
    QString enteredUsuario = Enombre->text();
    QString enteredPassword = Eclave->text();

    if (enteredUsuario == correctUsuario && enteredPassword == correctPassword) {
        if (enteredUsuario == correctUsuario) {
            intentosUsuario = 0;
        }
        intentosFallidos = 0;
        this->close();
    } else {
        if (enteredUsuario == correctUsuario) {
            intentosUsuario++;
            if (intentosUsuario >= 3) {
                qDebug() << "Usuario bloqueado. Espere 5 minutos.";
                bloquearUsuario();
            }
        }
        intentosFallidos++;
        if (intentosFallidos >= 3) {
            qDebug() << "Intentos fallidos excedidos. Espere 5 minutos.";
            bloquearClave();
        }
    }
}

void ven::bloquearUsuario() {
    bloqueoUsuarioTimer->start(300000);
    boton->setEnabled(false);
}

void ven::desbloquearUsuario() {
    intentosUsuario = 0;
    qDebug() << "Usuario 'nahuel' desbloqueado. Puede intentar iniciar sesión nuevamente.";
    boton->setEnabled(true);
}

void ven::updateTime() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QString formattedTime = currentTime.toString("hh:mm:ss");
    ttime->setText("Hora actual: " + formattedTime);
}
void ven::bloquearClave() {
    qDebug() << "Intentos fallidos excedidos. Espere 5 minutos.";

    // Bloquear el inicio de sesión deshabilitando el botón
    boton->setEnabled(false);

    // Iniciar un temporizador para desbloquear el inicio de sesión después de 5 minutos
    QTimer::singleShot(300000, this, &ven::desbloquearClave);
}
void ven::desbloquearClave() {
    qDebug() << "Inicio de sesión desbloqueado. Puede intentar iniciar sesión nuevamente.";

    // Habilitar el botón de inicio de sesión
    boton->setEnabled(true);
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

