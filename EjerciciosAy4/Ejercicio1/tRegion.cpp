#include "tRegion.hpp"

tRegion::tRegion(){
    numero = 0;
    nComunas = 0;
    capacidad = 0;
    nombre = "";
    comunas = nullptr;
}

tRegion::~tRegion(){
    delete[] comunas;
    comunas = nullptr;
}

void tRegion::crear(int numero, string nombre, int nComunas){
    this->numero = numero;
    this->nombre = nombre;
    this->capacidad = nComunas;
    this->nComunas = 0;
    comunas = new string[capacidad];

    for(int i = 0; i < nComunas; i++){
        string comuna;
        cin >> comuna;
        comunas[i] = comuna;
        this->nComunas++;
    }
}

void tRegion::imprimirComunas(){
    for(int i = 0; i < nComunas; i++){
        cout << "- " << comunas[i] << endl;
    }
}

void tRegion::agregarComuna(string nombre){
    if(nComunas + 1 > capacidad){
        int nuevaCap = capacidad * 2;
        if(capacidad == 0) nuevaCap = 1;

        string* nuevo = new string[nuevaCap];
        for(int i = 0; i < nComunas; i++)
            nuevo[i] = comunas[i];

        delete[] comunas;
        comunas = nuevo;
        capacidad = nuevaCap;
    }

    comunas[nComunas] = nombre;
    nComunas++;
}

void tRegion::eliminarComuna(string nombre){
    for(int i = 0; i < nComunas; i++){
        if(comunas[i] == nombre){
            for(int j = i; j < nComunas - 1; j++)
                comunas[j] = comunas[j + 1];
            nComunas--;
            return;
        }
    }
}

int tRegion::getNumero(){
    return numero;
}

string tRegion::getNombre(){
    return nombre;
}

int tRegion::getNComunas(){
    return nComunas;
}

string tRegion::getComuna(int i){
    return comunas[i];
}
