#include<login.h>
Login::Login()
{
    Usuario = new QLabel("Usuario");
    Clave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    Entrar = new QPushButton("Entrar");

    layout = new QGridLayout;
    layout->addWidget(Usuario, 0, 0, 1, 1);
    layout->addWidget(Clave, 1, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 2);
    layout->addWidget(leClave, 1, 1, 1, 2);
    layout->addWidget(Entrar, 2, 1, 1, 1);
    this->setLayout(layout);

    // Conexión de la señal clicked del botón Entrar al slot slot_validarUsuario
    connect(Entrar, &QPushButton::clicked, this, &Login::slot_validarUsuario);
}

void Login::slot_validarUsuario()
{
    if (leUsuario->text() == "admin" && leClave->text() == "1234")
    {
        // Si las credenciales son correctas, se cierra la ventana de inicio de sesión
        this->close();
    }
    else
    {
        // Si las credenciales son incorrectas, se limpia el campo de contraseña
        leClave->clear();
    }
}
