#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent)
{

    // Crear widgets
    QLabel *usernameLabel = new QLabel("Username:", this);
    QLabel *passwordLabel = new QLabel("Password:", this);
    usernameLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login", this);
    navigateLabel = new QLabel("Ingresar usuario", this);

    // Establecer propiedades del QLabel como botón
    navigateLabel->setAutoFillBackground(true);
    navigateLabel->setFrameShape(QFrame::Panel);
    navigateLabel->setFrameShadow(QFrame::Raised);
    navigateLabel->setLineWidth(2);
    navigateLabel->setStyleSheet("background-color: white; color: black;");

    // Crear layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);
    layout->addWidget(navigateLabel);

    // Conectar el botón de login con la función de manejo
    connect(loginButton, &QPushButton::clicked, this, &Login::onLoginButtonClicked);
    connect(navigateLabel, &QLabel::linkActivated, this, &Login::onNavigateClicked);

    setLayout(layout);

    // Inicializar AdminDB
    adminDB = AdminDB::getInstancia();
       adminDB->conectar("D:/usuariosDB.sqlite3");

       // Mostrar la tabla de usuarios al inicio
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

           // Preparar la consulta SQL con parámetros para evitar SQL injection
           query.prepare("SELECT nombre, apellido FROM datosusuarios WHERE nusuario = :username AND clave = :password");
           query.bindValue(":username", username);
           query.bindValue(":password", password);

           if (query.exec()) {
               if (query.next()) {
                   // Usuario válido
                   QString nombre = query.value("nombre").toString();
                   QString apellido = query.value("apellido").toString();

                   qDebug() << "Login exitoso. Nombre:" << nombre << "Apellido:" << apellido;
                   emit loginSuccessful();
               } else {
                   // Usuario no encontrado
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
    // Llamamos al evento base para que el resto del comportamiento siga ocurriendo
    QWidget::mousePressEvent(event);

    // Verificar si el evento ocurrió en navigateLabel
    if (event->button() == Qt::LeftButton && navigateLabel->geometry().contains(event->pos())) {
        emit navigateToOtherWindow();
    }
}
