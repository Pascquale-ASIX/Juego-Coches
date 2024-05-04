#include <iostream>

using namespace std;

class Coche {
private:
    string nombrePiloto;
    int velocidad;
    int distanciaRecorrida;
    bool nitro;

public:
    Coche(string nombre);

    string getNombrePiloto();
    int getVelocidad();
    int getDistanciaRecorrida();
    bool getNitro();

    void setNombrePiloto(string nombre);
    void setVelocidad(int velocidad);
    void setDistanciaRecorrida(int distancia);
    void setNitro(bool nitro);

    int lanzarDado();
    void usarNitro();
    void mover();
};

