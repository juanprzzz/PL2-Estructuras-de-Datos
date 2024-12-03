#ifndef NODOLISTAPROCESOS_H
#define NODOLISTAPROCESOS_H
#include "Proceso.h"
class NodoListaProcesos{
    private:
        Proceso proceso;
        NodoListaProcesos *siguiente;

    friend class ListaProcesos;
    friend class Arbol;

    public:
        NodoListaProcesos();
        NodoListaProcesos(Proceso p);
        ~NodoListaProcesos();
};
#endif