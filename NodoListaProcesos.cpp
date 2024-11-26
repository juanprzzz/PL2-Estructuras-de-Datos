#include "NodoListaProcesos.h"

NodoListaProcesos::NodoListaProcesos(){
    proceso;
    siguiente = NULL;
}

NodoListaProcesos::NodoListaProcesos(Proceso p){
    proceso = p;
    siguiente = NULL;
}
NodoListaProcesos::~NodoListaProcesos(){
    //Destructor
}

