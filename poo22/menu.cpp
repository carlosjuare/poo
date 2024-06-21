#include "menu.h"

#include "guitarra.h"
#include "bateria.h"
#include "teclado.h"

Menu::Menu(QWidget *parent) : QWidget(parent), instrumentos(nullptr), currentInstrumento(nullptr) {
    sonarButton = new QPushButton("Sonar", this);
    verloButton = new QPushButton("Ver Marca", this);
    agregarInstrumentoButton = new QPushButton("Agregar Instrumento", this);
    instrumentoComboBox = new QComboBox(this);
    nombreInstrumentoInput = new QLineEdit(this);
    nombreInstrumentoInput->setPlaceholderText("Ingrese nombre del instrumento");

    layout = new QVBoxLayout(this);
    layout->addWidget(instrumentoComboBox);
    layout->addWidget(sonarButton);
    layout->addWidget(verloButton);
    layout->addWidget(nombreInstrumentoInput);
    layout->addWidget(agregarInstrumentoButton);

    setLayout(layout);

    connect(sonarButton, &QPushButton::clicked, this, &Menu::onSonarButtonClicked);
    connect(verloButton, &QPushButton::clicked, this, &Menu::onVerloButtonClicked);
    connect(instrumentoComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Menu::onInstrumentoSelected);
    connect(agregarInstrumentoButton, &QPushButton::clicked, this, &Menu::onAgregarInstrumentoButtonClicked);
}

void Menu::setInstrumentos(std::vector<std::unique_ptr<Instrumento>>& instrumentos) {
    this->instrumentos = &instrumentos;
    for (size_t i = 0; i < instrumentos.size(); ++i) {
        instrumentoComboBox->addItem(QString::fromStdString("Instrumento " + std::to_string(i + 1)));
    }
    if (!instrumentos.empty()) {
        currentInstrumento = instrumentos[0].get();
    }
}

void Menu::onSonarButtonClicked() {
    if (currentInstrumento) {
        currentInstrumento->sonar();
    }
}

void Menu::onVerloButtonClicked() {
    if (currentInstrumento) {
        currentInstrumento->verlo();
    }
}

void Menu::onInstrumentoSelected(int index) {
    if (instrumentos && index >= 0 && index < static_cast<int>(instrumentos->size())) {
        currentInstrumento = (*instrumentos)[index].get();
    }
}

void Menu::onAgregarInstrumentoButtonClicked() {
    if (nombreInstrumentoInput->text().isEmpty()) {
        return;
    }

    QString nombre = nombreInstrumentoInput->text();
    std::unique_ptr<Instrumento> nuevoInstrumento;

    if (nombre == "Guitarra") {
        nuevoInstrumento = std::make_unique<Guitarra>();
    } else if (nombre == "Bateria") {
        nuevoInstrumento = std::make_unique<Bateria>();
    } else if (nombre == "Teclado") {
        nuevoInstrumento = std::make_unique<Teclado>();
    } else {
        return;
    }

    instrumentos->push_back(std::move(nuevoInstrumento));
    instrumentoComboBox->addItem(nombre);

    nombreInstrumentoInput->clear();
}
