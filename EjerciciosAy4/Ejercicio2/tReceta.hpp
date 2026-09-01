#ifndef TRECETA_HPP
#define TRECETA_HPP

#include <string>
#include "tPasos.hpp"

using namespace std;

struct Ingrediente {
    char nombre[40];
    double cantidad;
    char unidad[15];
};

const int MAX_ING = 30;

class tReceta {

    private: // Datos

        string nombre;
        int tiempo;
        int nIngredientes;
        Ingrediente ingredientes[MAX_ING];
        tPasos pasos;

    public: // Metodos

        tReceta();
        ~tReceta();

        void leerBin(string archivo);

        void cambiarNombre(string nuevoNombre);
        void cambiarTiempo(int nuevoTiempo);
        void agregarIngrediente(string nombreIng, double cantidad);
        void quitarIngrediente(string nombreIng, double cantidad);

        string getNombre();
        int getTiempo();
        int getNIngredientes();
        Ingrediente getIngrediente(int i);
        tPasos& getPasos();

};

#endif
