#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    setearvalores();
      update();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::setearvalores()
{
    AdminDB& gestor = AdminDB::getInstance();
    bool conexionExitosa = gestor.conectar("D:/Usuario Lab/Documentos/parcial2-test/database/basededatos.db");

    if (conexionExitosa) {
        qDebug() << "Conexión exitosa";

        QSqlDatabase db = gestor.getDB();
        QSqlQuery query(db);

        // Crear una instancia de Linea fuera del bucle

        if (query.exec("SELECT x_inicial, y_inicial, x_final, y_final FROM lineas")) {
            while (query.next()) {
                int x_inicial = query.value(0).toDouble();
                int y_inicial = query.value(1).toDouble();
                int x_final = query.value(2).toDouble();
                int y_final = query.value(3).toDouble();

                qDebug() << "Valores obtenidos de la base de datos:";
                qDebug() << "x_inicial:" << x_inicial;
                qDebug() << "y_inicial:" << y_inicial;
                qDebug() << "x_final:" << x_final;
                qDebug() << "y_final:" << y_final;

                linea.Seter(x_inicial, y_inicial, x_final, y_final); // Configurar los valores en la misma instancia de Linea
            }
        } else {
            qDebug() << "Error al ejecutar la consulta: "  ;
        }
    } else {
        qDebug() << "Error: La conexión falló";
    }
}
void Principal::paintEvent(QPaintEvent *event) {
    // Llamada al paintEvent de la clase base
    QWidget::paintEvent(event);

    // Crear un objeto QPainter para dibujar en el widget
    QPainter painter(this);

    // Establecer el color y el grosor de la línea
    painter.setPen(QPen(Qt::black, 2));

    // Dibujar la línea usando los puntos obtenidos de la base de datos
    painter.drawLine(linea.getXInicial(), linea.getYInicial(), linea.getXFinal(), linea.getYFinal());
}
