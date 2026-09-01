#ifndef TPASOS_HPP
#define TPASOS_HPP

#include <string>
#include <fstream>

using namespace std;

struct NodoPaso {
    string texto;
    NodoPaso* sig;
};

class tPasos {

    private: // Datos

        NodoPaso* head;
        int nPasos;

    public: // Metodos

        tPasos();
        ~tPasos();

        void agregarPaso(int pos, string texto);
        void eliminarPaso(int pos);
        void modificarPaso(int pos, string texto);
        int getNPasos();
        void escribirTxt(ofstream& salida);

};

#endif
