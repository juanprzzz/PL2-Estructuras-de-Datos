#ifndef ARBOL_H
#define ARBOL_H
#include "NodoArbol.h"
#include "ListaProcesos.h"
class Arbol
{
private:
    NodoArbol *raiz;
    Arbol *hijoIzquierdo;
    Arbol *hijoDerecho;

public:
    Arbol();
    Arbol(int prioridad, ListaProcesos l);
    NodoArbol* verRaiz();
    Arbol* hijoIzqdo();
    Arbol* hijoDcho();
    bool esVacio();
    void insertarProcesoEnArbol(Proceso p);
    void insertarProceso(Proceso p);
    void mostrarArbol();
    bool estáPrioridad(int prioridad);

    void mostrarPrioridadDada(int p);



    //void mayorNumeroprocesos();
    //void menorNumeroprocesos();
    //void mostrarPreorden();
    //void tiempoMedioEjecucionNivel(int p);

};
#endif