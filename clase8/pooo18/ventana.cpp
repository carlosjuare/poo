#include "ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
{
    htmlTextEdit = new QTextEdit(this);
    htmlTextEdit->setReadOnly(true);

    urlLineEdit = new QLineEdit(this);
    urlLineEdit->setPlaceholderText("Enter URL");
    connect(urlLineEdit, &QLineEdit::returnPressed, this, &Ventana::onUrlButtonClicked); // Conectamos la señal returnPressed

    urlButton = new QPushButton("Load URL", this);
    connect(urlButton, &QPushButton::clicked, this, &Ventana::onUrlButtonClicked);

    manager = new QNetworkAccessManager(this); // Inicializamos el manejador de acceso a red
    connect(manager, &QNetworkAccessManager::finished, this, &Ventana::onReplyFinished);

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
