
#include "log.h"
#include <QPainter>
#include <QDebug>
#include <QResizeEvent>

ven::ven(QWidget *parent) : QWidget(parent) {


    if (datbase.conectar( "D:/Usuario Lab/Descargas/poo-main/poo14-v2-temperatura/atabase/db2.db" ) )
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
validar2=new QPushButton("validar 2");
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

    pantalla->addWidget(urlImagen, 4, 0, 1, 2);
    pantalla->addWidget(cambiarFondoBtn, 5, 0, 1, 2);

    pantalla->addWidget(ttime, 0, 3);

    temperatureLabel = new QLabel("Temperatura de Córdoba: Cargando...");
    pantalla->addWidget(temperatureLabel, 2, 1);

    connect(boton, &QPushButton::clicked, this, &ven::slot_validar);
     connect(validar2, &QPushButton::clicked, this, &ven::iniciarSesion);

    connect(botontemp, &QPushButton::clicked, this, &ven::toggleTemperature);
    connect(cambiarFondoBtn, &QPushButton::clicked, this, &ven::cambiarFondo);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ven::updateTime);
    timer->start(1000);

    bloqueoUsuarioTimer = new QTimer(this);
    connect(bloqueoUsuarioTimer, &QTimer::timeout, this, &ven::desbloquearUsuario);
    bloqueoUsuarioTimer->setSingleShot(true);


}


void ven::slot_validar(){

    bool usuarioValido = false;

    if ( datbase.getDB().isOpen() )  {
        QSqlQuery * query = new QSqlQuery( datbase.getDB() );

        query->exec( "SELECT nombre, apellido FROM usuarios WHERE usuario='" +
        Enombre->text() + "' AND clave='" + Eclave->text() + "'" );

        // Si los datos son consistentes, devolverá un único registro.
        while ( query->next() )  {

            QSqlRecord record = query->record();

            // Obtenemos el número de la columna de los datos que necesitamos.
            int columnaNombre = record.indexOf( "nombre" );
            int columnaApellido = record.indexOf( "apellido" );

            // Obtenemos los valores de las columnas.
            qDebug() << "nombre=" << query->value( columnaNombre ).toString();
            qDebug() << "apellido=" << query->value( columnaApellido ).toString();

            usuarioValido = true;
        }

        if ( usuarioValido )  {


            this->close();
                    form.show();

        }else  {

            QMessageBox::critical( this, "Sin permisos", "Usuario inválido" );


        }
        }




}

void ven::iniciarSesion()
{
    QString nombreUsuario = Enombre->text();
       QString clave = Eclave->text();

       qDebug() << "Intentando iniciar sesión para el usuario:" << nombreUsuario;

       if (datbase.conectar("D:/Usuario Lab/Descargas/poo-main/poo14-v2-temperatura/atabase/db2.db")) {
           qDebug() << "Conexión a la base de datos exitosa.";
           datbase.consulta();

           QStringList datos = datbase.validarUsuario("usuarios", nombreUsuario, clave);
           if (!datos.isEmpty()) {
               emit usuarioAutenticado(nombreUsuario);
               qDebug() << "Inicio de sesión exitoso para el usuario:" << nombreUsuario;
           } else {
               qDebug() << "Nombre de usuario o contraseña incorrectos.";
           }
       } else {
           qDebug() << "No se pudo conectar a la base de datos";
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

