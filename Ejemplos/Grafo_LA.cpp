#ifndef GRAPH_LA_CPP
#define GRAPH_LA_CPP
#include "./Grafo.h"
#include "stddef.h"

class GrafoLA : public Grafo{
    private:
        // Propiedades.
        NodoLista<Arista>** listaAdy;
        bool esDirigido;
        int V;
        int A;
        int* gradoDeEntrada;

    public:
        GrafoLA(int _V, bool _esDirigido){
            V = _V;
            listaAdy = new NodoLista<Arista>*[V + 1];
            A = 0;
            esDirigido = _esDirigido;
            gradoDeEntrada = new int[V+1]();
            for(int i = 0; i <= V; i++)
            {
                listaAdy[i] = NULL;
                gradoDeEntrada[i] = 0;
            }
        }
        // Implementacion de metodos.
        void aniadirArista(int origen, int destino, int peso = 1) {
            Arista a(origen, destino, peso);
            NodoLista<Arista> * newNodo = new NodoLista<Arista>(a, listaAdy[origen]);
            listaAdy[origen] = newNodo;
            A++;
            gradoDeEntrada[destino]++;
            // En caso de no ser dirigido, debemos insertar el nodo tambien en la pos del nodo destino.
            if(!esDirigido){
                Arista a(destino, origen, peso);
                NodoLista<Arista> * newNodo = new NodoLista<Arista>(a, listaAdy[destino]);
                listaAdy[destino] = newNodo;
                A++;
                gradoDeEntrada[origen]++;
            }
        }
        int getV(){

        }
        int getA(){

        }
        NodoLista<Arista>* getAdyacentes(int origen){

        }
};

#endif