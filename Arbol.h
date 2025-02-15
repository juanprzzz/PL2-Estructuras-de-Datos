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

   friend class SistemaLista; 

public:
    Arbol();
    Arbol(int prioridad, ListaProcesos l);
    ~Arbol();
    NodoArbol* verRaiz();
    Arbol* hijoIzqdo();
    Arbol* hijoDcho();
    bool esVacio();
    void insertarProcesoEnArbol(Proceso p);
    void insertarProceso(Proceso p);
    void mostrarArbol();
    bool estáPrioridad(int prioridad);
    void mostrarPrioridadDada(int p);
    void mostrarPrioridadesEjecutadas();
    void mayorNumeroProcesosAux(Arbol *&mayorProcesos);
    void mayorNumeroProcesos();
    void menorNumeroProcesosAux(Arbol *&menorProcesos);
    void menorNumeroProcesos();
    double tiempoMedioEjecucionNivel(int p);
    void mostrarTiemposMediosNiveles();
    double tiempoMedioEstancia();
    double tiempoMedioEstanciaAux(double& sumaTiempos, int& cuentaNodos);

};
#endif