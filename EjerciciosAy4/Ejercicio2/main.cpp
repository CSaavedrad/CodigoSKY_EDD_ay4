#include <iostream>
#include <fstream>
#include <sstream>
#include "tReceta.hpp"

using namespace std;

int main() {

    // Inicializamos la receta
    tReceta receta;

    // Leemos receta.bin
    receta.leerBin("receta.bin");

    // Ejecutamos comandos.txt
    ifstream entrada("comandos.txt");
    string linea;

    while(getline(entrada, linea)){
        if(linea.empty())
            continue;

        stringstream ss(linea);
        string comando;
        ss >> comando;

        if(comando == "NOMBRE"){
            string resto;
            getline(ss, resto);
            if(!resto.empty() && resto[0] == ' ')
                resto = resto.substr(1);
            receta.cambiarNombre(resto);
        }
        else if(comando == "TIEMPO"){
            int nuevoTiempo;
            ss >> nuevoTiempo;
            receta.cambiarTiempo(nuevoTiempo);
        }
        else if(comando == "AGREGAR_ING"){
            string nombreIng;
            double cantidad;
            ss >> nombreIng >> cantidad;
            receta.agregarIngrediente(nombreIng, cantidad);
        }
        else if(comando == "QUITAR_ING"){
            string nombreIng;
            double cantidad;
            ss >> nombreIng >> cantidad;
            receta.quitarIngrediente(nombreIng, cantidad);
        }
        else if(comando == "MODIFICAR_PASO"){
            int pos;
            ss >> pos;
            string resto;
            getline(ss, resto);
            if(!resto.empty() && resto[0] == ' ')
                resto = resto.substr(1);
            receta.getPasos().modificarPaso(pos, resto);
        }
        else if(comando == "AGREGAR_PASO"){
            int pos;
            ss >> pos;
            string resto;
            getline(ss, resto);
            if(!resto.empty() && resto[0] == ' ')
                resto = resto.substr(1);
            receta.getPasos().agregarPaso(pos, resto);
        }
        else if(comando == "ELIMINAR_PASO"){
            int pos;
            ss >> pos;
            receta.getPasos().eliminarPaso(pos);
        }
    }

    entrada.close();

    // Exportamos nueva_receta.txt
    ofstream salida("nueva_receta.txt");

    salida << receta.getNombre() << endl;
    salida << receta.getTiempo() << endl;
    salida << receta.getNIngredientes() << endl;

    for(int i = 0; i < receta.getNIngredientes(); i++){
        Ingrediente ing = receta.getIngrediente(i);
        salida << ing.nombre << " "
               << ing.cantidad << " "
               << ing.unidad << endl;
    }

    salida << receta.getPasos().getNPasos() << endl;
    receta.getPasos().escribirTxt(salida);

    salida.close();

    return 0;
}
