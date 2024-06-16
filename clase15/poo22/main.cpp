#include <QApplication>
#include "menu.h"
#include "guitarra.h"
#include "bateria.h"
#include "teclado.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

      std::vector<std::unique_ptr<Instrumento>> instrumentos;
      instrumentos.push_back(std::make_unique<Guitarra>());
      instrumentos.push_back(std::make_unique<Bateria>());
      instrumentos.push_back(std::make_unique<Teclado>());
      instrumentos.push_back(std::make_unique<Guitarra>());
      instrumentos.push_back(std::make_unique<Bateria>());

      Menu menu;
      menu.setInstrumentos(instrumentos);
      menu.show();

      return app.exec();
}
