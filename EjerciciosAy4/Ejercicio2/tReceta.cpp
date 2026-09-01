#include "tReceta.hpp"
#include <fstream>
#include <cstring>

void leerString(ifstream& entrada, string& s){
    int L;
    entrada.read((char*)&L, sizeof(int));
    char* buffer = new char[L];
    entrada.read(buffer, L);
    s = string(buffer, L);
    delete[] buffer;
}

tReceta::tReceta() {
    nombre = "";
    tiempo = 0;
    nIngredientes = 0;
}

tReceta::~tReceta() {
}

void tReceta::leerBin(string archivo) {
    ifstream entrada(archivo, ios::binary);

    leerString(entrada, nombre);
    entrada.read((char*)&tiempo, sizeof(int));
    entrada.read((char*)&nIngredientes, sizeof(int));

    for(int i = 0; i < nIngredientes; i++)
        entrada.read((char*)&ingredientes[i], sizeof(Ingrediente));

    int nPasos;
    entrada.read((char*)&nPasos, sizeof(int));

    for(int i = 0; i < nPasos; i++){
        string paso;
        leerString(entrada, paso);
        pasos.agregarPaso(i + 1, paso);
    }

    entrada.close();
}

void tReceta::cambiarNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}

void tReceta::cambiarTiempo(int nuevoTiempo) {
    tiempo = nuevoTiempo;
}

void tReceta::agregarIngrediente(string nombreIng, double cantidad) {
    for(int i = 0; i < nIngredientes; i++){
        if(strcmp(ingredientes[i].nombre, nombreIng.c_str()) == 0){
            ingredientes[i].cantidad += cantidad;
            return;
        }
    }
}

void tReceta::quitarIngrediente(string nombreIng, double cantidad) {
    for(int i = 0; i < nIngredientes; i++){
        if(strcmp(ingredientes[i].nombre, nombreIng.c_str()) == 0){
            ingredientes[i].cantidad -= cantidad;
            if(ingredientes[i].cantidad < 0)
                ingredientes[i].cantidad = 0;
            return;
        }
    }
}

string tReceta::getNombre() {
    return nombre;
}

int tReceta::getTiempo() {
    return tiempo;
}

int tReceta::getNIngredientes() {
    return nIngredientes;
}

Ingrediente tReceta::getIngrediente(int i) {
    return ingredientes[i];
}

tPasos& tReceta::getPasos() {
    return pasos;
}
