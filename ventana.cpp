#include "ventana.h"
#include "ui_ventana.h"
#include "login.h" // Incluimos el archivo de encabezado Login.h aquí

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
    , log(nullptr)
{
    ui->setupUi(this);
    connect(ui->btvolver, SIGNAL(clicked()), this, SLOT(volverlogin()));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::volverlogin()
{
    this->close();
    log->show(); // Mostrar la instancia de Login
}

void Ventana::setLogin(Login *login)
{
    log = login;
}
