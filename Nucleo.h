#ifndef NUCLEO_H
#define NUCLEO_H
#include "Cola.h"
#include "Proceso.h"
#include <string>

class Nucleo 
{
    private:
        Cola colaEspera;
        int ID;
        Proceso procesoEjecucion;
        int contadorProcesos;

    friend class NodoPila;
    friend class Pila;
    friend class Sistema;
    friend class NodoCola;
    friend class Cola;
    friend class NodoLista;
    friend class Lista;

    friend class SistemaLista;
       
    public:
        Nucleo();
        Nucleo(int id);
        ~Nucleo();
        void añadirProceso(Proceso proceso); 
        void desencolarProceso();  //eliminar el 1er elemento de la cola de espera 
        void mostrarNucleo();
        string mostrarProcesoEjecucion();
        void ejecutarProceso(Proceso proceso);
        Proceso terminarProceso();
        void lenCola(); 

        Proceso PrimeroCola(); //getter delprimer elemento de la cola de espera

};

#endif