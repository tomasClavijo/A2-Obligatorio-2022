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

        void flotar(int pos){
            // Si estoy en la raiz, ya no puedo flotar mas.
            if (pos == 1){
                return;
            }
        }
    
    public:
        MinHeap(int capacidad){
            largo = capacidad + 1;
            proximoLibre = 1;
            arr = new int[largo]();
        }

        void insertar (int elemento){
            assert(!estaLleno);
            arr[proximoLibre] = elemento;
            proximoLibre++;
            flotar(proximoLibre - 1);
        }
        void eliminarMin(){

        }
        int getMin(){
            assert(!esVacio());
            return arr[1];
        }
        bool esVacio(){
            return proximoLibre == 1;
        }
        bool estaLleno(){
            return proximoLibre >= largo; // Puede ser == 
        }
        int cantidadDeElementos(){
            return proximoLibre - 1;
        }

};

int main(){
    return 0;
}