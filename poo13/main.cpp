#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    QWidget *ventana = new QWidget;
    ventana->resize(300, 50);

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 100);
    slider->setRange(0, 100);


    QObject::connect(spinBox, QOverload<int>::of(&QSpinBox::valueChanged), [=](int value){
        ventana->setWindowTitle("Volumen: " + QString::number(value));
    });
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    spinBox->setValue(15);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    ventana->setLayout(layout);
    ventana->setVisible(true);

    return a.exec();
}

