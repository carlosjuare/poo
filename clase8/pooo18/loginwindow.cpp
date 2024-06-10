#include "loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{
    usernameLineEdit = new QLineEdit(this);
    usernameLineEdit->setPlaceholderText("Username");

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);

    layout = new QGridLayout(this);
    layout->addWidget(usernameLineEdit, 0, 0);
    layout->addWidget(passwordLineEdit, 1, 0);
    layout->addWidget(loginButton, 2, 0);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
     ventanaPrincipal = new Ventana();
}

LoginWindow::~LoginWindow()
{
    delete layout;
     delete ventanaPrincipal;
}

void LoginWindow::onLoginButtonClicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (username == "admin" && password == "1234") {

        ventanaPrincipal->show();
              hide();
    } else {
        QMessageBox::warning(this, "Login", "Invalid username or password!");
    }
}
