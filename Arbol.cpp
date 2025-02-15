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
    if (p.prioridad <= raiz->prioridad) // si la prioridad del proceso es menor o igual que la raiz, busca en la izquierda
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
        if (prioridad < raiz->prioridad && hijoIzquierdo != nullptr)
        {
            return hijoIzquierdo->estáPrioridad(prioridad);
        }
        else if (prioridad > raiz->prioridad && hijoDerecho != nullptr)
        {
            return hijoDerecho->estáPrioridad(prioridad);
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
void Arbol::mostrarArbol()
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

void Arbol::mostrarPrioridadesEjecutadas()
{
    // Recorrido inorden para garantizar el orden numérico de las prioridades
    if (hijoIzquierdo != NULL)
    {
        hijoIzquierdo->mostrarPrioridadesEjecutadas();
    }

    // Mostrar la prioridad actual, ya que todos los procesos han sido ejecutados
    cout << "La prioridad " << raiz->prioridad << " ha ejecutado los siguientes procesos: " << endl;
    raiz->listaProcesos.mostrarListaProcesos();

    if (hijoDerecho != NULL)
    {
        hijoDerecho->mostrarPrioridadesEjecutadas();
    }
}

void Arbol::mayorNumeroProcesosAux(Arbol *&mayorProcesos) // Para que se pase por referencia, si no, se pasa por valor
{
    if (mayorProcesos->raiz->listaProcesos.len() == raiz->listaProcesos.len() && raiz->prioridad != 4) // Si tienen la misma cantidad de procesos hay que mostrarlos (inicialmente el 4 tendrá los mismos procesos que mayorProcesos, y como ya está en el arbol, se omite)
    {
        ListaProcesos copiaProcesos = raiz->listaProcesos.copiarLista(); // Hay que hacer copia para no modificar raiz->listaProcesos
        while (!copiaProcesos.esVacia())
        {
            mayorProcesos->insertarProceso(copiaProcesos.inicio()); // Va insertando los procesos en las prioridades correspondientes
            copiaProcesos.eliminarInicio();
        }
    }
    if (mayorProcesos->raiz->listaProcesos.len() < raiz->listaProcesos.len()) // Si mayorProcesos tiene menos procesos que la prioridad raíz del árbol/subárbol entonces hay que rehacer el árbol
    {
        mayorProcesos->~Arbol();
        ListaProcesos copiaProcesos = raiz->listaProcesos.copiarLista();
        mayorProcesos->raiz->prioridad = raiz->prioridad; // Siempre tiene que haber una raíz por definición
        while (!copiaProcesos.esVacia())
        {
            mayorProcesos->insertarProceso(copiaProcesos.inicio()); // Insertamos el proceso en el árbol en la prioridad correspondiente (se puede hacer con insertarProceso o con mayorProcesos->raíz->listaProcesos.añadirDerecha ya que solo vamos a añadir la raíz)
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
    Arbol *mayorProcesos = new Arbol();
    mayorProcesos->raiz->prioridad = raiz->prioridad;
    ListaProcesos copiaListaRaiz = raiz->listaProcesos.copiarLista();
    while (!copiaListaRaiz.esVacia())
    {
        mayorProcesos->raiz->listaProcesos.añadirPorDerecha(copiaListaRaiz.inicio()); // Insertamos en la raíz de mayorProcesos la lista de procesos de la prioridad raíz (será siempre 4)
        //mayorprocesos->insertarProceso(copiaProcesos.inicio())
        copiaListaRaiz.eliminarInicio();
    }

    mayorNumeroProcesosAux(mayorProcesos);
    cout << "Estas son las prioridades con mayor número de procesos: " << endl;
    mayorProcesos->mostrarArbol();
}

void Arbol::menorNumeroProcesosAux(Arbol *&menorProcesos)
{                                                                                                      // Para que se pase por referencia, si no, se pasa por valor
    if (menorProcesos->raiz->listaProcesos.len() == raiz->listaProcesos.len() && raiz->prioridad != 4) // Si tienen la misma cantidad de procesos y si la raíz es != 4 (porque prioridad 4 ya se encuentra en menorProcesos de la asignación en la función anterior)
    {
        ListaProcesos copiaProcesos = raiz->listaProcesos.copiarLista(); // Hay que hacer copia para no modificar raiz->listaProcesos
        while (!copiaProcesos.esVacia())
        {
            menorProcesos->insertarProceso(copiaProcesos.inicio()); // Va insertando los procesos en las prioridades correspondientes
            copiaProcesos.eliminarInicio();
        }
    }
    if (menorProcesos->raiz->listaProcesos.len() > raiz->listaProcesos.len()) // Si menorProcesos tiene más procesos que la prioridad raíz del árbol/subárbol entonces hay que rehacer el árbol
    {
        menorProcesos->~Arbol();
        menorProcesos->raiz->prioridad = raiz->prioridad; // Por definición, el árbol siempre tiene que tener un nodo raiz con una prioridad bien definida
        ListaProcesos copiaProcesos = raiz->listaProcesos.copiarLista();
        while (!copiaProcesos.esVacia())
        {
            menorProcesos->insertarProceso(copiaProcesos.inicio());
            // Insertamos el proceso en el árbol en la prioridad correspondiente (se puede hacer con insertarProceso o con mayorProcesos->raíz->listaProcesos.añadirDerecha ya que solo vamos a añadir la raíz)
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
    ListaProcesos copiaListaRaiz = raiz->listaProcesos.copiarLista(); // copiar listaProcesos de la raiz para no modificar la original
    while (!copiaListaRaiz.esVacia())                                 // metemos en el nuevo arbol auxiliar la raiz; Si solo hay un nodo en el arbol, será el mayor/menor por defecto
    {
        menorProcesos->raiz->listaProcesos.añadirPorDerecha(copiaListaRaiz.inicio());
        copiaListaRaiz.eliminarInicio();
    }
    menorNumeroProcesosAux(menorProcesos); // modificamos el arbol si la raiz no fuera el de menor num. de procesos
    cout << "Estas son las prioridades con menos procesos: " << endl;
    menorProcesos->mostrarArbol();
}

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
    raiz->prioridad = -1;
    raiz->listaProcesos.~ListaProcesos();

    hijoIzquierdo = nullptr;
    hijoDerecho = nullptr;
}

double Arbol::tiempoMedioEjecucionNivel(int p)
{
    if (estáPrioridad(p))
    {
        if (raiz->prioridad == p)
        {
            double tmedio = raiz->listaProcesos.tiempoMedioEjecucionLista();
            return tmedio;
        }
        else
        {
            if (hijoIzquierdo != NULL && p <= raiz->prioridad)
            {
                return hijoIzquierdo->tiempoMedioEjecucionNivel(p);
            }
            else if (hijoDerecho != NULL && p > raiz->prioridad)
            {
                return hijoDerecho->tiempoMedioEjecucionNivel(p);
            }
        }
    }

    cout << "El nivel de prioridad dado no existe." << endl;
    return -1;
}

double Arbol::tiempoMedioEstancia()
{
    double sumaTiempos = 0;
    int cuentaProcesos = 0;
    double resultado = 0;

    // Llamada auxiliar para recorrer el árbol
    tiempoMedioEstanciaAux(sumaTiempos, cuentaProcesos);
    cout << "La suma de los tiempos de los procesos es: "<<sumaTiempos << endl;
    cout <<"Ctd de procesos: " <<cuentaProcesos << endl;
    // Calcular la media final
    if (cuentaProcesos > 0)
    {
        resultado = (double)sumaTiempos / cuentaProcesos;
        cout << "La media total es: " << resultado << endl;
    }
    else
    {
        cout << "El árbol está vacío." << endl;
    }
    return resultado;
}

double Arbol::tiempoMedioEstanciaAux(double &sumaTiempos, int &cuentaProcesos)
{
    // Sumar tiempo de ejecución del nivel actual
    sumaTiempos += raiz->listaProcesos.sumaTiemposEstancia();
    cuentaProcesos += raiz->listaProcesos.len();
    // Recursión para hijos izquierdo y derecho
    if (hijoIzquierdo != NULL)
    {
        cout << "----------Nodos izquierdos----------" << endl;
        hijoIzquierdo->tiempoMedioEstanciaAux(sumaTiempos, cuentaProcesos);
    }
    if (hijoDerecho != NULL)
    {
        cout << "----------Nodos derechos----------" << endl;
        hijoDerecho->tiempoMedioEstanciaAux(sumaTiempos, cuentaProcesos);
    }
    return sumaTiempos;
}

void Arbol::mostrarTiemposMediosNiveles()
{
    cout << "NODO PRIORIDAD " << raiz->prioridad << endl;
    raiz->listaProcesos.tiempoMedioEjecucionLista();

    if (hijoIzquierdo != NULL)
    {
        cout << "----------Nodos izquierdos----------" << endl;
        hijoIzquierdo->mostrarTiemposMediosNiveles();
    }
    if (hijoDerecho != NULL)
    {
        cout << "----------Nodos derechos----------" << endl;
        hijoDerecho->mostrarTiemposMediosNiveles();
    }
}