#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent)
{


    QLabel *usernameLabel = new QLabel("Username:", this);
    QLabel *passwordLabel = new QLabel("Password:", this);
    usernameLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login", this);
    navigateLabel = new QLabel("Ingresar usuario", this);


    navigateLabel->setAutoFillBackground(true);
    navigateLabel->setFrameShape(QFrame::Panel);
    navigateLabel->setFrameShadow(QFrame::Raised);
    navigateLabel->setLineWidth(2);
    navigateLabel->setStyleSheet("background-color: white; color: black;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);
    layout->addWidget(navigateLabel);


    connect(loginButton, &QPushButton::clicked, this, &Login::onLoginButtonClicked);
    connect(navigateLabel, &QLabel::linkActivated, this, &Login::onNavigateClicked);

    setLayout(layout);


    adminDB = AdminDB::getInstancia();
       adminDB->conectar("C:/Users/nahuel/Desktop/archivos finales-poo/contenedor-poo25/usuariosDB.sqlite3");


      adminDB->mostrarDatosTabla();

}

Login::~Login()
{
}

void Login::onLoginButtonClicked()
{
    QString username = usernameLineEdit->text();
       QString password = passwordLineEdit->text();

       if (adminDB->getDB().isOpen()) {
           QSqlQuery query(adminDB->getDB());


           query.prepare("SELECT nombre, apellido FROM datosusuarios WHERE nusuario = :username AND clave = :password");
           query.bindValue(":username", username);
           query.bindValue(":password", password);

           if (query.exec()) {
               if (query.next()) {

                   QString nombre = query.value("nombre").toString();
                   QString apellido = query.value("apellido").toString();

                   qDebug() << "Login exitoso. Nombre:" << nombre << "Apellido:" << apellido;
                   emit loginSuccessful();
               } else {

                   QMessageBox::critical(this, "Error", "Usuario o contraseña incorrectos");
               }
           } else {
               qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
               QMessageBox::critical(this, "Error", "Error al intentar iniciar sesión");
           }
       } else {
           qDebug() << "La base de datos no está abierta.";
       }
}

void Login::onNavigateClicked()
{
    emit navigateToOtherWindow();
}

void Login::mousePressEvent(QMouseEvent *event)
{

    QWidget::mousePressEvent(event);


    if (event->button() == Qt::LeftButton && navigateLabel->geometry().contains(event->pos())) {
        emit navigateToOtherWindow();
    }
}
