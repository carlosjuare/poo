#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>

class Login : public QObject {
    Q_OBJECT
public:
    explicit Login(QObject *parent = nullptr);

signals:
    void usuarioAutenticado(QString nombreUsuario);

public slots:
    void iniciarSesion(QString nombreUsuario, QString clave);
};

#endif // LOGIN_H
