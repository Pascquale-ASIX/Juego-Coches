#include "Enemigo.h"
#include <cstdlib>

using namespace std;

Coche::Coche(string nombre) : nombrePiloto(nombre), velocidad(0), distanciaRecorrida(0), nitro(true) {}

string Coche::getNombrePiloto() { return nombrePiloto; }
int Coche::getVelocidad() { return velocidad; }
int Coche::getDistanciaRecorrida() { return distanciaRecorrida; }
bool Coche::getNitro() { return nitro; }

void Coche::setNombrePiloto(string nombre) { nombrePiloto = nombre; }
void Coche::setVelocidad(int velocidad) { this->velocidad = velocidad; }
void Coche::setDistanciaRecorrida(int distancia) { distanciaRecorrida = distancia; }
void Coche::setNitro(bool nitro) { this->nitro = nitro; }

int Coche::lanzarDado() {
    int puntos = rand() % 6 + 1;
    velocidad += puntos;
    return puntos;
}

void Coche::usarNitro() {
    if (nitro) {
        int resultado = rand() % 2;
        if (resultado == 0) {
            velocidad /= 2;
        }
        else {
            velocidad *= 2;
        }
        nitro = false;
    }
}

void Coche::mover() {
    distanciaRecorrida += velocidad * 100;
    velocidad = 0;
}