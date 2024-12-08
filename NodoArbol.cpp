#include "NodoArbol.h"


NodoArbol::NodoArbol(){
    prioridad = 4;
}
NodoArbol::NodoArbol(int p){
    prioridad = p;
}
NodoArbol::NodoArbol(int p, ListaProcesos l){
    prioridad = p;
    listaProcesos = l;
}
