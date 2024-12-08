#include "Proceso.h"
#include <string>

#include <iostream>
using namespace std;

Proceso::Proceso()
{
    PID = -1;
    PPID = -1;
    inicioProceso = -1;
    tiempoVida = -1;
    prioridad = -1;
    nucleo = -1;
}

Proceso::Proceso(int pid, int inicioproceso, int tiempovida, int prior)
{
    if (pid > 0 && inicioproceso >= 0 && tiempovida > 0 && prior >= 0 && prior <= 9)
    {
        PID = pid;
        inicioProceso = inicioproceso;
        tiempoVida = tiempovida;
        prioridad = prior;
    }
    else
    {
        Proceso();
    }
}
Proceso::Proceso(int pid, int inicioproceso, int tiempovida, int prior, int ppid)
{
    if (pid > 0 && inicioproceso >= 0 && tiempovida > 0 && prior >= 0 && prior <= 9 && ppid > 0)
    {
        PID = pid;
        inicioProceso = inicioproceso;
        tiempoVida = tiempovida;
        prioridad = prior;
        PPID = ppid;
    }
    else
    {
        Proceso();
    }
}

Proceso::~Proceso()
{
    // dtor
}

string Proceso::toString()
{
    string procesoToString = "PROCESO ---> PID: " + to_string(PID) + ", PPID: " + to_string(PPID) + ", Inicio del proceso: " + to_string(inicioProceso) + ", Tiempo de vida: " + to_string(tiempoVida) + ", Prioridad: " + to_string(prioridad) + ", Núcleo: " + to_string(nucleo);
    return procesoToString;
}

int Proceso::calcularTiempoEstancia()
{
    tiempoEstancia = 0;
    if (tiempoFin >= 0 && tiempoLlegada >= 0)
    {
        tiempoEstancia = tiempoFin - tiempoLlegada;
    }
    cout << "tfin: " << tiempoFin << ", tllegada: " << tiempoLlegada << ", testancia: " << tiempoEstancia << endl;

    return tiempoEstancia;
}