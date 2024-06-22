#include "login.h"
#include "admindb.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Login::Login(QWidget *parent) : QWidget(parent)
{
    database = AdminDB::getInstance();

    createLayout();
}

void Login::createLayout()
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Campos para iniciar sesión
    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Usuario");

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Contraseña");
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Iniciar sesión", this);
    connect(loginButton, &QPushButton::clicked, this, &Login::attemptLogin);

    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    // Campos para agregar usuario
    newUsernameEdit = new QLineEdit(this);
    newUsernameEdit->setPlaceholderText("Nuevo Usuario");

    newPasswordEdit = new QLineEdit(this);
    newPasswordEdit->setPlaceholderText("Nueva Contraseña");
    newPasswordEdit->setEchoMode(QLineEdit::Password);

    nombreEdit = new QLineEdit(this);
    nombreEdit->setPlaceholderText("Nombre");

    apellidoEdit = new QLineEdit(this);
    apellidoEdit->setPlaceholderText("Apellido");

    addUserButton = new QPushButton("Agregar Usuario", this);
    connect(addUserButton, &QPushButton::clicked, this, &Login::addUser);

    layout->addWidget(newUsernameEdit);
    layout->addWidget(newPasswordEdit);
    layout->addWidget(nombreEdit);
    layout->addWidget(apellidoEdit);
    layout->addWidget(addUserButton);

    setLayout(layout);
}

void Login::attemptLogin()
{
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text().trimmed();

    if (database->userExists(username, password)) {
        QMessageBox::information(this, "Inicio de sesión", "Inicio de sesión exitoso");
        emit loginSuccessful();
        // Aquí podrías abrir la ventana principal de la aplicación
    } else {
        QMessageBox::warning(this, "Inicio de sesión", "Usuario o contraseña incorrectos");
    }
}

void Login::addUser()
{
    QString newUsername = newUsernameEdit->text().trimmed();
    QString newPassword = newPasswordEdit->text().trimmed();
    QString nombre = nombreEdit->text().trimmed();
    QString apellido = apellidoEdit->text().trimmed();

    if (database->addUser(newUsername, newPassword, nombre, apellido)) {
        QMessageBox::information(this, "Agregar usuario", "Usuario agregado correctamente");
        // Limpiar los campos después de agregar usuario
        newUsernameEdit->clear();
        newPasswordEdit->clear();
        nombreEdit->clear();
        apellidoEdit->clear();
    } else {
        QMessageBox::warning(this, "Agregar usuario", "Error al agregar usuario");
    }
}
