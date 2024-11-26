#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Proceso.h"

class Cola{
    private:
        NodoCola * primero;
        NodoCola * ultimo;
        int len;
    public:
        Cola(); 
        ~Cola();
        void encolar(Proceso);
        void encolarPrioridad(Proceso);
        Proceso inicio();
        Proceso fin();
        void desencolar();
        void eliminarFin();
        bool es_vacia();
        void mostrarCola(); //No es correcto, se implementa para ver que está creada correctamente
        Cola copiarCola();
        int get_longitud();

};
#endif // COLA_H