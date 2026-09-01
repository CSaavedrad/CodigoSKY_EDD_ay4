#include "tChile.hpp"
#include <fstream>

tChile::tChile(){
    head = nullptr;
    tail = nullptr;
}

tChile::~tChile(){
    NodoRegion* actual = head;
    while(actual != nullptr){
        NodoRegion* siguiente = actual->next;
        delete actual;
        actual = siguiente;
    }
}

tRegion* tChile::getRegion(int numero){
    NodoRegion* actual = head;
    while(actual != nullptr){
        if(actual->datos.getNumero() == numero)
            return &(actual->datos);
        actual = actual->next;
    }
    return nullptr;
}

void tChile::agregarRegion(int numero, string nombre, int nComunas){
    if(getRegion(numero) != nullptr){
        cout << "Ya existe una region con ese numero" << endl;
        return;
    }

    NodoRegion* nuevo = new NodoRegion;
    nuevo->prev = nullptr;
    nuevo->next = nullptr;
    nuevo->datos.crear(numero, nombre, nComunas);

    if(head == nullptr){
        head = nuevo;
        tail = nuevo;
        return;
    }

    NodoRegion* actual = head;
    while(actual != nullptr && actual->datos.getNumero() < numero)
        actual = actual->next;

    if(actual == head){
        nuevo->next = head;
        head->prev = nuevo;
        head = nuevo;
    }
    else if(actual == nullptr){
        tail->next = nuevo;
        nuevo->prev = tail;
        tail = nuevo;
    }
    else{
        nuevo->prev = actual->prev;
        nuevo->next = actual;
        actual->prev->next = nuevo;
        actual->prev = nuevo;
    }
}

void tChile::eliminarRegion(int numero){
    NodoRegion* actual = head;
    while(actual != nullptr){
        if(actual->datos.getNumero() == numero){
            if(actual->prev != nullptr)
                actual->prev->next = actual->next;
            else
                head = actual->next;

            if(actual->next != nullptr)
                actual->next->prev = actual->prev;
            else
                tail = actual->prev;

            delete actual;
            return;
        }
        actual = actual->next;
    }
}

void tChile::imprimirRegiones(){
    NodoRegion* actual = head;
    while(actual != nullptr){
        cout << actual->datos.getNumero() << ". "
             << actual->datos.getNombre() << endl;
        actual = actual->next;
    }
}

void tChile::exportarInfo(){
    string archivo;
    cin >> archivo;

    ofstream salida(archivo);
    NodoRegion* actual = head;
    bool primero = true;

    while(actual != nullptr){
        if(!primero)
            salida << endl;
        primero = false;

        salida << "Region " << actual->datos.getNumero() << ": "
               << actual->datos.getNombre() << endl;
        salida << "Comunas (" << actual->datos.getNComunas() << "):" << endl;

        for(int i = 0; i < actual->datos.getNComunas(); i++)
            salida << "- " << actual->datos.getComuna(i) << endl;

        actual = actual->next;
    }

    salida.close();
}
