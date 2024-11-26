#ifndef SISTEMA_H
#define SISTEMA_H
#include "Pila.h"
#include "Cola.h"

class Sistema{
    private:
        Pila pilaProcesos;
        Cola colaEspera;
        Proceso nucleos[3];
        int tiempoTranscurrido = 0;


        //variables para calcular tiempo medio de proceso
        int tiempoLlegada=0;
        int tiempoFinalizacion=0;
        int ctdProcesos=0;
    public:
        Sistema();
        ~Sistema();
        
        void mostrarProcesosNucleo();
        void pasarTiempo(int N);
        bool asignarSiguienteProcesoDesdeCola(int nucleoLibre);
        void añadirCola(Proceso proceso);
        void acabarProcesos();
        void procesoComienzo();
        void apilarSistema(Proceso proceso);
        void borrarPila();
        void mostrarPilaProcesos();
        void mostrarColaPrioridad();
        bool pilaVacia();
        bool colaVacia();
        bool nucleosVacios();
};
    
#endif