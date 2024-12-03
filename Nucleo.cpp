#include "Nucleo.h"
#include "Cola.h"
#include "Proceso.h"
#include <string>


Nucleo::Nucleo(){
    colaEspera=Cola();
    procesoEjecucion=Proceso();
    ID=-1;
    contadorProcesos = 0;
}

Nucleo::Nucleo(int id){
    colaEspera = Cola();
    procesoEjecucion=Proceso();
    ID=id;
    contadorProcesos = 0;
}

void Nucleo::mostrarNucleo(){
    if(ID!=-1){ //nucleo no vacio
        cout<<"\n---------------------NUCLEO "<<ID<<"---------------------"<<endl;
        colaEspera.mostrarCola();
        cout<<"PROCESO EJECUTÁNDOSE:"<<endl;
        if (procesoEjecucion.PID!=-1){cout<<procesoEjecucion.toString()<<endl;}
        else{cout<<"Proceso vacío. Nada se está ejecutando."<<endl;}
        cout<<"---------------------------------------------------"<<endl;
    }
    else{
        cout<<"El nucleo "<<ID<<" está vacío"<<endl;
    }
    
}

Nucleo::~Nucleo(){}


string Nucleo::mostrarProcesoEjecucion(){
    return procesoEjecucion.toString();
}

//setters
void Nucleo::añadirProceso(Proceso p){
    colaEspera.encolarPrioridad(p);
}

void Nucleo::desencolarProceso(){
    colaEspera.desencolar();
}

Proceso Nucleo::PrimeroCola(){
    return colaEspera.inicio();
}

void Nucleo::ejecutarProceso(Proceso p){
   procesoEjecucion=p;
}

Proceso Nucleo::terminarProceso(){
   Proceso paux = procesoEjecucion; /////////////////
   procesoEjecucion=Proceso();
   contadorProcesos ++;
   return paux;
}

void Nucleo::lenCola(){
    colaEspera.get_longitud();
}