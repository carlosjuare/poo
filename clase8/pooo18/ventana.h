#ifndef VENTANA_H
#define VENTANA_H


#include <QWidget>
#include <QTextEdit>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

    void setHtml(const QString &html);

private slots:
    void onUrlButtonClicked();
    void onReplyFinished(QNetworkReply *reply);

private:
    QTextEdit *htmlTextEdit;
    QLineEdit *urlLineEdit;
    QPushButton *urlButton;
    QNetworkAccessManager *manager; // Manejador de acceso a red
    QLayout *layout;
};

#endif // VENTANA_H
