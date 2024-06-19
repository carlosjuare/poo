#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("ventana");
    nombre = new QLabel("nombre");
    Enombre = new QLineEdit;
    clave = new QLabel("clave");
    Eclave = new QLineEdit;
    Eclave->setEchoMode(QLineEdit::Password);

    boton = new QPushButton("Iniciar sesión");
    botontemp = new QPushButton("Mostrar/Ocultar temperatura");

    pantalla = new QGridLayout(this);
    pantalla->addWidget(nombre, 0, 0);
    pantalla->addWidget(Enombre, 0, 1);
    pantalla->addWidget(clave, 1, 0);
    pantalla->addWidget(Eclave, 1, 1);
    pantalla->addWidget(botontemp, 2, 0);
    pantalla->addWidget(boton, 3, 0);

    temperatureLabel = new QLabel("Temperatura de Córdoba: Cargando...");
    pantalla->addWidget(temperatureLabel, 2, 1);

    connect(boton, SIGNAL(clicked()), this, SLOT(checkPassword()));
       connect(botontemp, SIGNAL(clicked()), this, SLOT(toggleTemperature()));


    getWeather();
}

void Login::checkPassword() {
    QString enteredPassword = Eclave->text();
    if (enteredPassword == correctPassword) {
        this->close();
        Formulario *formulario = new Formulario;
        connect(formulario, &Formulario::contraseaCambiada, this, [this](const QString& nuevaContrasea) {

            correctPassword = nuevaContrasea;
            qDebug() << "Contraseña cambiada exitosamente a:" << correctPassword;
        });
        formulario->show();
    } else {
        qDebug() << "Contraseña incorrecta. Acceso denegado.";
    }
}

void Login::getWeather() {
    manager = new QNetworkAccessManager(this);
   connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(weatherReply(QNetworkReply*)));
    QUrl url("http://api.openweathermap.org/data/2.5/weather?q=Cordoba&appid=1f101cc43962da830035160fe4f2202c");
    manager->get(QNetworkRequest(url));
}

void Login::weatherReply(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(responseData);
        QJsonObject obj = json.object();
        QJsonObject main = obj["main"].toObject();
        double temperature = main["temp"].toDouble() - 273.15;
        temperatureLabel->setText(QString("Temperatura de Córdoba: %1 °C").arg(temperature));
    } else {
        qDebug() << "Error al obtener la temperatura:" << reply->errorString();
    }

    reply->deleteLater();
}

void Login::toggleTemperature() {
    temperatureLabel->setVisible(!temperatureLabel->isVisible());
}
