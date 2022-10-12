#ifndef GRAPH_LA_CPP
#define GRAPH_LA_CPP
#include "./Grafo.h"
#include "stddef.h"

class GrafoMA: public Grafo{
    private:

        // En el caso de que existe una arista, las coordenadas de esta matriz nos dira que peso tiene. 
        int** ponderaciones;
        // Esta matriz la usamos para saber la existencia (o no) de una arista dadas sus coordenadas.
        bool** existeArista;
        bool esDirigido;
        int V;
        int A;
        int* gradoDeEntrada;

    public:
        GrafoMA(int _V, bool _esDirigido){
            V = _V;
            esDirigido = _esDirigido; 
            // Matriz de ponderaciones
            ponderaciones = new int*[V+1]();
            // Matriz de aristas existentes
            existeArista = new bool*[V+1]();
            for (int i = 1; i <= V; i++){
                ponderaciones[i] = new int [V+1]();
                existeArista = new bool*[V+1]();
                for (int j = 1; j <= V; j++){
                    ponderaciones[i][j] = 0;
                    existeArista[i][j] = false;

                }
            }
            A = 0;
            gradoDeEntrada = new int[V+1]();
            for(int i = 0; i <= V; i++)
            {
                gradoDeEntrada[i] = 0;
            }
        }
        void aniadirArista(int origen, int destino, int peso = 1){

        }
        int getV(){
            return V;
        }
        int getA(){
            return A;
        }
};

#endif 