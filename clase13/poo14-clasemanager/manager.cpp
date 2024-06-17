#include "manager.h"

Manager::Manager() {
    ventanaLogin = new ven();
      formulario = new Formulario();

      connect(formulario, &Formulario::nuevaClave, this, &Manager::cambiarClave);
   connect(ventanaLogin, &ven::passwordCorrect, this, &Manager::ocultarVentanaLogin);
      // Mostrar la ventana de inicio de sesión al inicio
    mostrarVentanaLogin();

}

void Manager::mostrarVentanaLogin() {
    ventanaLogin->show();
    formulario->hide();
}

void Manager::ocultarVentanaLogin() {
    ventanaLogin->hide();
      formulario->show();
}
void Manager::cambiarClave(const QString& nuevaClave) {
    // Cambiar la clave en ven
    ventanaLogin->cambiarClave(nuevaClave);
mostrarVentanaLogin();
}
