#include "ListaProcesos.h"
#include <iostream>

using namespace std;

ListaProcesos::ListaProcesos(){
    primero = NULL;
    ultimo = primero;
}

ListaProcesos::ListaProcesos(Proceso p){
    primero = new NodoListaProcesos(p);
    ultimo = primero;
}
ListaProcesos::~ListaProcesos(){
    while(!esVacia()){
        eliminarInicio();
    }
}
void ListaProcesos::añadirPorIzquierda(Proceso p){
    NodoListaProcesos *nuevoNodo = new NodoListaProcesos(p);
    if(esVacia()){
        primero = nuevoNodo;
        ultimo = primero;
    }
    else{
        NodoListaProcesos *aux = primero;
        primero = nuevoNodo;
        primero->siguiente = aux;
    }
}
void ListaProcesos::añadirPorDerecha(Proceso p){
    NodoListaProcesos *nuevoNodo = new NodoListaProcesos(p);
    if(esVacia()){
       
        ultimo = nuevoNodo;
        primero = ultimo;
    }
    else{
        ultimo->siguiente = nuevoNodo;
        ultimo = nuevoNodo;
        
    }
}
bool ListaProcesos::esVacia(){
    return primero == NULL && ultimo == NULL;
}
Proceso ListaProcesos::inicio(){
    return !esVacia() ? primero->proceso : Proceso();
}
Proceso ListaProcesos::fin(){
    return !esVacia() ? ultimo->proceso : Proceso();
}
void ListaProcesos::eliminarInicio(){
    if(!esVacia()){
        if(primero == ultimo){
            //primero->siguiente = NULL; En principio no sería necesaria ya que primero->siguiente == ultimo
            primero = NULL;
            ultimo = NULL;
        }
        else{
            NodoListaProcesos *aux = primero;
            primero = primero->siguiente;
            aux->siguiente = NULL;
            if(primero == ultimo){
                ultimo = primero;
            }
            delete aux;
        }
        
    }
}
void ListaProcesos::eliminarFin(){
    if(primero == ultimo){
        primero = NULL;
        ultimo = NULL;
    }
    else{
        NodoListaProcesos *aux = primero;
        while(primero->siguiente != NULL){
            aux = aux->siguiente;
        }
        ultimo = aux;
        if(ultimo == primero){
            primero = ultimo;
        }
    }
}
ListaProcesos ListaProcesos::copiarLista(){
    ListaProcesos def;
    ListaProcesos aux;
    while(!esVacia()){
        aux.añadirPorDerecha(inicio());
        def.añadirPorDerecha(inicio());
        eliminarInicio();
    }
    while(!aux.esVacia()){
        añadirPorDerecha(aux.inicio());
        aux.eliminarInicio();
    }
    return def;
}
void ListaProcesos::mostrarListaProcesos(){
    
    if(esVacia()){
        cout <<"Lista vacía"<<endl;
    }
    else{
        ListaProcesos aux = copiarLista();
        while(!aux.esVacia()){
            cout<<aux.primero->proceso.toString()<<endl;
            aux.eliminarInicio();
        }
        
    }
}
int ListaProcesos::len(){
    ListaProcesos listaProcesosCopia = copiarLista();
    int cuenta = 0;
   /* while(!esVacia()){
        cuenta+=1;
        eliminarInicio();
    }*/
    while(!listaProcesosCopia.esVacia()){
        //añadirPorDerecha(listaProcesosCopia.inicio());
        cuenta++;
        listaProcesosCopia.eliminarInicio();
    }
    return cuenta;
}

double ListaProcesos::tiempoMedioEjecucionLista(){
    int suma=0;
    double media=0;
    ListaProcesos aux = copiarLista();
        while(!aux.esVacia()){
            //cout<<aux.primero->proceso.toString()<<endl;
            suma+=aux.inicio().calcularTiempoEstancia();
            aux.eliminarInicio();
        }
    media=(double)suma/len();
    return media;
}

int ListaProcesos::sumaTiemposEstancia(){
    int suma=0;
    double media=0;
    ListaProcesos aux = copiarLista();
        while(!aux.esVacia()){
            //cout<<aux.primero->proceso.toString()<<endl;
            suma+=aux.inicio().calcularTiempoEstancia();
            aux.eliminarInicio();
        }
    return suma; 
} 