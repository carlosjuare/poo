#ifndef LOGIN_H
#define LOGIN_H



#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class QNetworkAccessManager;
class QNetworkReply;

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void loginn();
    void onRequestFinished(QNetworkReply *reply);

private:
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QPushButton *loginButton;
    QLabel *resultLabel;

    QNetworkAccessManager *manager;
};


#endif // LOGIN_H
