#ifndef PROCESO_H 
#define PROCESO_H
#include <string>

using namespace std;

class Proceso{
    private:
        int PID;
        int PPID=1;
        int inicioProceso;
        int tiempoVida;
        int prioridad;
        int nucleo=0;


        //tiempo de estancia
        int tiempoLlegada=-1;
        int tiempoFin=-1;
        int tiempoEstancia=-1;


 /*
        13.  Calcular  y  mostrar  el  tiempo  promedio  de  ejecución  de  los  procesos  con  una 
prioridad específica: Calcula el tiempo medio que los procesos de un nivel de prioridad 
dado han estado en ejecución.
        */


        friend class NodoPila;
        friend class Pila;
        friend class Sistema;
        friend class NodoCola;
        friend class Cola;
        friend class Nucleo;
        friend class Lista;
        friend class SistemaLista;
        friend class Arbol;

    public:
        Proceso();
        Proceso(int PID,int inicioProceso, int tiempoVida, int prioridad); 
        Proceso(int PID,int inicioProceso, int tiempoVida, int prioridad, int ppid); 
        ~Proceso();
        string toString(); 
        int calcularTiempoEstancia();

};

#endif // PROCESO_H