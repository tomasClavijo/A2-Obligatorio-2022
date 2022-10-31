#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

struct nodo {
    int vertice;
    int gradoIncidencia;
};

class MaxHeap{
    private:
        nodo** arr;
        int proximoLibre;
        int largo;

        int posPadre(int pos){
            return pos / 2;
        }

        int posHijoIzq(int pos){
            return pos * 2;
        }

        int posHijoDer(int pos){
            return pos * 2 + 1;
        }

        bool tengoHijoIzq(int pos){
            return proximoLibre > posHijoIzq(pos);
        }

        bool tengoHijoDer(int pos){
            return proximoLibre > posHijoDer(pos);
        }

        void intercambiar(int pos1, int pos2){
            nodo* aux = arr[pos1];
            arr[pos1] = arr[pos2];
            arr[pos2] = aux;
        }

        void flotar(int pos){
            if (pos == 1){
                return;
            } else {
                int posPadre = this->posPadre(pos);
                int valorPadre = arr[posPadre]->gradoIncidencia;
                int valorActual = arr[pos]->gradoIncidencia;
                if (valorPadre < valorActual){
                    intercambiar(posPadre, pos);
                    flotar(posPadre);
                } else if (valorPadre == valorActual){
                    if (arr[posPadre]->vertice < arr[pos]->vertice){
                        intercambiar(posPadre, pos);
                        flotar(posPadre);
                    }
                }
            }
        }

        void hundir(int pos){
           if (tengoHijoIzq(pos)){
            int posHijoMayor = posHijoIzq(pos);
            if (tengoHijoDer(pos) && (arr[posHijoDer(pos)]->gradoIncidencia > arr [posHijoIzq(pos)]->gradoIncidencia)){
                posHijoMayor = posHijoDer(pos);
            } else if (arr[posHijoDer(pos)]->gradoIncidencia == arr[posHijoIzq(pos)]->gradoIncidencia){
                if (arr[posHijoDer(pos)]->vertice > arr[posHijoIzq(pos)]->vertice){
                    posHijoMayor = posHijoDer(pos);
                }
            }
            if(arr[pos]->gradoIncidencia < arr[posHijoMayor]->gradoIncidencia){
                intercambiar (pos, posHijoMayor);
                hundir (posHijoMayor);
            } else if (arr[pos]->gradoIncidencia == arr[posHijoMayor]->gradoIncidencia){
                if (arr[pos]->vertice < arr[posHijoMayor]->vertice){
                    intercambiar (pos, posHijoMayor);
                    hundir (posHijoMayor);
                }
            }
           }
        }
    
    public:
        MaxHeap(int capacidad){
            largo = capacidad + 1;
            proximoLibre = 1;
            arr = new nodo*[largo]();
        }
        ~MaxHeap(){
            delete [] arr;
        }
        void insertar (nodo* elemento){
            assert(!estaLleno());
            arr[proximoLibre] = elemento;
            proximoLibre++;
            flotar(proximoLibre - 1);
        }
        void eliminarMax(){
            assert(!esVacio());
            arr[1] = arr[proximoLibre - 1];
            proximoLibre--;
            hundir(1);
        }
        nodo* getMax(){
            assert(!esVacio());
            return arr[1];
        }
        bool esVacio(){
            return proximoLibre == 1;
        }
        bool estaLleno(){
            return proximoLibre >= largo; 
        }
        int cantidadDeElementos(){
            return proximoLibre - 1;
        }

};

int main (){
    int cantidadVertices; 
    cin >> cantidadVertices;
    int cantidadAristas;
    cin >> cantidadAristas;
    int* arr = new int [cantidadVertices + 1];
    for (int i = 0; i < cantidadVertices + 1; i++){
        arr[i] = 0;
    }
    for(int i = 1; i < cantidadAristas + 1; i++){
        int origen;
        cin >> origen;
        int destino;
        cin >> destino;
        arr[destino]++;
    }
    MaxHeap* heap = new MaxHeap(cantidadVertices);
    for(int i = 1; i < cantidadVertices + 1; i++){
        nodo* n = new nodo();
        n->gradoIncidencia = arr[i];
        n->vertice = i;
        heap->insertar(n);
    }
    for (int i = 1; i < cantidadVertices + 1; i++){
        nodo* n = heap->getMax();
        heap->eliminarMax();
        int gradoIncidencia = n->gradoIncidencia;
        int vertice = n->vertice;
        cout << vertice << " " << gradoIncidencia << endl;
        delete n;
    }
}