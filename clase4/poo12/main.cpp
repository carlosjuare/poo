#include <QApplication>
#include <QLabel>
#include <QImage>
#include <QTimer>
#include <QPainter>

class ImageLabel : public QLabel {
public:
    ImageLabel(const QString &imagePath, QWidget *parent = nullptr)
        : QLabel(parent), image(imagePath) {
        if (image.isNull()) {
            qWarning("No se pudo cargar la imagen.");
        }
    }

protected:
    void paintEvent(QPaintEvent *event) override {

        QPainter painter(this);
        painter.fillRect(rect(), Qt::white);


        if (!image.isNull()) {
            QSize screenSize = size();
            QImage scaledImage = image.scaled(screenSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            int x = (width() - scaledImage.width()) / 2;
            int y = (height() - scaledImage.height()) / 2;
            painter.drawImage(x, y, scaledImage);
        }

        QLabel::paintEvent(event);
    }

private:
    QImage image;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    ImageLabel label("../imagen.jpg");
    label.setWindowState(Qt::WindowMaximized);
    label.show();


    QTimer::singleShot(3000, &app, &QApplication::quit);

    return app.exec();
}
