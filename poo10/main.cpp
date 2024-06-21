#include <iostream>
#include<string>
#include<vector>
using namespace std;
class jugador{
private:
    string nombre;
    int velocidad;
    int fuerza;

public:
    jugador(int velocidad=0,int fuerza=0, string nombre="sin nombre");
    void getter(int & velocidad, int & fuerza, string & nombre);
    void setter(int  velocidad, int  fuerza, string  nombre);

};
jugador::jugador(int velocidad, int fuerza, string nombre) {
    this->velocidad = velocidad;
    this->fuerza = fuerza;
    this->nombre = nombre;
}


void jugador::getter( int & velocidad, int & fuerza, string & nombre )  {
    velocidad = this->velocidad;
    fuerza = this->fuerza;
    nombre = this->nombre;
}

void jugador::setter( int  velocidad, int  fuerza, string  nombre )  {
    this->velocidad = velocidad;
    this->fuerza = fuerza;
    this->nombre = nombre;
}


int main()
{
    vector<jugador> equipo;
    equipo.push_back(jugador(1,10,"juan"));
     equipo.push_back(jugador(2,9,"juan2"));
      equipo.push_back(jugador(3,8,"juan3"));
       equipo.push_back(jugador(4,7,"juan4"));
        equipo.push_back(jugador(5,6,"juan5"));
         equipo.push_back(jugador(6,5,"juan6"));
          equipo.push_back(jugador(7,4,"juan7"));
           equipo.push_back(jugador(8,3,"juan8"));
            equipo.push_back(jugador(9,2,"juan9"));
             equipo.push_back(jugador(10,1,"juan10"));

             for (int i = 0; i < equipo.size(); ++i) {
                    int vel;
                    int fuer;
                    string nom;
                    equipo[i].getter(vel, fuer, nom);
                    cout << "Jugador " << i + 1 << ":" << endl;
                    cout << "Nombre: " << nom << endl;
                    cout << "Velocidad: " << vel << endl;
                    cout << "Fuerza: " << fuer << endl;
                    cout << endl;
                }
             return 0;


}
