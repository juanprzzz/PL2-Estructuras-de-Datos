#include "SistemaLista.h"
#include <iostream>
#include <string>

using namespace std;

SistemaLista::SistemaLista()
{
    Pila pilaProcesos;
    Lista lista;
    Arbol abb;
}

SistemaLista::~SistemaLista()
{
    // Destructor
}

/*
 *Funciones auxiliares para el menu del main
 */
void SistemaLista::añadirNucleo(Nucleo n)
{
    lista.añadirDerecha(n);
}
void SistemaLista::borrarPila()
{
    pilaProcesos.~Pila();
}
void SistemaLista::mostrarPilaProcesos()
{
    pilaProcesos.mostrarPila();
}

bool SistemaLista::pilaVacia()
{
    return pilaProcesos.esVacia();
}
bool SistemaLista::listaVacia()
{
    return lista.esVacia();
}

void SistemaLista::mostrarProcesosNucleo()
{
    lista.mostrarLista();
}

void SistemaLista::mostrarOcupacion(){
    cout<<"Màs ocupado:"<<endl;
    lista.masOcupado();
    cout<<"Menos ocupado:"<<endl;
    lista.menosOcupado();
}

void SistemaLista::apilarSistema(Proceso p)
{
    if (p.inicioProceso < tiempoTranscurrido)
    {
        cout << "No se puede añadir ese proceso, el minuto en el que se tiene que iniciar ese proceso, ya ocurrió" << endl;
    }
    else
    {
        pilaProcesos.apilar(p);
        ctdProcesos++;
    }
}

/*
 * Se encarga de que transcurra en el sistema N minutos. Se encarga de llamar a las funciones correspondientes para mostrar
 * los núcleos cada minuto, asignación de procesos...
 */

void SistemaLista::pasarTiempo(int N)
{
    for (int i = 0; i < N; i++)
    {       
        procesoComienzo(); // Se comprueba si hay algún proceso que inicie en este minuto. Si lo hay, se añade a la cola
        Lista aux = lista.copiarLista();
        lista.~Lista();

        while (!aux.esVacia())
        {
            if (aux.primero->nucleo.procesoEjecucion.tiempoVida ==0)
            {
                cout << "\nHa finalizado el siguiente proceso al final del minuto " << tiempoTranscurrido - 1 << " del sistema: " << aux.primero->nucleo.mostrarProcesoEjecucion() << endl;
                tiempoFinalizacion += tiempoTranscurrido; // como ha acabado un proceso, se suma el tiempo actual al tiempo de finalización
                aux.primero->nucleo.procesoEjecucion.tiempoFin=tiempoTranscurrido;
                Proceso pact=aux.primero->nucleo.terminarProceso();    // Además, como ahora el núcleo está vacío, se sustituye el proceso finalizado por uno vacío con todos los valores a -1
                //pact.tiempoFin=tiempoTranscurrido;
                abb.insertarProceso(pact); //se podria hacer directamente abb.insertarProceso(aux.primero->nucleo.procesoEjecucion
            }else{
                aux.primero->nucleo.procesoEjecucion.tiempoVida--; 
            }
            if (aux.primero->nucleo.procesoEjecucion.PID == -1 && !aux.primero->nucleo.colaEspera.es_vacia())
            { // Si el proceso en ejecucion está vacío (no hay) y la cola no está vacía
                Proceso procesoNuevo = aux.primero->nucleo.PrimeroCola();//primerocola=colaEspera.inicio()
                aux.primero->nucleo.ejecutarProceso(procesoNuevo);
                aux.primero->nucleo.colaEspera.desencolar();
                aux.primero->nucleo.procesoEjecucion.tiempoVida--; 

                cout << "\nSe ha introducido al inicio del minuto " << tiempoTranscurrido << " del sistema, el Proceso con PID " << aux.primero->nucleo.procesoEjecucion.PID << endl;
            }
            lista.añadirDerecha(aux.inicio());//meto cada elemento de aux,lista pero modificado, de vuelta en lista
            aux.eliminarInicio();
        }
        lista.eliminarNucleosVacios(lista.comprobarEliminarNucleos()); //compruebo si se pueden eliminar nucleos vacios 
        
        cout << "\nESTADO DE LOS NÚCLEOS. MINUTO: " << tiempoTranscurrido << endl;
        lista.mostrarLista();

        tiempoTranscurrido++;
    }
}

/*
 * Mira la pila de procesos, si nos encontramos en el minuto en el que se inicia un (o varios) nuevo proceso, lo mete en una cola auxiliar ordenado por prioridad (para que un proceso menos prioritario no se ejecute antes que otro)
 * Después, de la cola auxiliar mete cada proceso en la cola de un nucleo/se lo asigna si puede. Si es necesario, se crean más nucleos
 */
void SistemaLista::procesoComienzo()
{

    // primero creo una cola auxiliar para guardar todos los elementos que inician en este minuto
    Cola colaNuevos;
    while (tiempoTranscurrido == pilaProcesos.mostrar().inicioProceso)
    {
        Proceso paux=pilaProcesos.mostrar();
        paux.tiempoLlegada=tiempoTranscurrido;
        colaNuevos.encolarPrioridad(paux);
        pilaProcesos.desapilar();
        tiempoLlegada += tiempoTranscurrido;
    }

    // si hay elementos que inician en este minuto...
    while (!colaNuevos.es_vacia())
    {
        if (lista.primero != NULL) // Lista no vacia
        {
            NodoLista *aux;
            aux = lista.primero;
            bool añadido = false;

            int posic=lista.posicMenosOcupado();
            for (int i=1;i<posic;i++){
                if (aux->siguiente != NULL){aux = aux->siguiente;}
            }
            if (aux->nucleo.procesoEjecucion.tiempoVida == 0)
            {
                cout << "\nHa finalizado el siguiente proceso al final del minuto " << tiempoTranscurrido - 1 << " del sistema: " << aux->nucleo.mostrarProcesoEjecucion() << endl;
                aux->nucleo.procesoEjecucion.tiempoFin=tiempoTranscurrido;
                tiempoFinalizacion += tiempoTranscurrido; // como ha acabado un proceso, se suma el tiempo actual al tiempo de finalización
                Proceso pact=aux->nucleo.terminarProceso();    // Además, como ahora el núcleo está vacío, se sustituye el proceso finalizado por uno vacío con todos los valores a -1
                abb.insertarProceso(pact); 
            }

            if (!aux->nucleo.colaEspera.es_vacia() && aux->nucleo.procesoEjecucion.PID == -1)
            { // compruebo si hay algo que meter a ejecutar desde la cola del propio nucleo o si es mas prioritario el nuevo a añadir.
                // si la cola estuviera llena con 2 procesos y no hubiera ninguno ejecutandose, no cabrian mas y se crearia un nuevo nucleo.
                // Sin embargo, realmente habría que meter el más prioritario de la cola de espera a ejecucion y ya no sería necesario el nuevo nucleo (en un nucleo caben 3 procesos, no 2)
                Proceso ejecutar;
                if (colaNuevos.fin().prioridad < aux->nucleo.PrimeroCola().prioridad){
                    ejecutar = colaNuevos.fin();
                    añadido=true;
                    ejecutar.nucleo = aux->nucleo.ID;
                    colaNuevos.eliminarFin();
                }
                    //si el nuevo a añadir en esa posicion tiene mas prioridad que el 1o de la lista, se ejecuta el nuevo
                else{
                    ejecutar = aux->nucleo.PrimeroCola();
                    aux->nucleo.desencolarProceso(); }
                //ejecutar.nucleo = aux->nucleo.ID;
                aux->nucleo.ejecutarProceso(ejecutar);
                cout << "\nSe ha introducido al inicio del minuto " << tiempoTranscurrido << " del sistema, el Proceso con PID " << aux->nucleo.procesoEjecucion.PID << endl;
                
            }

            if (!añadido && aux->nucleo.colaEspera.get_longitud() < 2)
                { // si el elemento marcado por aux tiene menos de 2 procesos en su cola de espera puedo añadir un nuevo proceso
                    Proceso procesoNuevo = colaNuevos.fin();
                    procesoNuevo.nucleo = aux->nucleo.ID;
                    aux->nucleo.añadirProceso(procesoNuevo);
                    colaNuevos.eliminarFin();
                    añadido = true;
                }
            
               
            if (!añadido) // Si no se ha podido añadir a ningun nucleo, todos estaban llenos, se crea uno nuevo
            {             // si todos los nucleos estaban llenos (El ultimo elemento tiene aux->siguiente = NULL y por eso se cambian los procesos)
                
                if(lista.comprobarAñadirNuevosNucleos()){
                    lista.añadirNuevoNucleo();
                    Proceso procesoNuevo = colaNuevos.inicio();
                    procesoNuevo.nucleo = lista.ultimo->nucleo.ID;
                    lista.ultimo->nucleo.ejecutarProceso(procesoNuevo); // Como los procesos a añadir ya van ordenados por orden de prioridad, se puede ejecutar directamente
                    colaNuevos.desencolar();
                }
                else{
                    Proceso procesoNuevo = colaNuevos.fin();
                    procesoNuevo.nucleo = lista.ultimo->nucleo.ID;
                    lista.ultimo->nucleo.añadirProceso(procesoNuevo);
                    colaNuevos.eliminarFin();
                }    
            }
        }
        else // Lista vacía
        {
            // si la lista está vacia se crea nuevo nucleo, y como es nuevo puedo comenzar a ejecutar el proceso más prioritario actual de la cola
            lista.añadirNuevoNucleo(); // si la lista está vacia se crea nuevo nucleo
            Proceso procesoNuevo = colaNuevos.inicio();
            procesoNuevo.nucleo = lista.primero->nucleo.ID;
            lista.primero->nucleo.ejecutarProceso(procesoNuevo); // Como los procesos a añadir ya van ordenador por orden de prioridad, se puede ejecutar directamente
            colaNuevos.desencolar();
            
        }
    }
}


void SistemaLista::acabarProcesos()
{

    // solo saldrá del bucle una vez que ninguna condición se cumpla. Es decir, cuando la pila sea vacía y todos los núcleos estén vacíos

    while (!pilaProcesos.esVacia() || !nucleosVacios())
    {
        //   ahora el while deberia ser mientras que la pila no este vacia, la longitud de la cola no sea 1 ese 1 elemento este vacio
        pasarTiempo(1);
    }
    double tiempoMedio = (double)(tiempoFinalizacion - tiempoLlegada) / ctdProcesos;
    cout << "La suma de los tiempos de llegada de todos los procesos es: " << tiempoLlegada << endl;
    cout << "La suma de los tiempos de finalización de todos los procesos es: " << tiempoFinalizacion << endl;
    cout << "\n El tiempo medio de estancia es: " << tiempoMedio << endl;
    cout << "\nEL ARBOL ES: " << endl;
    abb.mostrarArbol();
    cout << "\nT.medio ejecucion:" << endl;
    //abb.tiempoMedioEjecucionNivel(5);
    abb.tiempoMedioEstancia();
    cout << "\n//////////////////////////////////////////////////////// " << endl;
    abb.mayorNumeroProcesos();
    abb.menorNumeroProcesos();
}
bool SistemaLista::nucleosVacios()
{
    Lista aux = lista.copiarLista();
    lista.~Lista();
    int nucleosVacios = 0;
    bool todosVacios = false;
    while (!aux.esVacia())
    {
        if (aux.inicio().procesoEjecucion.nucleo == -1 && aux.inicio().colaEspera.es_vacia())
        { // Si en el núcleo no se ejecuta nada, y la cola está vacía
            nucleosVacios++;
        }
        lista.añadirDerecha(aux.inicio());
        aux.eliminarInicio();
    }
    if (nucleosVacios == lista.ctdNucleos)
    {
        todosVacios = true;
    }
    return todosVacios;
}