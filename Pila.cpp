#include "Pila.h"
#include "NodoPila.h"
#include "Proceso.h"
#include <iostream>

using namespace std;


Pila::Pila(){
    cima = NULL;
}
Pila::~Pila(){   
    while(cima) {
        desapilar();
    }
}

/*
*Se encarga de apilar en la pila (sin ordenar por prioridad)
*/
 void Pila::añadir(Proceso proceso){ 
            pNodoPila nuevo = new NodoPila(proceso,cima);
            cima = nuevo;
}
/*
*Apila ordenando por prioridad (si es necesario)
*/
void Pila::apilar(Proceso proceso){
    if (esVacia() || (proceso.inicioProceso<=mostrar().inicioProceso)){
        añadir(proceso);
    }
    //Si la pila es vacía o el tiempo de inicio del nuevo es menor al del primero, añado el nuevo a la cima directamente
    else{ 
        Pila aux;
        bool insertado=false;
        while (!esVacia() && insertado==false){
            aux.añadir(mostrar()); //voy guardando los que no cumplan la condición del if de abajo. Se guarda directamente el primer elemento por la condicion del if arriba
            desapilar();
            //Voy guardando en una pila auxiliar las cimas cuyo tiempo de inicio sea menor al del nuevo y desapilando.
            if (proceso.inicioProceso<=mostrar().inicioProceso){
                añadir(proceso);
                insertado=true;
                //si el tiempo del nuevo es menor, apilo el proceso directamente a la pila original e indico que ya ha sido insertado para salir del bucle while.

            }
        }
        if (insertado==false){
            añadir(proceso);
            //si la pila se quedó vacía y el tiempo del nuevo era mayor a todos, se mete al fondo
        }

        while (!aux.esVacia()){
                    añadir(aux.mostrar());
                    aux.desapilar();
                    //una vez terminado, recuperar lo que se haya perdido de la pila, apilando los elementos en el orden en el que estaban originalmente.
                }
    }
    
}
/*
*Se encarga de devolver una copia de una pila
*/
Pila Pila::copiarPila(){
        Pila aux;
        Pila pilaCopia;
        while (!esVacia()){
            aux.añadir(mostrar());
            //pilaCopia.añadir(mostrar());
            desapilar();
        }
        while(!aux.esVacia()){
            añadir(aux.mostrar());
            pilaCopia.añadir(aux.mostrar());
            aux.desapilar();
        }
        return pilaCopia;
}


void Pila::desapilar(){ 
    pNodoPila aux;
        if(cima){
            aux = cima;
            cima = aux->siguiente;
            delete aux;  
            }
        }

bool Pila::esVacia(){
    return cima == NULL; 
}


Proceso Pila::mostrar(){   
    if(esVacia()) {
        return Proceso(); 
    }
    else{
        return cima->proceso; 
    }
}


void Pila::mostrarPila(){
    Pila aux=copiarPila();
    if(!esVacia()){
        cout<<"\nLa cima es: "<<mostrar().toString()<<endl;
        while(!aux.esVacia()){
            Proceso actual=aux.mostrar();
            cout<<actual.toString()<<endl;
            aux.desapilar();
        }
    }
    else{
        cout<<"La pila está vacía"<<endl;
    }
}