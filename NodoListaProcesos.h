#ifndef NODOLISTAPROCESOS_H
#define NODOLISTAPROCESOS_H
#include "Proceso.h"
class NodoListaProcesos{
    private:
        Proceso proceso;
        NodoListaProcesos *siguiente;

    friend class ListaProcesos;

    public:
        NodoListaProcesos();
        NodoListaProcesos(Proceso p);
        ~NodoListaProcesos();
};
#endif