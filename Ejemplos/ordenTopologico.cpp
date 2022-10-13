#include <iostream>
#include <limits>
#include "./Pila.cpp"
#include "./Grafo.h"
#include "./Grafo_LA.cpp"
#include "./Grafo_MA.cpp"

using namespace std;

int* calcularGradoDeEntrada(Grafo* g){
    int * gradoDeEntrada = new int[g->getV() + 1]();
    for (int i = 1; i<= g->getV(); i++){
        NodoLista<Arista> * ady = g->getAdyacentes(i);
        while(ady != NULL){
            gradoDeEntrada[ady->el.getDestino()]++;
            ady = ady->sig;
        }
    }
    return gradoDeEntrada;
}

void ordenTopologico(Grafo* g){
    int * indiceDeEntrada = calcularGradoDeEntrada(g);
    Pila<int> * listos = new Pila<int>();
    for(int i = 1; i<= g->getV(); i++){
        if(indiceDeEntrada[i] == 0){
            listos->push(i);
        }
    }
    int verticesProcesados = 0;
    while(!listos->esVacia()){
        int vertice = listos->pop();
        verticesProcesados++;
        cout << vertice << endl;
        NodoLista<Arista>* ady = g->getAdyacentes(vertice);
        while (ady != NULL){
            int destino = ady->el.getDestino();
            indiceDeEntrada[destino]--;
            if(indiceDeEntrada[destino] == 0){
                listos->push(destino);
            }
            ady = ady->sig;

        }
    }
    if (verticesProcesados < g->getV()){
        cout << "Hay un ciclo en la sala!" << endl;
    }
}