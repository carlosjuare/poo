#include "masterwidget.h"
#include <QVBoxLayout>
#include <QDebug>

MasterWidget::MasterWidget(QWidget *parent) : QWidget(parent)
{
    // Crear instancias de Login y ListaWindow
    login = new Login(this);
    listaWindow = new ListaWindow(this);

    // Conectar la señal loginSuccessful() de Login a onLoginSuccessful() de MasterWidget
    connect(login, &Login::loginSuccessful, this, &MasterWidget::onLoginSuccessful);

    // Configurar la interfaz de usuario de MasterWidget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(login);  // Agregar el widget de inicio de sesión al layout
    layout->addWidget(listaWindow);  // Agregar la ventana de lista al layout
    listaWindow->hide();  // Ocultar la ventana de lista al inicio

    setLayout(layout);
}

void MasterWidget::onLoginSuccessful()
{
    // Ocultar la ventana de login y mostrar la ventana de lista
    qDebug() << "Inicio de sesión exitoso, mostrando ListaWindow...";
    login->hide();  // Ocultar la ventana de login
    listaWindow->show();  // Mostrar la ventana de lista
    listaWindow->raise();  // Asegurar que la ventana de lista esté en primer plano
}
