/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *iniciars;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *key;
    QLineEdit *user;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        iniciars = new QPushButton(Login);
        iniciars->setObjectName(QString::fromUtf8("iniciars"));
        iniciars->setGeometry(QRect(170, 240, 75, 23));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 170, 47, 14));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 110, 47, 14));
        key = new QLineEdit(Login);
        key->setObjectName(QString::fromUtf8("key"));
        key->setGeometry(QRect(120, 170, 113, 20));
        user = new QLineEdit(Login);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(130, 110, 113, 20));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        iniciars->setText(QCoreApplication::translate("Login", "ingresar", nullptr));
        label->setText(QCoreApplication::translate("Login", "clave", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
