#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QPushButton>

class Formulario : public QWidget {
    Q_OBJECT
signals:
    void volverClicked();
public:
    explicit Formulario(QWidget *parent = nullptr);

private:
    QPushButton *volverButton;
};
#endif // FORMULARIO_H
