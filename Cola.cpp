#include "NodoCola.h"
#include "Cola.h"
#include <iostream>

using namespace std;

Cola::Cola(){
    primero = NULL;
    ultimo = NULL;
    len=0;
}

Cola::~Cola() {}

void Cola::encolar(Proceso proceso){
    NodoCola *nuevo_nodo = new NodoCola(proceso);
    if (es_vacia()){
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else{
        ultimo->siguiente = nuevo_nodo; // puntero->atributo
        ultimo = nuevo_nodo;
    }
    len++;
}
/*
 *Se encarga de introducir un proceso en el lugar que le corresponde por prioridad en la cola
 */
void Cola::encolarPrioridad(Proceso proceso){
    Cola aux;
    
    while (!es_vacia() && inicio().prioridad <= proceso.prioridad)
    { // Mientras que la cola no esté vacía y el primer elemento de la cola sea más prioritario que el otro proceso
        aux.encolar(inicio());
        desencolar();
    }
    aux.encolar(proceso); // Cuando la prioridad del primer proceso de la cola es menor, entonces se encola el proceso que quiero (ya que es más prioritario)
    while (!es_vacia())
    { // Tengo que encolar en la cola aux el resto de elementos que se han quedado en la cola principal
        aux.encolar(inicio());
        desencolar();
    }
    len=0;
    while (!aux.es_vacia())
    { // Como la función no devuelve nada, si no que modifica la cola principal, tengo que introducir los elementos de la cola aux en la principal
        encolar(aux.inicio());
        aux.desencolar();
    }
}

void Cola::desencolar(){
    if (!es_vacia()){
        Proceso elemento = primero->proceso;
        NodoCola *aux = primero;
        if ((primero == ultimo) && (primero->siguiente == NULL)){
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete (aux);
        }
        else{
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete (aux);
        }
        len--;
    }
}

void Cola::eliminarFin(){
    if (!es_vacia()){
        NodoCola *aux = primero;
    
        if ((primero == ultimo) && (primero->siguiente == NULL)){
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
           
        }
        else {
            while (aux->siguiente->siguiente!=NULL){
                aux=aux->siguiente;
            }
            ultimo=aux;
            ultimo->siguiente=NULL;
         
        }
        len--;
        
    }
}


Proceso Cola::inicio(){
    if (!es_vacia()){
        return primero->proceso;
    }
    else{
        return Proceso();
    }
}

Proceso Cola::fin(){
    if (!es_vacia()){
        return ultimo->proceso;
    }
    else{
        return Proceso();
    }
}

bool Cola::es_vacia(){
    return ((primero == NULL) && (ultimo == NULL));
}

void Cola::mostrarCola()
// No es correcto, la cola solo puede verse mostrando el primero y desencolando, se implementa para comprobar código facilmente.
{
    NodoCola *aux = primero;
    if (es_vacia()) {
        cout << "La cola está vacía"<< endl;
    }
    else{
        cout << "COLA: " << endl;
        while (aux){
            if(aux->proceso.nucleo != -1){
                cout << aux->proceso.toString() << endl;
            }
            aux = aux->siguiente;
        }
    }
}

Cola Cola::copiarCola()
{
    Cola aux;
    Cola copia;
    len=0;
    while (!es_vacia())
    {
        aux.encolar(inicio());
        copia.encolar(inicio());
        desencolar();
    }
    while (!aux.es_vacia())
    {
        encolar(aux.inicio());
        aux.desencolar();
    }
    return copia;
}


int Cola::get_longitud(){
    return len;}