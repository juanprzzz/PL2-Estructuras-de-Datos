CC = g++
CFLAGS1 = -Wall -c
CFLAGS2 = -Wall

all: PL

PL: Arbol.o Cola.o Lista.o ListaProcesos.o main.o NodoArbol.o NodoCola.o NodoLista.o NodoListaProcesos.o NodoPila.o Nucleo.o Pila.o Proceso.o Sistema.o SistemaLista.o
	$(CC) $(CFLAGS2) Arbol.o Cola.o Lista.o ListaProcesos.o main.o NodoArbol.o NodoCola.o NodoLista.o NodoListaProcesos.o NodoPila.o Nucleo.o Pila.o Proceso.o Sistema.o SistemaLista.o -o PL2

Arbol.o: Arbol.cpp Arbol.h
	$(CC) $(CFLAGS1) Arbol.cpp
Cola.o: Cola.cpp Cola.h
	$(CC) $(CFLAGS1) Cola.cpp
Lista.o: Lista.cpp Lista.h
	$(CC) $(CFLAGS1) Lista.cpp
ListaProcesos.o: ListaProcesos.cpp ListaProcesos.h
	$(CC) $(CFLAGS1) ListaProcesos.cpp
main.o:
	$(CC) $(CFLAGS1) main.cpp
NodoArbol.o: NodoArbol.cpp NodoArbol.h
	$(CC) $(CFLAGS1) NodoArbol.cpp
NodoCola.o: NodoCola.cpp NodoCola.h
	$(CC) $(CFLAGS1) NodoCola.cpp
NodoLista.o: NodoLista.cpp NodoLista.h
	$(CC) $(CFLAGS1) NodoLista.cpp
NodoListaProcesos.o: NodoListaProcesos.cpp NodoListaProcesos.h
	$(CC) $(CFLAGS1) NodoListaProcesos.cpp
NodoPila.o: NodoPila.cpp NodoPila.h
	$(CC) $(CFLAGS1) NodoPila.cpp
Nucleo.o: Nucleo.cpp Nucleo.h
	$(CC) $(CFLAGS1) Nucleo.cpp
Pila.o: Pila.cpp Pila.h
	$(CC) $(CFLAGS1) Pila.cpp
Proceso.o: Proceso.cpp Proceso.h
	$(CC) $(CFLAGS1) Proceso.cpp
Sistema.o: Sistema.cpp Sistema.h
	$(CC) $(CFLAGS1) Sistema.cpp
SistemaLista.o:SistemaLista.cpp SistemaLista.h
	$(CC) $(CFLAGS1) SistemaLista.cpp

.PHONY: clean
clean:
	rm -f *.o
