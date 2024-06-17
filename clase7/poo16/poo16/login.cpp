#include "login.h"
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

Login::Login(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Inicio de Sesión");

    usernameLabel = new QLabel("Usuario:");
    usernameInput = new QLineEdit();
    passwordLabel = new QLabel("Contraseña:");
    passwordInput = new QLineEdit();
    passwordInput->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Iniciar Sesión");
    resultLabel = new QLabel();

    connect(loginButton, &QPushButton::clicked, this, &Login::loginn);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);
    layout->addWidget(resultLabel);

    setLayout(layout);

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Login::onRequestFinished);
}

Login::~Login()
{
    delete usernameLabel;
    delete usernameInput;
    delete passwordLabel;
    delete passwordInput;
    delete loginButton;
    delete resultLabel;
}

void Login::loginn()
{
    QString username = usernameInput->text();
    QString password = passwordInput->text();

    QNetworkRequest request(QUrl("http://localhost:8000/validar_usuario/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray data = QString("{\"usuario\": \"%1\", \"clave\": \"%2\"}").arg(username, password).toUtf8();
    manager->post(request, data);
}

void Login::onRequestFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QString responseText = QString(reply->readAll());

        if (responseText == "denegado")
        {
            resultLabel->setText("Credenciales incorrectas");
        }
        else
        {
            resultLabel->setText("Inicio de sesión exitoso para: " + responseText);
        }
    }
    else
    {
        resultLabel->setText("Error al conectar con el servidor: " + reply->errorString());
    }

    reply->deleteLater();
}
