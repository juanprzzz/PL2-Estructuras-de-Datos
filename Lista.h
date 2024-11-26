#ifndef LISTA_H
#define LISTA_H
#include "Nucleo.h"
#include "NodoLista.h"

class Lista{
    private:
        NodoLista* primero; //o NodoLista*
        NodoLista* ultimo;
        int ctdNucleos;
        int IDs;

        friend class SistemaLista; 
    public:
        Lista(); 
        Lista(Nucleo nucleo);
        ~Lista();
        
        void añadirDerecha(Nucleo nucleo); //añade nucleo al final
        void añadirIzquierda(Nucleo nucleo); //añade nucleo al inicio
        Nucleo inicio();
        Nucleo fin();
        void eliminarFin();
        void eliminarInicio();
        int getCtdNucleos(); //longitud de la lista
        void mostrarLista(); 
        bool esVacia();
        Lista copiarLista();
        void menosOcupado(); //muestra cual es el nucleo menos ocupado 
        int posicMenosOcupado(); //igual que menos ocupado pero devuelve la posicion
        void masOcupado(); //muestra cual es el nucleo con más procesos
        bool comprobarAñadirNuevosNucleos();
        void añadirNuevoNucleo();
        int comprobarEliminarNucleos();
        void eliminarNucleosVacios(int nucleosVacios);

};

#endif 