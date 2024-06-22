#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>

class QLineEdit;
class QPushButton;
class AdminDB;

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

signals:
    void loginSuccessful();

private slots:
    void attemptLogin();
    void addUser();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QLineEdit *newUsernameEdit;
    QLineEdit *newPasswordEdit;
    QLineEdit *nombreEdit;
    QLineEdit *apellidoEdit;
    QPushButton *addUserButton;
    AdminDB *database;

    void createLayout();
};
#endif // LOGIN_H
