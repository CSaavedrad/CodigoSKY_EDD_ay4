#include <iostream>
#include <string>
#include "tChile.hpp"

using namespace std;

int main(int argc, char **argv){

    // Inicializamos chile
    tChile chile;

    // Loop de interacción
    bool active = true;
    int option; // Asumiremos que el input es siempre correcto

    while(active){

        cout<<"Escoge una opción:"<<endl<<
              "1. Agregar región"<<endl<<
              "2. Eliminar región"<<endl<<
              "3. Agregar comuna"<<endl<<
              "4. Eliminar comuna"<<endl<<
              "5. Listar regiones"<<endl<<
              "6. Listar comunas de una región"<<endl<<
              "7. Exportar a archivo"<<endl<<
              "0. Salir"<<endl;

        cin>>option;
        if(option==0){
            active = false;
            continue;
        }
        else if(option==1){ // Agregar región

            int numero, nComunas;
            string nombre;
            cin>>numero>>nombre>>nComunas;

            chile.agregarRegion(numero,nombre,nComunas);

        }
        else if(option==2){ // Eliminar región

            int numero;
            cin>>numero;

            chile.eliminarRegion(numero);

        }
        else if(option==3){ // Agregar comuna

            int numero;
            string nombre;
            cin>>numero>>nombre;

            tRegion* region = chile.getRegion(numero);
            (*region).agregarComuna(nombre);

        }
        else if(option==4){ // Eliminar comuna

            int numero;
            string nombre;
            cin>>numero>>nombre;

            tRegion* region = chile.getRegion(numero);
            (*region).eliminarComuna(nombre);

        }
        else if(option==5){ // Listar regiones

            chile.imprimirRegiones();

        }
        else if(option==6){ // Listar comunas de una región

            int numero;
            cin>>numero;

            tRegion* region = chile.getRegion(numero);
            (*region).imprimirComunas();
            
        }
        else{ // Exportar archivo

            chile.exportarInfo();

        }


    }

    return 0;

}