#include "formulario.h"
#include <QVBoxLayout>

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Ventana");

    volverButton = new QPushButton("Volver", this);

    // Establece el diseño para la ventana
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(volverButton);

    setLayout(layout);  // Establece el diseño como el diseño principal de la ventana

    // Conectar la señal clicked() del botón "Volver" a nuestra señal personalizada volverClicked()
    connect(volverButton, &QPushButton::clicked, this, [this]() {
        emit volverClicked();
    });
}
