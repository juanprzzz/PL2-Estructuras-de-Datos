#ifndef LISTAPROCESOS_H
#define LISTAPROCESOS_H
#include "NodoListaProcesos.h"
class ListaProcesos{
    private:
        NodoListaProcesos *primero;
        NodoListaProcesos *ultimo;

        friend class Arbol;
    public:
        ListaProcesos();
        ListaProcesos(Proceso p);
        ~ListaProcesos();
        void añadirPorIzquierda(Proceso p);
        void añadirPorDerecha(Proceso p);
        bool esVacia();
        Proceso inicio();
        Proceso fin();
        void eliminarInicio();
        void eliminarFin();
        ListaProcesos copiarLista();
        void mostrarListaProcesos();
        int len();

        int tiempoMedioEjecucionLista();

};

#endif