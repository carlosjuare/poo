#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;
class QGridLayout;

class VentanaLogin : public QWidget {
    Q_OBJECT
public:
    VentanaLogin(QWidget *parent = nullptr);

private slots:
    void comprobarContrasena();
     void guardarContrasena();

private:
    QLabel *labelUsuario;
    QLabel *labelApellido;
    QLabel *labelContrasena;
    QLabel *labelLegajo;
    QLineEdit *editUsuario;
    QLineEdit *editApellido;
    QLineEdit *editContrasena;
    QLineEdit *editLegajo;
    QPushButton *botonIniciarSesion;
    QGridLayout *layout;
};
#endif // LOGIN_H
