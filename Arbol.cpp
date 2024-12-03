#include "Arbol.h"
#include <iostream>
using namespace std;

Arbol::Arbol()
{
    int p = 4;
    ListaProcesos l;
    raiz = new NodoArbol(p, l);
    hijoIzquierdo = NULL;
    hijoDerecho = NULL;
}
Arbol::Arbol(int prioridad, ListaProcesos l)
{
    raiz = new NodoArbol(prioridad, l);
    hijoIzquierdo = NULL;
    hijoDerecho = NULL;
}
NodoArbol *Arbol::verRaiz()
{
    return raiz;
}
Arbol *Arbol::hijoIzqdo()
{
    return hijoIzquierdo;
}

Arbol *Arbol::hijoDcho()
{
    return hijoDerecho;
}
bool Arbol::esVacio()
{
    return raiz->prioridad == 4 && hijoIzquierdo == NULL && hijoDerecho == NULL;
}

void Arbol::insertarProcesoEnArbol(Proceso p) // si no está ese nivel de prioridad
{
    /*
    if (raiz->prioridad == -1) { int prioridad = p.prioridad;
        raiz->listaProcesos.añadirPorDerecha(p);
        raiz->prioridad = prioridad;
    }*/
    if (p.prioridad <= raiz->prioridad) // si la prioridad del proceso es menor o igual que la raiz, busca en la izquierda
    // raiz->prioridad != -1 &&
    {
        if (hijoIzquierdo == NULL) // si el hijo izquierdo es NULL, crea nuevo nodo con lista nueva y la prioridad del proceso a añadir
        {
            int prioridad = p.prioridad;
            ListaProcesos l;
            l.añadirPorDerecha(p);
            hijoIzquierdo = new Arbol(prioridad, l);
        }
        else // si no, sigue recursivamente
        {
            hijoIzquierdo->insertarProcesoEnArbol(p);
        }
    }
    else if (p.prioridad > raiz->prioridad)
    {
        if (hijoDerecho == NULL)
        {
            int prioridad = p.prioridad;
            ListaProcesos l;
            l.añadirPorDerecha(p);
            hijoDerecho = new Arbol(prioridad, l);
        }
        else
        {
            hijoDerecho->insertarProcesoEnArbol(p);
        }
    }
}

void Arbol::insertarProceso(Proceso p)
{
    if (estáPrioridad(p.prioridad))
    { // si la prioridad no es la actual pero el nivel está en el árbol
        if (raiz->prioridad == p.prioridad)
        { // si la prioridad de la raiz actual es la misma que la del proceso, añadir en lista
            raiz->listaProcesos.añadirPorDerecha(p);
        }
        else if (hijoIzquierdo != NULL && p.prioridad <= raiz->prioridad)
        {
            hijoIzquierdo->insertarProceso(p);
        }
        else if (hijoDerecho != NULL && p.prioridad > raiz->prioridad)
        {
            hijoDerecho->insertarProceso(p);
        }
    }
    else
    { // si no está, insertar nuevo nodo con ese proceso
        insertarProcesoEnArbol(p);
    }
}

bool Arbol::estáPrioridad(int prioridad)
{
    if (raiz->prioridad == prioridad)
    {
        return true;
    }
    else
    {
        if (hijoIzquierdo != NULL && hijoIzquierdo->estáPrioridad(prioridad))
        {
            return true;
        }
        if (hijoDerecho != NULL && hijoDerecho->estáPrioridad(prioridad))
        {
            return true;
        }
        return false;
    }
}
void Arbol::mostrarPrioridadDada(int p)
{
    if (estáPrioridad(p))
    {
        if (raiz->prioridad == p)
        {
            cout << "Los procesos con prioridad " << p << " son: " << endl;
            raiz->listaProcesos.mostrarListaProcesos();
        }
        else
        {
            if (hijoIzquierdo != NULL && p <= raiz->prioridad)
            {
                hijoIzquierdo->mostrarPrioridadDada(p);
            }
            else if (hijoDerecho != NULL && p > raiz->prioridad)
            {
                hijoDerecho->mostrarPrioridadDada(p);
            }
        }
    }
    else
    {
        cout << "La prioridad no existe en el árbol" << endl;
    }
}
void Arbol::mostrarArbol() // falta mostrar tiempo vivo en el SO
{                          // PRIMERO MUESTRA TODO EL LADO IZQUIERDO POSIBLE, LUEGO LADO DERECHO
    if (hijoIzquierdo == NULL && hijoDerecho == NULL)
    {
        cout << "Nodo prioridad " << raiz->prioridad << endl;
        cout << "Lista de procesos: " << endl;
        raiz->listaProcesos.mostrarListaProcesos();
    }
    else
    {
        cout << "NODO PRIORIDAD " << raiz->prioridad << endl;
        cout << "Lista de procesos: " << endl;
        raiz->listaProcesos.mostrarListaProcesos();
        if (hijoIzquierdo != NULL)
        {
            cout << "----------Nodos izquierdos----------" << endl;
            hijoIzquierdo->mostrarArbol();
        }
        if (hijoDerecho != NULL)
        {
            cout << "----------Nodos derechos----------" << endl;
            hijoDerecho->mostrarArbol();
        }
    }
}

void Arbol::mostrarPrioridadesEjecutadas() //// REVISAR IMPRIME DOS VECES EL 4
{
    if (hijoIzquierdo == NULL && hijoDerecho == NULL) // Si los dos son nulos es el valor más pequeño posible
    {
        cout << "La prioridad " << raiz->prioridad << " ha ejecutado los siguientes procesos: " << endl;
        raiz->listaProcesos.mostrarListaProcesos();
    }
    else
    {
        if (hijoIzquierdo != NULL) // Si tiene hijo izquierdo hay otro valor más pequeño
        {
            hijoIzquierdo->mostrarPrioridadesEjecutadas();
            cout << "La prioridad " << raiz->prioridad << " ha ejecutado los siguientes procesos: " << endl; // Imprimirá el segundo valor más pequeño (ya que si no puedo ir más a la izquieda)
            raiz->listaProcesos.mostrarListaProcesos();
        }
        if (hijoDerecho != NULL)
        {
            if (raiz->prioridad != 4)
            {                                                                                                    // De esta forma no muestra dos veces el 4 (ya que sube dos veces)
                cout << "La prioridad " << raiz->prioridad << " ha ejecutado los siguientes procesos: " << endl; // Antes de meternos hay que imprimir el valor ya que es el más pequeño de los que quedan
                raiz->listaProcesos.mostrarListaProcesos();
            }

            hijoDerecho->mostrarPrioridadesEjecutadas();
        }
    }
}
void Arbol::mayorNumeroProcesosAux(Arbol *&mayorProcesos) // Para que se pase por referencia, si no, se pasa por valor
{
    if (mayorProcesos->raiz->listaProcesos.len() == raiz->listaProcesos.len() && raiz->prioridad != 4) // Si tienen la misma cantidad de procesos hay que mostrarlos (inicialmente el 4 tendrá los mismos procesos que mayorProcesos, y como ya está en el arbol, se omite)
    {
        ListaProcesos copiaProcesos = raiz->listaProcesos.copiarLista(); //Hay que hacer copia para no modificar raiz->listaProcesos
        while (!copiaProcesos.esVacia())
        {
            mayorProcesos->insertarProceso(copiaProcesos.inicio());//Va insertando los procesos en las prioridades correspondientes
            copiaProcesos.eliminarInicio();
        }
    }
    if (mayorProcesos->raiz->listaProcesos.len() < raiz->listaProcesos.len())//Si mayorProcesos tiene menos procesos que la prioridad raíz del árbol/subárbol entonces hay que rehacer el árbol
    {
        mayorProcesos->~Arbol();
        ListaProcesos copiaProcesos = raiz->listaProcesos.copiarLista();
        mayorProcesos->raiz->prioridad = raiz->prioridad; // Siempre tiene que haber una raíz por definición
        while (!copiaProcesos.esVacia())
        {
            mayorProcesos->insertarProceso(copiaProcesos.inicio()); //Insertamos el proceso en el árbol en la prioridad correspondiente (se puede hacer con insertarProceso o con mayorProcesos->raíz->listaProcesos.añadirDerecha ya que solo vamos a añadir la raíz)
            copiaProcesos.eliminarInicio();
        }
    }
    if (hijoIzquierdo != nullptr)
    {
        hijoIzquierdo->mayorNumeroProcesosAux(mayorProcesos);
    }

    if (hijoDerecho != nullptr)
    {
        hijoDerecho->mayorNumeroProcesosAux(mayorProcesos);
    }
}

void Arbol::mayorNumeroProcesos()
{
    //Arbol *mayorProcesos = new Arbol(raiz->prioridad, raiz->listaProcesos); No funcionaba usando esto
    Arbol *mayorProcesos = new Arbol();
    mayorProcesos->raiz->prioridad = raiz->prioridad;
    ListaProcesos copiaListaRaiz = raiz->listaProcesos.copiarLista();
    while (!copiaListaRaiz.esVacia())
    {
        mayorProcesos->raiz->listaProcesos.añadirPorDerecha(copiaListaRaiz.inicio()); //Insertamos en la raíz de mayorProcesos la lista de procesos de la prioridad raíz (será siempre 4)
        copiaListaRaiz.eliminarInicio();
    }
    
    mayorNumeroProcesosAux(mayorProcesos);
    cout << "Estas son las prioridades con mayor número de procesos: " << endl;
    mayorProcesos->mostrarArbol();
}

void Arbol::menorNumeroProcesosAux(Arbol *&menorProcesos)
{ // Para que se pase por referencia, si no, se pasa por valor
    if (menorProcesos->raiz->listaProcesos.len() == raiz->listaProcesos.len() && raiz->prioridad != 4) //Si tienen la misma cantidad de procesos y si la raíz es != 4 (porque prioridad 4 ya se encuentra en menorProcesos de la asignación en la función anterior)
    {
        ListaProcesos copiaProcesos = raiz->listaProcesos.copiarLista();//Hay que hacer copia para no modificar raiz->listaProcesos
        while (!copiaProcesos.esVacia())
        {
            menorProcesos->insertarProceso(copiaProcesos.inicio()); //Va insertando los procesos en las prioridades correspondientes
            copiaProcesos.eliminarInicio();
        }
    }
    if (menorProcesos->raiz->listaProcesos.len() > raiz->listaProcesos.len()) //Si menorProcesos tiene más procesos que la prioridad raíz del árbol/subárbol entonces hay que rehacer el árbol
    {
        menorProcesos->~Arbol();
        menorProcesos->raiz->prioridad = raiz->prioridad; // Por definición, el árbol siempre tiene que tener un nodo raiz con una prioridad bien definida
        ListaProcesos copiaProcesos = raiz->listaProcesos.copiarLista();
        while (!copiaProcesos.esVacia())
        {

            menorProcesos->insertarProceso(copiaProcesos.inicio());//Insertamos el proceso en el árbol en la prioridad correspondiente (se puede hacer con insertarProceso o con mayorProcesos->raíz->listaProcesos.añadirDerecha ya que solo vamos a añadir la raíz)

            copiaProcesos.eliminarInicio();
        }
    }
    if (hijoIzquierdo != nullptr)
    {
        hijoIzquierdo->menorNumeroProcesosAux(menorProcesos);
    }
    if (hijoDerecho != nullptr)
    {
        hijoDerecho->menorNumeroProcesosAux(menorProcesos);
    }
}
void Arbol::menorNumeroProcesos()
{
    Arbol *menorProcesos = new Arbol();
    menorProcesos->raiz->prioridad = raiz->prioridad;
    ListaProcesos copiaListaRaiz = raiz->listaProcesos.copiarLista();
    while (!copiaListaRaiz.esVacia())
    {
        menorProcesos->raiz->listaProcesos.añadirPorDerecha(copiaListaRaiz.inicio());
        copiaListaRaiz.eliminarInicio();
    }
    menorNumeroProcesosAux(menorProcesos);
    cout << "Estas son las prioridades con menos procesos: " << endl;
    menorProcesos->mostrarArbol();
}
/*
void Arbol::destruirArbol(Arbol *a)
{
  if (hijoDerecho != NULL)
  {
      destruirArbol(hijoDerecho);
  }
  if (hijoIzquierdo != NULL)
  {
      destruirArbol(hijoIzquierdo);
  }
  // destruirArbol(hijoDerecho);
  // destruirArbol(hijoIzquierdo);
  delete raiz;
  if (raiz == nullptr)
  {
      cout << "PUNTERO NULO" << endl;
  }
}*/

Arbol::~Arbol()
{
    if (hijoDerecho != NULL)
    {
        hijoDerecho->~Arbol();
    }
    if (hijoIzquierdo != NULL)
    {
        hijoIzquierdo->~Arbol();
    }
    // destruirArbol(hijoDerecho);
    // destruirArbol(hijoIzquierdo);
    raiz->prioridad = NULL;
    raiz->listaProcesos.~ListaProcesos();

    // raiz = nullptr;

    hijoIzquierdo = nullptr;
    hijoDerecho = nullptr;
}

int Arbol::tiempoMedioEjecucionNivel(int p)
{
    if (estáPrioridad(p))
    {
        if (raiz->prioridad == p)
        {
            int tmedio = raiz->listaProcesos.tiempoMedioEjecucionLista();
            cout << "el tiempo medio de p es: " << tmedio << endl;
            return tmedio;
        }
        else
        {
            if (hijoIzquierdo != NULL && p <= raiz->prioridad)
            {
                hijoIzquierdo->tiempoMedioEjecucionNivel(p);
            }
            else if (hijoDerecho != NULL && p > raiz->prioridad)
            {
                hijoDerecho->tiempoMedioEjecucionNivel(p);
            }
        }
    }
    else
    {
        return -1;
    }
}
