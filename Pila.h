#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include "Proceso.h"

class Pila
{
    private:
        pNodoPila cima;

    public:
        Pila(); 
        ~Pila();
        bool esVacia();
        void añadir(Proceso proceso); 
        void apilar(Proceso proceso);
        void desapilar();
        Proceso mostrar();
        Pila copiarPila();
        void mostrarPila();
};

#endif