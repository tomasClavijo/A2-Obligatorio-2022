#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

class MinHeap{
    private:
        int* arr;
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
            int aux = arr[pos1];
            arr[pos1] = arr[pos2];
            arr[pos2] = aux;
        }

        void flotar(int pos){
            if (pos == 1){
                return;
            } else {
                int posPadre = this->posPadre(pos);
                int valorPadre = arr[posPadre];
                int valorActual = arr[pos];
                if (valorPadre > valorActual){
                    intercambiar(posPadre, pos);
                    flotar(posPadre);
                }
            }
        }

        void hundir(int pos){
           if (tengoHijoIzq(pos)){
            int posHijoMenor = posHijoIzq(pos);
            if (tengoHijoDer(pos) && (arr[posHijoDer(pos)] < arr [posHijoIzq(pos)])){
                posHijoMenor = posHijoDer(pos);
            }
            if(arr[pos] > arr[posHijoMenor]){
                intercambiar (pos, posHijoMenor);
                hundir (posHijoMenor);
            }
           }
        }
    
    public:
        MinHeap(int capacidad){
            largo = capacidad + 1;
            proximoLibre = 1;
            arr = new int[largo]();
        }
        ~MinHeap(){
            delete [] arr;
        }
        void insertar (int elemento){
            assert(!estaLleno());
            arr[proximoLibre] = elemento;
            proximoLibre++;
            flotar(proximoLibre - 1);
        }
        void eliminarMin(){
            assert(!esVacio());
            arr[1] = arr[proximoLibre - 1];
            proximoLibre--;
            hundir(1);
        }
        int getMin(){
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

int main(){
    int cantidadNumerosEnteros; // N cantidad de elementos
    cin >> cantidadNumerosEnteros;
    int n; // Variable para cada numero a insertar. 
    MinHeap* heap = new MinHeap(cantidadNumerosEnteros);
    for (int i = 0; i < cantidadNumerosEnteros; i++){
        cin >> n;
        heap->insertar(n);
    }
    for (int i = 0; i < cantidadNumerosEnteros; i++){
        cout << heap->getMin() <<endl;
        heap->eliminarMin();
    }
    delete heap;
}