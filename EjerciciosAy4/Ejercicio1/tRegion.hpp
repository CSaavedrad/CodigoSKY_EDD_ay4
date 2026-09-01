#include <iostream>
#include <string>

using namespace std;

class tRegion{

    private: //Datos

        int numero;
        int nComunas;
        int capacidad;
        string nombre;
        string *comunas; // Arreglo dinámico

    public: //Metodos

        tRegion();
        ~tRegion();
        void crear(int numero, string nombre, int nComunas);
        void imprimirComunas();
        void agregarComuna(string nombre);
        void eliminarComuna(string nombre);
        int getNumero();
        string getNombre();
        int getNComunas();
        string getComuna(int i);

};
