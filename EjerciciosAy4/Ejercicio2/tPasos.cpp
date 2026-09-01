#include "tPasos.hpp"

tPasos::tPasos() {
    head = nullptr;
    nPasos = 0;
}

tPasos::~tPasos() {
    NodoPaso* actual = head;
    while(actual != nullptr){
        NodoPaso* siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
}

void tPasos::agregarPaso(int pos, string texto) {
    NodoPaso* nuevo = new NodoPaso;
    nuevo->texto = texto;
    nuevo->sig = nullptr;

    if(pos <= 1 || head == nullptr){
        nuevo->sig = head;
        head = nuevo;
        nPasos++;
        return;
    }

    NodoPaso* actual = head;
    int i = 1;
    while(actual->sig != nullptr && i < pos - 1){
        actual = actual->sig;
        i++;
    }

    nuevo->sig = actual->sig;
    actual->sig = nuevo;
    nPasos++;
}

void tPasos::eliminarPaso(int pos) {
    if(head == nullptr || pos < 1 || pos > nPasos)
        return;

    if(pos == 1){
        NodoPaso* aux = head;
        head = head->sig;
        delete aux;
        nPasos--;
        return;
    }

    NodoPaso* actual = head;
    for(int i = 1; i < pos - 1; i++)
        actual = actual->sig;

    NodoPaso* aux = actual->sig;
    actual->sig = aux->sig;
    delete aux;
    nPasos--;
}

void tPasos::modificarPaso(int pos, string texto) {
    if(head == nullptr || pos < 1 || pos > nPasos)
        return;

    NodoPaso* actual = head;
    for(int i = 1; i < pos; i++)
        actual = actual->sig;

    actual->texto = texto;
}

int tPasos::getNPasos() {
    return nPasos;
}

void tPasos::escribirTxt(ofstream& salida) {
    NodoPaso* actual = head;
    while(actual != nullptr){
        salida << actual->texto << endl;
        actual = actual->sig;
    }
}
