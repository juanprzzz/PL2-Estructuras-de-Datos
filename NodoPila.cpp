#include "NodoPila.h"

NodoPila::NodoPila() //constructor si hago NodoPila(); vacio
{
    proceso=Proceso();
    siguiente=NULL;
}

NodoPila::NodoPila(Proceso p, NodoPila *sig) //constructor bueno
{
proceso = p;
siguiente = sig;
}


NodoPila::~NodoPila() //destructor
{
}