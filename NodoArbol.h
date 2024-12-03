#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "ListaProcesos.h"
class NodoArbol{
    private:
        //NodoArbol *nodoIzquierdo;
        //NodoArbol *nodoDerecho; NO DEBERÍA DE SER NECESARIO
        int prioridad;
        ListaProcesos listaProcesos;
        
    friend class Arbol;

    public:
        NodoArbol();
        NodoArbol(int p);
        NodoArbol(int p, ListaProcesos l);
        //~NodoArbol();



};
#endif