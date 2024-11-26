#ifndef NODOPILA_H
#define NODOPILA_H
#include "Proceso.h"

class NodoPila
{
    private:
        NodoPila *siguiente;
        Proceso proceso;
        friend class Pila;//clase pila podra acceder tanto a metodos publicos como privados

    public:
        NodoPila(); //constructor
        NodoPila(Proceso proceso, NodoPila *sig = NULL); //constructor donde meto elemento proceso y puntero null, se hace asi por defecto
        ~NodoPila(); //destructor
};

typedef NodoPila *pNodoPila; //creas nuevo tipo de dato nodopila que es un puntero

#endif // NODOPILA_H