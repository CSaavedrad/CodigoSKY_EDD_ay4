#include <string>
#include <iostream>
#include "tRegion.hpp"

using namespace std;

struct NodoRegion {
    tRegion datos;
    NodoRegion* prev;
    NodoRegion* next;
};

class tChile{

    private: // Datos

        NodoRegion* head;
        NodoRegion* tail;

    public: // Metodos

        tChile();
        ~tChile();
        tRegion* getRegion(int numero);
        void agregarRegion(int numero, string nombre, int nComunas);
        void eliminarRegion(int numero);
        void imprimirRegiones();
        void exportarInfo();

};
