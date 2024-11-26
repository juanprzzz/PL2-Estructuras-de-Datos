#include "NodoArbol.h"


NodoArbol::NodoArbol(){
    prioridad = 4;
    listaProcesos;
}
NodoArbol::NodoArbol(int p){
    prioridad = p;
    listaProcesos;
}
NodoArbol::NodoArbol(int p, ListaProcesos l){
    prioridad = p;
    listaProcesos = l;
}