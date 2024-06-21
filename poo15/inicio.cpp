#include "inicio.h"
#include <QDebug>
#include <QRandomGenerator>

ini::ini(QWidget *parent) : QWidget(parent) {
    setWindowTitle("ventana");

    int numeroAleatorio = QRandomGenerator::global()->bounded(10001);
    naltLabel = new QLabel(QString::number(numeroAleatorio));
    nombreLabel = new QLabel("nombre:");
    apellidoLabel = new QLabel("apellido:");
    legajoLabel = new QLabel("legajo:");
    Enombre = new QLineEdit("Nahuel");
    Eapellido = new QLineEdit("juarez");
    Elegajo = new QLineEdit("12345");
    Ecapcha = new QLineEdit;
    bot = new QPushButton("alta");

    Ecapcha->setPlaceholderText("Escriba el CAPTCHA");

    pantala = new QGridLayout(this);
    pantala->addWidget(nombreLabel, 0, 0);
    pantala->addWidget(apellidoLabel, 1, 0);
    pantala->addWidget(legajoLabel, 2, 0);
    pantala->addWidget(Enombre, 0, 1);
    pantala->addWidget(Eapellido, 1, 1);
    pantala->addWidget(Elegajo, 2, 1);
    pantala->addWidget(bot, 3, 1);
    pantala->addWidget(naltLabel, 3, 0);
    pantala->addWidget(Ecapcha, 4, 0, 1, 2); // Se extiende sobre dos columnas

    connect(bot, &QPushButton::clicked, this, &ini::salir);
}

void ini::salir() {
    if (Ecapcha->text() == naltLabel->text()) {
        qDebug() << "CAPTCHA correcto. Cerrando la aplicación.";
        this->close();
    } else {
        qDebug() << "El CAPTCHA ingresado es incorrecto.";
        // Aquí puedes agregar un QMessageBox u otra señal de advertencia al usuario
    }
}
