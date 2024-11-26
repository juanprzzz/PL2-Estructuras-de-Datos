//#include "Pila.h"
//#include "Cola.h"
//#include "Sistema.h"
#include <iostream>
//#include "Lista.h"
//#include "SistemaLista.h"
#include "Proceso.h"
#include "ListaProcesos.h"
#include "Arbol.h"
using namespace std;

int main(){
    Proceso p1= Proceso(1,0,5,1,2);
    Proceso p2= Proceso(2,2,3,0);    
    Proceso p3= Proceso(3,3,6,9);
    Proceso p4= Proceso(4,0,7,5);
    Proceso p5 = Proceso(5,4,3,6); 
    Proceso p6 = Proceso(6,7,8,3);
    Proceso p7 = Proceso(7,5,5,4);
    Proceso p8 = Proceso(8,3,2,0);
    Proceso p9 = Proceso(9,1,8,5);
    Proceso p10 = Proceso(10,2,4,4);

Arbol prueba;

//cout<<prueba.esVacio() <<endl;
prueba.insertarProceso(p4);
prueba.insertarProceso(p3);
prueba.insertarProceso(p5);
prueba.insertarProceso(p8);
prueba.insertarProceso(p9);
prueba.insertarProceso(p3);
prueba.insertarProceso(p3);
prueba.insertarProceso(p7);
prueba.insertarProceso(p10);

prueba.mostrarPrioridadDada(4);





/*
SistemaLista sl;
Sistema sistemaPrincipal;


bool exit=false;

while(!exit){
bool salir=false;
int menu;
cout << "|--------------|      |----------------|\n";
cout << "|   COLA DE    |      |      CPU       |\n";
cout << "|   PROCESOS   |----->|   PROCESANDO   |\n";
cout << "|--------------|      |----------------|\n\n";
cout<<"\t|------------------------|"<<endl;
cout<<"\t|                        |"<<endl;
cout<<"\t|PLANIFICADOR DE PROCESOS|"<<endl;
cout<<"\t|                        |"<<endl;
cout<<"\t|-1 -> Salir del programa|"<<endl;
cout<<"\t|                        |"<<endl;
cout<<"\t|1 -> Primera parte      |"<<endl;
cout<<"\t|                        |"<<endl;
cout<<"\t|2 -> Segunda parte      |"<<endl;
cout<<"\t|                        |"<<endl;
cout<<"\t|------------------------|"<<endl;
cout<<"\nIntroduce una opción: ";
cin >> menu;
if (menu==-1){exit=true;}
else if (menu==1){
    
    while(!salir){
    int opcion;
    cout << "\nQué opción quieres?:\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n|-1 -> Salir\t\t\t1 -> Crear pila de procesos del sistema\t\t2 -> Mostrar pila \t3 -> Borrar pila                                  |\n|                                                                                                                                                         |\n| 4 -> Mostrar cola espera\t5 -> Mostrar procesos en nucleos\t\t6 -> Pasar N minutos\t7 -> Acabar todos los procesos y/o t.medio proc.  |\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n\nIntroduce una opción: ";
    cin >> opcion;
    cout << opcion<<endl;

    switch (opcion)
    {
    case -1:
        salir=true;
        break;

    case 1: //crear pila de procesos
        if(sistemaPrincipal.pilaVacia()){
            cout << "Creando pila..."<<endl;
            sistemaPrincipal.apilarSistema(p1);
            sistemaPrincipal.apilarSistema(p2);
            sistemaPrincipal.apilarSistema(p3);
            sistemaPrincipal.apilarSistema(p4);
            sistemaPrincipal.apilarSistema(p5);
            sistemaPrincipal.apilarSistema(p6);
            sistemaPrincipal.apilarSistema(p7);
            sistemaPrincipal.apilarSistema(p8);
            sistemaPrincipal.apilarSistema(p9);
            sistemaPrincipal.apilarSistema(p10);
        }
        else{
            cout<<"¡Ya tienes una pila con procesos!"<<endl;
        }
        break;

    case 2: //mostrar la pila de procesos
        sistemaPrincipal.mostrarPilaProcesos();
        break;

    case 3: //borrar la pila de procesos
        cout << "Borrando pila..."<<endl;
        sistemaPrincipal.borrarPila();
        break;

    case 4: //mostrar la cola de prioridades
        sistemaPrincipal.mostrarColaPrioridad();
        break;

    case 5: //mostrar los procesos activos en los nucleos
        sistemaPrincipal.mostrarProcesosNucleo();
        break;

    case 6://Pasa n minutos en el sistema  
        if(sistemaPrincipal.pilaVacia() && sistemaPrincipal.colaVacia() && sistemaPrincipal.nucleosVacios()){
            cout<<"No hay procesos que ejecutar"<<endl;
        }
        else{
            int minutos;
            cout << "Cuantos minutos quieres que pasen: ";
            cin >> minutos;
            if (minutos>0){
                sistemaPrincipal.pasarTiempo(minutos);
            }
            else{
                cout << "Por favor, introduzca un número mayor que 0 "<<endl;
            }
        } 
        
        break;

    case 7:  //Pasa todo el tiempo hasta que acaben todos los procesos
        if(sistemaPrincipal.pilaVacia() && sistemaPrincipal.colaVacia() && sistemaPrincipal.nucleosVacios()){
            cout<<"No hay procesos que ejecutar"<<endl;
        }
        else{
            sistemaPrincipal.acabarProcesos();
        }   
        
        break;

    default:
        cout << "Opción no válida "<<endl;
        break;
    }
}

}


else if (menu==2) {
    while(!salir){
        int opcion;
        cout << "\nQué opción quieres?:\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n|-1 -> Volver\t\t\t1 -> Crear pila de procesos del sistema\t\t2 -> Mostrar pila \t3 -> Borrar pila                                  |\n|                                                                                                                                                         |\n| 4 -> Consultar ocupación  \t5 -> Mostrar procesos en nucleos\t\t6 -> Pasar N minutos\t7 -> Acabar todos los procesos y/o t.medio proc.  |\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n\nIntroduce una opción: ";
        cin >> opcion;
        cout << opcion<<endl;

        switch (opcion){
            case -1:
                salir=true;
                break;

            case 1: //crear pila de procesos
                if(sl.pilaVacia()){
                    cout << "Creando pila..."<<endl;
                    sl.apilarSistema(p1);
                    sl.apilarSistema(p2);
                    sl.apilarSistema(p3);
                    sl.apilarSistema(p4);
                    sl.apilarSistema(p5);
                    sl.apilarSistema(p6);
                    sl.apilarSistema(p7);
                    sl.apilarSistema(p8);
                    sl.apilarSistema(p9);
                    sl.apilarSistema(p10);
                    }
                else{
                    cout<<"¡Ya tienes una pila con procesos!"<<endl;
                     }
        
                    break;

            case 2: //mostrar la pila de procesos
                sl.mostrarPilaProcesos();
                break;

            case 3: //borrar la pila de procesos
                cout << "Borrando pila..."<<endl;
                sl.borrarPila();
                break;

            case 4: //mostrar nucleo mas y menos ocupado
                sl.mostrarOcupacion();
                break;

            case 5: //mostrar los procesos activos en los nucleos
                sl.mostrarProcesosNucleo();
                break;

            case 6://Pasa n minutos en el sistema  
                if(sl.pilaVacia() && sl.listaVacia() && sl.nucleosVacios()){  //////////////////comprobar
                    cout<<"No hay procesos que ejecutar"<<endl;
                }
                else{
                    int minutos;
                    cout << "Cuantos minutos quieres que pasen: ";
                    cin >> minutos;
                    if (minutos>0){
                        sl.pasarTiempo(minutos);
                    }
                    else{
                        cout << "Por favor, introduzca un número mayor que 0 "<<endl;
                    }
                } 
        
                break;

            case 7:  //Pasa todo el tiempo hasta que acaben todos los procesos
                    if(sl.pilaVacia() && sl.listaVacia()  && sl.nucleosVacios()){
                        cout<<"No hay procesos que ejecutar"<<endl;
                    }
                    else{
                        sl.acabarProcesos();
                }   
        
                    break;

            default:
                    cout << "Opción no válida "<<endl;
                    break;
            }
        }
    }
else{
    cout << "Opción no válida "<<endl;
}
}
*/

return 0;
}

