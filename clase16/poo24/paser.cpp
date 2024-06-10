#include "paser.h"
#include "ui_paser.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QFile>
#include <QDir>
#include <QByteArray>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QDebug>
#include <QPainter>
Paser::Paser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Paser),
      networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    connect(ui->botoningreso, &QPushButton::clicked, this, &Paser::downloadHtml);
    connect(ui->cfondo, &QPushButton::clicked, this, &Paser::seleccionarImagen);

}

Paser::~Paser()
{
    delete ui;
}

void Paser::downloadHtml()
{
    // Obtener la URL ingresada por el usuario
    QString url = ui->ingreso->text().trimmed(); // Eliminar espacios al principio y al final
    if (url.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese una URL válida.");
        return;
    }

    // Hacer la solicitud GET al servidor para descargar el HTML
    QNetworkReply *reply = networkManager->get(QNetworkRequest(QUrl(url)));

    // Esperar a que la solicitud se complete
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Verificar si la solicitud fue exitosa
    if (reply->error() == QNetworkReply::NoError)
    {
        // Obtener el HTML de la respuesta
        QByteArray htmlData = reply->readAll();

        // Llamar a la función para analizar el HTML en busca de recursos
        parseHtml(htmlData);

        // Construir la ruta completa del archivo de salida
        QString outputDir = QFileDialog::getExistingDirectory(this, "Seleccionar directorio de salida", QDir::homePath());
        if (outputDir.isEmpty()) {
            QMessageBox::warning(this, "Error", "No se seleccionó ningún directorio de salida.");
            return;
        }
        QString filePath = outputDir + "/downloaded.html";

        // Abrir el archivo en modo de escritura, truncando el archivo si ya existe
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            // Escribir el contenido del HTML en el archivo
            file.write(htmlData);
            file.close();
            QMessageBox::information(this, "Descargado", "HTML descargado en la carpeta seleccionada.");
            downloadResources();

        }
        else
        {
            QMessageBox::warning(this, "Error", "Fallo al abrir el archivo para escritura.");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "Fallo al descargar el HTML: " + reply->errorString());
    }

    // Liberar la memoria del objeto QNetworkReply
    reply->deleteLater();
}

void Paser::seleccionarImagen()
{
    // Mostrar el diálogo para seleccionar un archivo de imagen
       QString fileName = QFileDialog::getOpenFileName(this, tr("Seleccionar imagen de fondo"), QDir::homePath(), tr("Archivos de imagen (*.png *.jpg *.jpeg *.bmp)"));

       // Verificar si se seleccionó un archivo
       if (!fileName.isEmpty()) {
           // Cargar la imagen seleccionada
           QImage imagen(fileName);
           if (imagen.isNull()) {
               QMessageBox::critical(this, tr("Error"), tr("No se pudo cargar la imagen."));
               return;
           }

           // Almacenar la imagen cargada como fondo
           imagenFondo = imagen;

           // Forzar a que se repinte la ventana
           update();
       }
}

void Paser::parseHtml(const QByteArray &html)
{
    // Expresiones regulares para encontrar URLs de recursos
    QRegularExpression imgRegex("<img[^>]*src=[\"']([^\"']+)[\"'][^>]*>");
    QRegularExpression cssRegex("<link[^>]*href=[\"']([^\"']+)[\"'][^>]*>");
    QRegularExpression jsRegex("<script[^>]*src=[\"']([^\"']+)[\"'][^>]*>");

    // URL base del sitio web
    QUrl baseUrl(ui->ingreso->text().trimmed());

    // Buscar imágenes
    QRegularExpressionMatchIterator imgMatches = imgRegex.globalMatch(html);
    while (imgMatches.hasNext()) {
        QRegularExpressionMatch match = imgMatches.next();
        QString imgUrl = match.captured(1);
        QUrl imageUrl = baseUrl.resolved(QUrl(imgUrl));
        resourceUrls.append(imageUrl);
    }

    // Buscar hojas de estilo CSS
    QRegularExpressionMatchIterator cssMatches = cssRegex.globalMatch(html);
    while (cssMatches.hasNext()) {
        QRegularExpressionMatch match = cssMatches.next();
        QString cssUrlString = match.captured(1);
        QUrl resolvedCssUrl = baseUrl.resolved(QUrl(cssUrlString));
        resourceUrls.append(resolvedCssUrl);
    }

    // Buscar scripts JavaScript
    QRegularExpressionMatchIterator jsMatches = jsRegex.globalMatch(html);
    while (jsMatches.hasNext()) {
        QRegularExpressionMatch match = jsMatches.next();
        QString jsUrlString = match.captured(1);
        QUrl resolvedJsUrl = baseUrl.resolved(QUrl(jsUrlString));
        resourceUrls.append(resolvedJsUrl);
    }

}

 void Paser::downloadResources()
 {
     // Recorrer la lista de URLs de recursos
     foreach(const QUrl& url, resourceUrls) {
         // Descargar el recurso
         downloadResource(url);
     }
 }

 void Paser::downloadResource(const QUrl &url)
 {
     // Hacer la solicitud GET al servidor
     QNetworkReply *reply = networkManager->get(QNetworkRequest(url));

     // Esperar a que la solicitud se complete
     QEventLoop loop;
     connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
     loop.exec();

     // Verificar si la solicitud fue exitosa
     if (reply->error() == QNetworkReply::NoError)
     {
         // Obtener el nombre del archivo desde la URL
         QString fileName = QFileInfo(url.path()).fileName();

         // Construir la ruta completa del archivo de salida
         QString outputDir = QFileDialog::getExistingDirectory(this, "Seleccionar directorio de salida", QDir::homePath());
         if (outputDir.isEmpty()) {
             QMessageBox::warning(this, "Error", "No se seleccionó ningún directorio de salida.");
             return;
         }
         QString filePath = outputDir + "/" + fileName;

         // Abrir el archivo en modo de escritura, truncando el archivo si ya existe
         QFile file(filePath);
         if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
         {
             // Escribir el contenido del recurso en el archivo
             file.write(reply->readAll());
             file.close();
             QMessageBox::information(this, "Descargado", "Recurso descargado en la carpeta seleccionada.");
         }
         else
         {
             QMessageBox::warning(this, "Error", "Fallo al abrir el archivo para escritura.");
         }
     }
     else
     {
         QMessageBox::critical(this, "Error", "Fallo al descargar el recurso: " + reply->errorString());
     }

     // Liberar la memoria del objeto QNetworkReply
     reply->deleteLater();
 }

 void Paser::paintEvent(QPaintEvent *event)
 {
     // Llama a la implementación de paintEvent de la clase base
       QWidget::paintEvent(event);

       // Verificar si hay una imagen de fondo seleccionada
       if (!imagenFondo.isNull()) {
           // Obtener el rectángulo de destino para dibujar la imagen
           QRect targetRect(0, 0, width(), height());

           // Obtener el painter de la ventana
           QPainter painter(this);

           // Dibujar la imagen de fondo en la ventana
           painter.drawImage(targetRect, imagenFondo);
       }
 }
