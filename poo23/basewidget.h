#ifndef BASEWIDGET_H
#define BASEWIDGET_H
#include <QWidget>
#include <QDebug>

class BaseWidget {
public:
    BaseWidget() { qDebug() << "BaseWidget Constructor"; }
    virtual ~BaseWidget() { qDebug() << "BaseWidget Destructor"; }

    virtual void showWidget() = 0; // Método puro virtual
};
#endif // BASEWIDGET_H
