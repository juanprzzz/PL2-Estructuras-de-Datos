#include "NodoLista.h"
#include "Lista.h"
#include "Nucleo.h"
#include "SistemaLista.h"
#include <iostream>
using namespace std;

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    ctdNucleos = 0;
    IDs = 0;
}

Lista::Lista(Nucleo n)
{
    primero = new NodoLista(n);
    ultimo = primero;
    ctdNucleos = 1;
    IDs = 1;
}

Lista::~Lista()
{
    while (!esVacia())
    {
        eliminarInicio();
    }
}

void Lista::añadirIzquierda(Nucleo nucleo)
{
    IDs++;
    ctdNucleos++;
    NodoLista *nuevo_nodo = new NodoLista(nucleo);
    if (esVacia())
    {
        primero = nuevo_nodo;
        ultimo = primero;
    }
    else
    {
        nuevo_nodo->siguiente = primero;
        primero = nuevo_nodo;
    }
}

void Lista::añadirDerecha(Nucleo nucleo)
{
    IDs ++;
    ctdNucleos++;
    NodoLista *nuevo_nodo = new NodoLista(nucleo);
    if (esVacia())
    {
        primero = nuevo_nodo;
        ultimo = primero;
    }
    else
    {
        ultimo->siguiente = nuevo_nodo; 
        ultimo = nuevo_nodo;
    }
}

void Lista::eliminarFin()
{
    NodoLista *aux; // puntero aux para manipular el nodo
    if (!esVacia() && ctdNucleos >= 2)
    { // si solo hay 1 no puedo hacer siguiente->siguiente
        aux = primero;
        while (aux->siguiente->siguiente != NULL)
        { // si el elemento siguiente tiene como atributo "siguiente" null (si el siguiente del aux es el ultimo)
            aux = aux->siguiente;
        }
        ultimo = aux;
        ultimo->siguiente = NULL;
        ctdNucleos--;
    }

    else if (ctdNucleos == 1)
    {
        primero = NULL;
        ultimo = NULL;
        ctdNucleos--;
    }
}

void Lista::eliminarInicio()
{
    if (!esVacia())
    { 
        Nucleo elemento = primero->nucleo;
        NodoLista *aux = primero;
        if ((primero == ultimo) && (primero->siguiente == NULL))
        { 
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete aux;
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete aux;
        }
        ctdNucleos--;
    }
    else if (ctdNucleos == 1)
    {
        primero = NULL;
        ultimo = NULL;
        ctdNucleos--;
    }
}

Nucleo Lista::inicio()
{
    if (!esVacia())
    {
        return primero->nucleo;
    }
    else
    {
        return Nucleo();
    }
}

Nucleo Lista::fin()
{
    if (!esVacia())
    {
        return ultimo->nucleo;
    }
    else
    {
        return Nucleo();
    }
}

void Lista::mostrarLista()
{
    if (esVacia())
    {
        cout << "lista vacia:) " << endl;
    }
    else
    {
        Lista listaCopia = copiarLista();
        while (!listaCopia.esVacia())
        {
            listaCopia.inicio().mostrarNucleo();
            listaCopia.eliminarInicio();
        }
    }
}

Lista Lista::copiarLista()
{
    Lista listaAux;
    Lista listaResultado;
    while (!esVacia())
    {
        listaAux.añadirDerecha(inicio());
        listaResultado.añadirDerecha(inicio());
        eliminarInicio();
    }
    ctdNucleos = 0;
    IDs = 0;
    while (!listaAux.esVacia())
    {
        añadirDerecha(listaAux.inicio());
        listaAux.eliminarInicio();
    }
    return listaResultado;
}


bool Lista::esVacia()
{
    return ((primero == NULL) && (ultimo == NULL));
}

int Lista::getCtdNucleos()
{
    return ctdNucleos;
}

int Lista::posicMenosOcupado(){
    if (esVacia()){
        return -1;
    }
    else{
        if (ctdNucleos == 1){
            return 1;
        }

        else{ 
            NodoLista *aux; // puntero aux para manipular el nodo
            Lista resultado;
            Nucleo nucleoAux;
            aux = primero;
            nucleoAux = primero->nucleo;
            resultado.añadirDerecha(nucleoAux);
            int posic=1;
            int len1=0; 
            int len2=0;
            int procesovacio1=0;
            int procesovacio2=0;
            int contadordiferencia=1; 

            while (aux->siguiente != NULL){ // hasta que llegue al final de los elementos
                aux = aux->siguiente;
                contadordiferencia++;
                if(nucleoAux.procesoEjecucion.tiempoVida>0){procesovacio1=1;}
                else{procesovacio1=0;}
                if(aux->nucleo.procesoEjecucion.tiempoVida>0){procesovacio2=1;}
                else{procesovacio2=0;}
                len1=(nucleoAux.colaEspera.get_longitud()+procesovacio1);
                len2=(aux->nucleo.colaEspera.get_longitud()+procesovacio2);

                if (len1 > len2){
                    resultado.~Lista(); // si encuentra que el siguiente nucleo de la lista está menos ocupado, borra la lista y lo mete
                    nucleoAux = aux->nucleo;
                    resultado.añadirDerecha(nucleoAux);
                    posic=contadordiferencia; 
                }
                else if (len1 == len2){
                    nucleoAux = aux->nucleo; // si encuentra que el siguiente nucleo esta igual de ocupado, lo añade también a la lista
                    resultado.añadirDerecha(nucleoAux);
                }
            } 
            return posic;
        }
    }
}

void Lista::menosOcupado()
{
 if (esVacia())
    {
        cout << "Está vacía" << endl;
    }
else
    {
        if (ctdNucleos == 1)
        {
            cout << "Hay 1 núcleo solo:" << endl;
            mostrarLista();
        }

        else
        {
            NodoLista *aux; // puntero aux para manipular el nodo
            Lista resultado;
            Nucleo nucleoAux;
            aux = primero;
            nucleoAux = primero->nucleo;
            resultado.añadirDerecha(nucleoAux);int contador=1;
            int len1=0; 
            int len2=0;
            int procesovacio1=0;
            int procesovacio2=0;

            while (aux->siguiente != NULL){ // hasta que llegue al final de los elementos
                aux = aux->siguiente;

                if(nucleoAux.procesoEjecucion.tiempoVida>0){procesovacio1=1;}
                else{procesovacio1=0;}
                if(aux->nucleo.procesoEjecucion.tiempoVida>0){procesovacio2=1;}
                else{procesovacio2=0;}
                len1=(nucleoAux.colaEspera.get_longitud()+procesovacio1);
                len2=(aux->nucleo.colaEspera.get_longitud()+procesovacio2);

                if (len1 > len2)
                {
                    resultado.~Lista(); // si encuentra que el siguiente nucleo de la lista está menos ocupado, borra la lista y lo mete
                    nucleoAux = aux->nucleo;
                    resultado.añadirDerecha(nucleoAux);
                   
                }
                else if (len1 == len2)
                {
                    nucleoAux = aux->nucleo; // si encuentra que el siguiente nucleo esta igual de ocupado, lo añade también a la lista
                    resultado.añadirDerecha(nucleoAux);
                }
            }
            resultado.mostrarLista();
        }
    }
}

void Lista::masOcupado()
{
    if (esVacia())
    {
        cout << "Está vacía" << endl;
    }
else
    {
        if (ctdNucleos == 1)
        {
            cout << "Hay 1 núcleo solo:" << endl;
            mostrarLista();
        }

        else 
        {
            NodoLista *aux; // puntero aux para manipular el nodo
            Lista resultado;
            Nucleo nucleoAux;
            aux = primero;
            nucleoAux = primero->nucleo;
            resultado.añadirDerecha(nucleoAux);int posic=1;
            int len1=0; 
            int len2=0;
            int procesovacio1=0;
            int procesovacio2=0;

            while (aux->siguiente != NULL){ // hasta que llegue al final de los elementos
                aux = aux->siguiente;
                //Se tendrá en cuenta la longitud de la cola y si el proceso es vacío o no
                if(nucleoAux.procesoEjecucion.tiempoVida>0){procesovacio1=1;}
                else{procesovacio1=0;}
                if(aux->nucleo.procesoEjecucion.tiempoVida>0){procesovacio2=1;}
                else{procesovacio2=0;}
                len1=(nucleoAux.colaEspera.get_longitud()+procesovacio1);
                len2=(aux->nucleo.colaEspera.get_longitud()+procesovacio2); 

                if (len1 < len2)
                {
                    resultado.~Lista(); // si encuentra que el siguiente nucleo de la lista está más ocupado, borra la lista y lo mete
                    nucleoAux = aux->nucleo;
                    resultado.añadirDerecha(nucleoAux);
                   
                }
                else if (len1 == len2)
                {
                    nucleoAux = aux->nucleo; // si encuentra que el siguiente nucleo esta igual de ocupado, lo añade también a la lista
                    resultado.añadirDerecha(nucleoAux);
                }
            }
            resultado.mostrarLista();
        }
    }
}

bool Lista::comprobarAñadirNuevosNucleos()
{
    Lista listaCopia = copiarLista();
    bool añadir = true;
    while (!listaCopia.esVacia() && añadir)
    {
        Cola c = listaCopia.inicio().colaEspera;
        int len = c.get_longitud();
        if (len < 2)
        {
            añadir = false;
        }
        listaCopia.eliminarInicio();
    }
    return añadir;
}

void Lista::añadirNuevoNucleo()
{
    if (comprobarAñadirNuevosNucleos())
    {
        añadirDerecha(Nucleo(IDs + 1));
    }
}

int Lista::comprobarEliminarNucleos()
{
    Lista listaCopia = copiarLista();
    int nucleosVacios = 0;
    while (!listaCopia.esVacia())
    {
        if (listaCopia.inicio().colaEspera.es_vacia() && listaCopia.inicio().procesoEjecucion.nucleo == -1) //Si la cola de espera está vacía y los núcleos no ejecutan ningún proceso
        {
            nucleosVacios++;
        }

        listaCopia.eliminarInicio();
    }
    if (ctdNucleos - nucleosVacios == 0) //Si la diferencia de los núcleos totales y vacíos es 0, entonces puedo eliminar n - 1 núcleos
    {
        nucleosVacios--;
    }
    cout<<"aaaa"<<endl;
    return nucleosVacios;
}
void Lista::eliminarNucleosVacios(int nucleosVacios)
{
    cout<<"bbbbbb"<<endl;
    Lista listaNoEliminados;
    int nucleosEliminados = 0;
    //Lista N = Lista();
    while (nucleosEliminados != nucleosVacios) // Elimino tantos núcleos como se indiquen (no sirve con for, eliminaría menos núcleos, pueden pasar 20 núcleos hasta poder eliminar 3 porque el resto están ocupados)
    {
        if (!(inicio().colaEspera.es_vacia() && inicio().procesoEjecucion.nucleo == -1)) // Si la cola de espera no está vacía, y hay un proceso ejecución, no puedo eliminarlo
        {
            cout<<"fdfs"<<endl;
            listaNoEliminados.añadirDerecha(inicio());
        }
        else
        {
            cout<<"La cuenta de procesos del núcleo "<<inicio().ID <<" es: "<<inicio().contadorProcesos<<endl;
         nucleosEliminados++;
         //N.añadirDerecha(inicio());
        }
        
        eliminarInicio();
    }
    while (!listaNoEliminados.esVacia()) //Vuelco los núcleos ocupados en la lista principal
    {
        añadirDerecha(listaNoEliminados.inicio());
        listaNoEliminados.eliminarInicio();
    }
    //return N;
}
