#include <iostream>
using namespace std;

// 1. CLASE BASE
class Vehiculo {
public:
    string marca;

    // Método virtual para mostrar información básica
    virtual void mostrarInfo() {
        cout << "Vehiculo: " << marca << endl;
    }

    // Método virtual para el polimorfismo de encendido
    virtual void encender() {
        cout << "El vehiculo esta encendido." << endl;
    }

};

// 2. CLASE HIJA: AUTO
class Auto : public Vehiculo {
public:
    int numPuertas;

    void mostrarInfo() override {
        cout << "Auto: " << marca << " | Puertas: " << numPuertas << endl;
    }

    void encender() override {
        cout << " Gira la llave y suena el motor." << endl;
    }
};

// 3. CLASE HIJA: MOTO
class Moto : public Vehiculo {
public:
    int cilindraje;

    void mostrarInfo() override {
        cout << "Moto: " << marca << " | Cilindraje: " << cilindraje << "cc" << endl;
    }

    void encender() override {
        cout << " Presiona el boton de arranque y ruge la moto." << endl;
    }
};

int main() {
    // Creamos los objetos directamente
    Auto miAuto;
    miAuto.marca = "Toyota - Fortuner";
    miAuto.numPuertas = 4;

    Moto miMoto;
    miMoto.marca = "BMW - S1000R";
    miMoto.cilindraje = 999;

    // Ejecutamos los métodos de cada uno
    miAuto.mostrarInfo();
    miAuto.encender();

    miMoto.mostrarInfo();
    miMoto.encender();

    return 0;
}
