#include <QApplication>
#include "mylabel.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Ruta de la imagen
    QString imagePath = "D:/Usuario Lab/Descargas/Pruebas1.jpg";

    // Crear un objeto de la clase MyLabel con la ruta de la imagen
    MyLabel label(imagePath);

    // Mostrar la QLabel
    label.showMaximized();

    return app.exec();
}
