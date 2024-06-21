#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ventana; }
QT_END_NAMESPACE

class ventana : public QWidget
{
    Q_OBJECT

public:
    ventana(QWidget *parent = nullptr);
    ~ventana();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::ventana *ui;

    QImage fondo;
};
#endif // VENTANA_H
