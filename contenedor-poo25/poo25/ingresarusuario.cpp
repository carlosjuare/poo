#include "ingresarusuario.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

IngresarUsuario::IngresarUsuario(QWidget *parent) : QWidget(parent), adminDB(AdminDB::getInstancia())
{
    // Conectar a la base de datos SQLite
    if (!adminDB->conectar("../contenedor-poo25/usuariosDB.sqlite3")) {
        QMessageBox::critical(this, "Error", "No se pudo conectar a la base de datos.");
        return;
    }

    nombreLineEdit = new QLineEdit();
    apellidoLineEdit = new QLineEdit();
    nusuarioLineEdit = new QLineEdit();
    claveLineEdit = new QLineEdit();
    claveLineEdit->setEchoMode(QLineEdit::Password);

    agregarButton = new QPushButton("Agregar Usuario");
    connect(agregarButton, &QPushButton::clicked, this, &IngresarUsuario::agregarUsuario);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(new QLabel("Nombre:"));
    layout->addWidget(nombreLineEdit);
    layout->addWidget(new QLabel("Apellido:"));
    layout->addWidget(apellidoLineEdit);
    layout->addWidget(new QLabel("Nombre de usuario:"));
    layout->addWidget(nusuarioLineEdit);
    layout->addWidget(new QLabel("Clave:"));
    layout->addWidget(claveLineEdit);
    layout->addWidget(agregarButton);

    setLayout(layout);
}

IngresarUsuario::~IngresarUsuario()
{
    // No se necesita eliminar los widgets individualmente, ya que al ser hijos de
    // IngresarUsuario, Qt se encargará de esto.
}

void IngresarUsuario::agregarUsuario()
{
    QString nombre = nombreLineEdit->text().trimmed();
    QString apellido = apellidoLineEdit->text().trimmed();
    QString nusuario = nusuarioLineEdit->text().trimmed();
    QString clave = claveLineEdit->text();

    if (nombre.isEmpty() || apellido.isEmpty() || nusuario.isEmpty() || clave.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor completa todos los campos.");
        return;
    }

    // Obtener la base de datos
    QSqlDatabase db = adminDB->getDB();

    // Verificar si la base de datos está abierta
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "No se pudo conectar a la base de datos.");
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO datosusuarios (nombre, apellido, nusuario, clave) VALUES (?, ?, ?, ?)");
    query.addBindValue(nombre);
    query.addBindValue(apellido);
    query.addBindValue(nusuario);
    query.addBindValue(clave);

    if (query.exec()) {
        qDebug() << "Usuario agregado correctamente.";
        QMessageBox::information(this, "Éxito", "Usuario agregado correctamente.");
        limpiarCampos();
    } else {
        qDebug() << "Error al agregar usuario:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Error al agregar usuario.");
    }
}

void IngresarUsuario::limpiarCampos()
{
    nombreLineEdit->clear();
    apellidoLineEdit->clear();
    nusuarioLineEdit->clear();
    claveLineEdit->clear();
}
