
#include "log.h"
#include <QPainter>
#include <QDebug>
#include <QResizeEvent>

Login::Login(QWidget *parent) : QWidget(parent) {
    if (datbase.conectar("D:/Usuario Lab/Descargas/poo-main/poo14-v2-temperatura/atabase/db2.db"))
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

    boton = new QPushButton("Iniciar sesión");
    botontemp = new QPushButton("Mostrar/Ocultar temperatura");

    cambiarFondoBtn = new QPushButton("Cambiar Fondo");
    urlImagen = new QLineEdit;
    urlImagen->setPlaceholderText("Ingrese URL de la imagen");
    validar2 = new QPushButton("validar 2");
    valdar3 = new QPushButton("validar 3"); // Botón para validar con credenciales fijas

    ttime = new QLabel();
    ttime->setText("Hora actual: ");

    pantalla = new QGridLayout(this);
    pantalla->addWidget(nombre, 0, 0);
    pantalla->addWidget(Enombre, 0, 1);
    pantalla->addWidget(clave, 1, 0);
    pantalla->addWidget(Eclave, 1, 1);
    pantalla->addWidget(botontemp, 2, 0);
    pantalla->addWidget(boton, 3, 0);
    pantalla->addWidget(validar2, 3, 1);
    pantalla->addWidget(valdar3, 4, 0); // Agregamos el botón validar3
    pantalla->addWidget(urlImagen, 5, 0, 1, 2);
    pantalla->addWidget(cambiarFondoBtn, 6, 0, 1, 2);
    pantalla->addWidget(ttime, 0, 3);

    temperatureLabel = new QLabel("Temperatura de Córdoba: Cargando...");
    pantalla->addWidget(temperatureLabel, 2, 1);

    connect(boton, SIGNAL(clicked()), this, SLOT(slot_validar()));
    connect(validar2, SIGNAL(clicked()), this, SLOT(iniciarSesion()));
    connect(valdar3, SIGNAL(clicked()), this, SLOT(validar3())); // Conectamos el botón validar3
    connect(botontemp, SIGNAL(clicked()), this, SLOT(toggleTemperature()));
    connect(cambiarFondoBtn, SIGNAL(clicked()), this, SLOT(cambiarFondo()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

    bloqueoUsuarioTimer = new QTimer(this);
    connect(bloqueoUsuarioTimer, SIGNAL(timeout()), this, SLOT(desbloquearUsuario()));
    bloqueoUsuarioTimer->setSingleShot(true);
}

void Login::slot_validar()
{
    bool usuarioValido = false;

    if (datbase.getDB().isOpen()) {
        QSqlQuery query(datbase.getDB());

        QString consulta = "SELECT nombre, apellido FROM datos WHERE usuario = :usuario AND clave = :clave";
        query.prepare(consulta);
        query.bindValue(":usuario", Enombre->text());
        query.bindValue(":clave", Eclave->text());

        if (query.exec()) {
            while (query.next()) {
                QString nombre = query.value("nombre").toString();
                QString apellido = query.value("apellido").toString();

                qDebug() << "Nombre:" << nombre << ", Apellido:" << apellido;
                usuarioValido = true;
            }

            if (usuarioValido) {
                this->close();
                form.show();
            } else {
                QMessageBox::critical(this, "Sin permisos", "Usuario inválido");
            }
        } else {
            qDebug() << "Error al ejecutar la consulta:"  ;
        }
    } else {
        qDebug() << "La base de datos no está abierta.";
    }
}

void Login::iniciarSesion()
{
    QString nombreUsuario = Enombre->text();
    QString clave = Eclave->text();

    qDebug() << "Intentando iniciar sesión para el usuario:" << nombreUsuario;

    if (datbase.conectar("D:/Usuario Lab/Descargas/poo-main/poo14-v2-temperatura/atabase/db2.db")) {
        qDebug() << "Conexión a la base de datos exitosa.";
        datbase.consulta();

        QStringList datos = datbase.validarUsuario("datos", nombreUsuario, clave);
        if (!datos.isEmpty()) {
            emit usuarioAutenticado(nombreUsuario);
            qDebug() << "Inicio de sesión exitoso para el usuario:" << nombreUsuario;
            this->close();
            form.show();
        } else {
            qDebug() << "Nombre de usuario o contraseña incorrectos.";
        }
    } else {
        qDebug() << "No se pudo conectar a la base de datos";
    }
}

void Login::validar3()
{
    QString nombreUsuario = Enombre->text();
    QString clave = Eclave->text();

    qDebug() << "Intentando iniciar sesión con credenciales fijas para el usuario:" << nombreUsuario;

    if (nombreUsuario == correctUsuario && clave == correctPassword) {
        qDebug() << "Inicio de sesión exitoso con credenciales fijas para el usuario:" << nombreUsuario;
        emit usuarioAutenticado(nombreUsuario);
        this->close();
        form.show();
    } else {
        qDebug() << "Nombre de usuario o contraseña incorrectos con credenciales fijas.";
        intentosFallidos++;
        if (intentosFallidos >= 3) {
            bloquearUsuario();
        }
    }
}


void Login::bloquearUsuario() {
    bloqueoUsuarioTimer->start(300000);
    boton->setEnabled(false);
}

void Login::desbloquearUsuario() {
    intentosUsuario = 0;
    qDebug() << "Usuario 'nahuel' desbloqueado. Puede intentar iniciar sesión nuevamente.";
    boton->setEnabled(true);
}

void Login::updateTime() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QString formattedTime = currentTime.toString("hh:mm:ss");
    ttime->setText("Hora actual: " + formattedTime);
}

void Login::bloquearClave() {
    qDebug() << "Intentos fallidos excedidos. Espere 5 minutos.";

    // Bloquear el inicio de sesión deshabilitando el botón
    boton->setEnabled(false);

    // Iniciar un temporizador para desbloquear el inicio de sesión después de 5 minutos
    QTimer::singleShot(300000, this, SLOT(desbloquearClave()));
}

void Login::desbloquearClave() {
    qDebug() << "Inicio de sesión desbloqueado. Puede intentar iniciar sesión nuevamente.";

    // Habilitar el botón de inicio de sesión
    boton->setEnabled(true);
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
