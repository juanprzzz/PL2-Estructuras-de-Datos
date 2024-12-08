#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "ListaProcesos.h"
class NodoArbol{
    private:
        int prioridad;
        ListaProcesos listaProcesos;
        
    friend class Arbol;

    public:
        NodoArbol();
        NodoArbol(int p);
        NodoArbol(int p, ListaProcesos l);



};
#endif