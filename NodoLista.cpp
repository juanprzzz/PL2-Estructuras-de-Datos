#include "NodoLista.h"

NodoLista::NodoLista(){
nucleo=Nucleo(); 
siguiente=NULL;
//constructor por defecto
}


NodoLista::NodoLista(Nucleo n, NodoLista*sig ){
nucleo=n;
siguiente = sig;
}


NodoLista::~NodoLista(){
//dtor
}