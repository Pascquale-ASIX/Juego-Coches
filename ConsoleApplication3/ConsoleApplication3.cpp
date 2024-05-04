// ConsoleApplication3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include "Enemigo.h"
#include <ctime>
#include <thread>
#include <conio.h>
#include <iostream>


using namespace std;

void mostrarCarrera(Coche& coche, char cocheChar) {
    for (int i = 0; i < coche.getDistanciaRecorrida() / 100; ++i) {
        cout << "-";
    }
    cout << cocheChar << "\n";
}

int main() {
    srand(time(0));

    string nombre;
    cout << "Introduce el nombre de tu piloto: ";
    cin >> nombre;

    Coche coche1(nombre);
    Coche coche2("IA");

    for (int i = 0; i < 4; ++i) {
        cout << "Presiona cualquier tecla para lanzar el dado...\n";
        _getch();

        cout << "Tirando dado, espera...\n";
        this_thread::sleep_for(chrono::seconds(3));
        int puntos = coche1.lanzarDado();
        cout << "Has obtenido " << puntos << " puntos!\n";
        this_thread::sleep_for(chrono::seconds(2));

        if (coche1.getNitro()) {
            cout << "Presiona 'n' para usar el nitro, o cualquier otra tecla para continuar...\n";
            char tecla = _getch();
            if (tecla == 'n' || tecla == 'N') {
                coche1.usarNitro();
                cout << "Nitro activado!\n";
            }
        }

        coche1.mover();
        mostrarCarrera(coche1, '1');

        cout << "Turno de la IA...\n";
        this_thread::sleep_for(chrono::seconds(3));
        coche2.lanzarDado();
        if (coche2.getNitro() && rand() % 2 == 0) {
            coche2.usarNitro();
        }
        coche2.mover();
        mostrarCarrera(coche2, '2');
    }

    if (coche1.getDistanciaRecorrida() > coche2.getDistanciaRecorrida()) {
        cout << coche1.getNombrePiloto() << " ha ganado!\n";
    }
    else if (coche1.getDistanciaRecorrida() < coche2.getDistanciaRecorrida()) {
        cout << coche2.getNombrePiloto() << " ha ganado!\n";
    }
    else {
        cout << "Es un empate!\n";
    }

    return 0;
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
