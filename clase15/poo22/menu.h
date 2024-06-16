#ifndef MENU_H
#define MENU_H


#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <vector>
#include <memory>
#include "Instrumento.h"

class Menu : public QWidget {
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);

    void setInstrumentos(std::vector<std::unique_ptr<Instrumento>>& instrumentos);

private slots:
    void onSonarButtonClicked();
    void onVerloButtonClicked();
    void onInstrumentoSelected(int index);
    void onAgregarInstrumentoButtonClicked();

private:
    QPushButton *sonarButton;
    QPushButton *verloButton;
    QPushButton *agregarInstrumentoButton;
    QComboBox *instrumentoComboBox;
    QVBoxLayout *layout;

    QLineEdit *nombreInstrumentoInput;

    std::vector<std::unique_ptr<Instrumento>>* instrumentos;
    Instrumento* currentInstrumento;

    void setInstrumento(std::unique_ptr<Instrumento> inst);
    Instrumento* getInstrumento() const;
};


#endif // MENU_H
