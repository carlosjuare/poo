#ifndef PANTALLA2_H
#define PANTALLA2_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPixmap>

class pantalla2 : public QWidget {
    Q_OBJECT
public:
    pantalla2(QWidget *parent = nullptr);

private:

    QGridLayout *p2;
};
#endif // PANTALLA2_H
