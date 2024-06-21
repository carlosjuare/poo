#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    QLabel label("Esto es una QLabel");
    label.setGeometry(50, 50, 200, 50);
    label.show();

    QWidget widget;
    widget.setGeometry(300, 50, 200, 50);
    widget.show();


    QPushButton button("Esto es un QPushButton");
    button.setGeometry(50, 150, 200, 50);
    button.show();


    QLineEdit lineEdit;
    lineEdit.setGeometry(300, 150, 200, 50);
      lineEdit.show();

    return app.exec();
}
