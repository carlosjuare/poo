
#include "log.h"
#include <QPainter>
#include <QDebug>
#include <QResizeEvent>

Login::Login(QWidget *parent) : QWidget(parent) {
    if (datbase.conectar("db2.db"))
        qDebug() << "Conexion exitosa";
    else
        qDebug() << "Conexion NO exitosa";
    datbase.consulta();

    descargaimagen = new QNetworkAccessManager(this);
    connect(descargaimagen, SIGNAL(finished(QNetworkReply*)), this, SLOT(descargaimg(QNetworkReply*)));

    setWindowTitle("ventana");

    nombre = new QLabel("nombre");
    Enombre = new QLineEdit;
    clave = new QLabel("clave");
    Eclave = new QLineEdit;
    Eclave->setEchoMode(QLineEdit::Password);

    botonIniciarSesion = new QPushButton("Iniciar sesión");
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
    pantalla->addWidget(botonIniciarSesion, 3, 0, 1, 2); // Solo un botón para iniciar sesión

    pantalla->addWidget(urlImagen, 5, 0, 1, 2);
    pantalla->addWidget(cambiarFondoBtn, 6, 0, 1, 2);
    pantalla->addWidget(ttime, 0, 3);

    temperatureLabel = new QLabel("Temperatura de Córdoba: Cargando...");
    pantalla->addWidget(temperatureLabel, 2, 1);

    connect(botonIniciarSesion, SIGNAL(clicked()), this, SLOT(iniciarSesion())); // Conexión del botón

    connect(botontemp, SIGNAL(clicked()), this, SLOT(toggleTemperature()));
    connect(cambiarFondoBtn, SIGNAL(clicked()), this, SLOT(cambiarFondo()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

    bloqueoUsuarioTimer = new QTimer(this);
    connect(bloqueoUsuarioTimer, SIGNAL(timeout()), this, SLOT(desbloquearUsuario()));
    bloqueoUsuarioTimer->setSingleShot(true);
}


void Login::iniciarSesion() {
    QString nombreUsuario = Enombre->text();
    QString claveUsuario = Eclave->text();

    qDebug() << "Intentando iniciar sesión para el usuario:" << nombreUsuario;

    if (datbase.conectar("db2.db")) {
        qDebug() << "Conexión a la base de datos exitosa.";

        QStringList datos = datbase.validarUsuario("usuarios", nombreUsuario, claveUsuario);
        if (!datos.isEmpty()) {

            qDebug() << "Inicio de sesión exitoso para el usuario:" << nombreUsuario;
            this->hide();
             form.show();
            intentosFallidos = 0; // Reiniciar contador de intentos fallidos
        } else {
            qDebug() << "Nombre de usuario o contraseña incorrectos.";
            intentosFallidos++;

            // Bloquear usuario si excede 3 intentos fallidos
            if (intentosFallidos >= 3) {
                qDebug() << "Intentos fallidos excedidos. Bloqueando usuario por 5 minutos.";
                bloquearUsuario();
            }
        }
    } else {
        qDebug() << "No se pudo conectar a la base de datos";
    }
}

void Login::bloquearUsuario() {
    bloqueoUsuarioTimer->start(300000); // 5 minutos en milisegundos
    botonIniciarSesion->setEnabled(false);
    QMessageBox::critical(this, "Usuario bloqueado", "Demasiados intentos fallidos. Usuario bloqueado por 5 minutos.");
}

void Login::desbloquearUsuario() {
    qDebug() << "Usuario desbloqueado. Puede intentar iniciar sesión nuevamente.";
    botonIniciarSesion->setEnabled(true);
    intentosFallidos = 0; // Reiniciar contador de intentos fallidos
}

void Login::bloquearClave() {
    bloqueoClaveTimer->start(300000); // 5 minutos en milisegundos
    botonIniciarSesion->setEnabled(false);
    QMessageBox::critical(this, "Inicio de sesión bloqueado", "Demasiados intentos fallidos. Intente nuevamente en 5 minutos.");
}

void Login::updateTime() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QString formattedTime = currentTime.toString("hh:mm:ss");
    ttime->setText("Hora actual: " + formattedTime);
}

void Login::desbloquearClave() {
    qDebug() << "Inicio de sesión desbloqueado. Puede intentar iniciar sesión nuevamente.";
    botonIniciarSesion->setEnabled(true);
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
        double temperature = main["temp"].toDouble() - 273.15; // Kelvin a Celsius
        temperatureLabel->setText(QString("Temperatura de Córdoba: %1 °C").arg(temperature));
    } else {
        qDebug() << "Error al obtener la temperatura:" << reply->errorString();
    }

    reply->deleteLater();
}

void Login::toggleTemperature() {
    temperatureLabel->setVisible(!temperatureLabel->isVisible());
}

void Login::descargaimg(QNetworkReply *reply) {
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

void Login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if (!im.isNull()) {
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.drawImage(rect(), im, im.rect());
    }
}

void Login::cambiarFondo() {
    QUrl imageUrl(urlImagen->text());
    QNetworkRequest request(imageUrl);
    descargaimagen->get(request);
}
