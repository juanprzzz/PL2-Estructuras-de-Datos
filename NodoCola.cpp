#include "NodoCola.h"

NodoCola::NodoCola(){
proceso=Proceso();
siguiente=NULL;
//constructor por defecto
}

NodoCola::NodoCola(Proceso p, NodoCola*sig){
proceso=p;
siguiente = sig;
}

NodoCola::~NodoCola(){
//dtor
}