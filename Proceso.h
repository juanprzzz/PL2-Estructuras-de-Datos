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

};

#endif // PROCESO_H