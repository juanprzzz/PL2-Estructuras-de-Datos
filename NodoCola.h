#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include "Proceso.h"

class NodoCola
{
    friend class Cola;

    private:
        NodoCola *siguiente;
        Proceso proceso;

    public:
        NodoCola();
        NodoCola(Proceso p, NodoCola*sig = NULL);
        ~NodoCola();
};
#endif // NODOCOLA_H