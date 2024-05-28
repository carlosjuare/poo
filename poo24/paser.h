#ifndef PASER_H
#define PASER_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class Paser; }
QT_END_NAMESPACE

class Paser : public QWidget
{
    Q_OBJECT

public:
    Paser(QWidget *parent = nullptr);
    ~Paser();
private slots:
    void downloadHtml();
      void seleccionarImagen();
private:
    Ui::Paser *ui;
     QNetworkAccessManager *networkManager;
     void parseHtml(const QByteArray &html);
    void downloadResources();
    void downloadResource(const QUrl &url);

    void paintEvent(QPaintEvent *event);

    QImage imagenFondo;
    QList<QUrl> resourceUrls;

};
#endif // PASER_H
