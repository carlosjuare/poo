#include "ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
{
    htmlTextEdit = new QTextEdit(this);
    htmlTextEdit->setReadOnly(true);

    urlLineEdit = new QLineEdit(this);
    urlLineEdit->setPlaceholderText("Enter URL");
   connect(urlLineEdit, SIGNAL(returnPressed()), this, SLOT(onUrlButtonClicked()));

    urlButton = new QPushButton("Load URL", this);
      connect(urlButton, SIGNAL(clicked()), this, SLOT(onUrlButtonClicked()));

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onReplyFinished(QNetworkReply*)));

    layout = new QVBoxLayout(this);
    layout->addWidget(htmlTextEdit);
    layout->addWidget(urlLineEdit);
    layout->addWidget(urlButton);
}

Ventana::~Ventana()
{
}

void Ventana::setHtml(const QString &html)
{
    htmlTextEdit->setHtml(html);
}

void Ventana::onUrlButtonClicked()
{
    QString url = urlLineEdit->text();
    QUrl qUrl(url);
    QNetworkRequest request(qUrl); // Creamos una solicitud de red
    manager->get(request); // Enviamos la solicitud
}

void Ventana::onReplyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QString html = QString::fromUtf8(data);
        htmlTextEdit->setPlainText(html); // Mostrar el HTML en QTextEdit
    } else {
        htmlTextEdit->setPlainText("Error loading URL: " + reply->errorString()); // Mostrar un mensaje de error si hay algún problema
    }
    reply->deleteLater(); // Liberar el objeto reply
}
