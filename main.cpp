#include "Pila.h"
#include "Cola.h"
#include "Sistema.h"
#include <iostream>
#include "Lista.h"
#include "SistemaLista.h"
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
    Proceso p6 = Proceso(6,7,8,4);
    Proceso p7 = Proceso(7,5,5,4);
    Proceso p8 = Proceso(8,3,2,0);
    Proceso p9 = Proceso(9,1,8,5);
    Proceso p10 = Proceso(10,2,4,4);

 int PID =-1, inicioProceso=-1,  tiempoVida=-1,  ppid=-1, prioridad=-1, p=0;

    SistemaLista sl;

    bool salir=false;
    while(!salir){
        int opcion;
cout << "\n¿Qué opción quieres?:\n";
cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
cout << "| -1 -> Volver       1 -> Crear pila       2 -> Mostrar pila       3 -> Borrar pila     4 -> Ocupación núcleos       5 -> Procesos en núcleos          |\n";
cout << "|  6 -> Pasar N min  7 -> Acabar procesos  8 -> Añadir proceso    9 -> Ver ABB        10 -> Proc. por prioridad       11 -> Prioridades ejecutadas       |\n";
cout << "| 12 -> Max/Min procesos en abb            13 -> T. promedio para 1 nivel              14 -> T. promedio para cada nivel   15 -> Tiempo estancia total    |\n";
cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
cout << "\nIntroduce una opción: ";
         cin >> opcion;
       // cout << opcion<<endl;

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
                if(sl.pilaVacia() && sl.listaVacia() && sl.nucleosVacios()){  
                    cout<<"No hay procesos que ejecutar"<<endl;
                }
                else{
                    int minutos;
                    cout << "¿Cuántos minutos quieres que pasen: ?";
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
            case 8: //añadir al abb a mano
                cout <<"Introduzca a continuación los datos del proceso a añadir (válidos porfa)"<<endl;;
                cout <<"introduce PID: ";
                cin >> PID;
                cout <<"introduce tiempo inicio proceso: ";
                cin >> inicioProceso;
                cout <<"introduce tiempo de vida: ";
                cin >> tiempoVida;
                cout <<"introduce PPID: ";
                cin >> ppid;
                cout <<"introduce prioridad: ";
                cin >> prioridad;

                sl.añadirProcesoAbbTeclado(PID,inicioProceso,tiempoVida,ppid,prioridad);
            break;

            case 9: //ver el abb
                sl.verABB();
            break;

            case 10:// Mostrar  los  procesos  con  la  prioridad  dada
                cout <<"Introduce el nivel de prioridad que quieras ver en el ABB: ";
                cin >> p;
                sl.verPrioridadDada(p);
            break;

            case 11://Mostrar  todos  los  niveles  de  prioridad  que  han  tenido  al  menos  un  proceso  ejecutado, en orden numérico
                sl.verPrioridadesEjecutadas();
            break;

            case 12: //Calcular y mostrar el nivel de prioridad con el mayor número de procesos y el de menor  número
                sl.mayorNumeroProcesos();
                cout<<"\n\n"<<endl;
                sl.menorNumeroProcesos();
            break;

            case 13: // tiempo  promedio  de  ejecución  de  los  procesos  con  una prioridad específica
                cout <<"Introduce el nivel de prioridad del que quieras ver el tiempo promedio de ejecución: ";
                cin >> p;
                sl.tiempoMedioEjecucionNivel(p);
            break;

            case 14: //tiempo promedio de ejecución de los procesos en cada nivel de  prioridad
                sl.mostrarTiemposMediosNiveles(); 
            break;

            case 15: //muestra el t.medio de estancia
                sl.tiempoMedioEstancia(); 
            break;

            default:
                    cout << "Opción no válida "<<endl;
                    break;
            }
        }
return 0;
}

