#ifndef SISTEMALISTA_H
#define SISTEMALISTA_H
#include "Pila.h"
#include "NodoLista.h"
#include "Lista.h"
#include "Nucleo.h"
#include "Arbol.h"

class SistemaLista{
    private:
        Pila pilaProcesos;
        Lista lista;
        int tiempoTranscurrido = 0;

        Arbol abb;


        //variables para calcular tiempo medio de proceso
        int tiempoLlegada=0;
        int tiempoFinalizacion=0;
        int ctdProcesos=0;
    public:
        SistemaLista();
        ~SistemaLista();
        
        void mostrarProcesosNucleo();
        void pasarTiempo(int N);
        //bool asignarSiguienteProcesoDesdeCola(int nucleoLibre);
        void añadirNucleo(Nucleo n);
        void acabarProcesos();
        void procesoComienzo();
        void apilarSistema(Proceso proceso);
        void borrarPila();
        void mostrarPilaProcesos();
        bool pilaVacia();
        bool listaVacia();
        bool nucleosVacios();
        void mostrarOcupacion();

        void añadirProcesoAbbTeclado(int PID, int inicioProceso, int tiempoVida, int ppid, int prioridad);
        void verABB();
        void verPrioridadDada(int p);
        void verPrioridadesEjecutadas();
        void mayorNumeroProcesos();
        void menorNumeroProcesos();

        void mostrarTiemposMediosNiveles(); //muestra el tiempo medio de todos los niveles de prioridad del abb en preorden
        void tiempoMedioEjecucionNivel(int p); //muestra el tiempo medio de ejecución de un nivel dado del abb
        void tiempoMedioEstancia(); //tiempo medio de estancia total en ese momento
}; 
#endif