#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

// En esta clase defino los operadores por mi cuenta, por lo que puedo comparar los objetos en base a la edad.
class Persona{
    private: 
        string nombre;
        string apellido;
        int edad;
    public:
        Persona(string _nombre, string _apellido, int _edad){
            nombre = _nombre;
            apellido = _apellido;
            edad = _edad;
        }
        Persona(){
            nombre = "";
            edad = 0;
        }
        string getNombre(){return nombre;}
        string getApellido(){return apellido;}
        int getEdad(){return edad; }

        /* OPCIONAL: 
        bool operator<(Persona p){
            return this->getEdad() < p.getEdad();
        }
        bool operator>(Persona p){
            return this->getEdad() > p.getEdad();
        }
        bool operator==(Persona p){
            return this->getNombre() == p.getNombre() && this->getApellido() == p.getApellido();
        }
        */
};

template <class T>
class MinHeap{
    private:
        int* arr;
        int proximoLibre;
        int largo;
        /* La funcion compara dos elementos de tipo T. 
        Si es positivo, entonces el segundo elemento es mayor que el primero
        Si es negativo, entonces el primer elemento es mayor que el segundo.
        Si es cero, son comparativamente iguales
        */
        int (*fnComparacion)(T,T);

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

        // Intercambia los elementos de las dos posiciones dadas por parametro.
        void intercambiar(int pos1, int pos2){
            T aux = arr[pos1];
            arr[pos1] = arr[pos2];
            arr[pos2] = aux;
        }

        void flotar(int pos){
            // Si estoy en la raiz, ya no puedo flotar mas.
            if (pos == 1){
                return;
            } else {
                int posPadre = this->posPadre(pos);
                T valorPadre = arr[posPadre];
                T valorActual = arr[pos];
                // Necesito flotar
                if (fnComparacion(valorPadre, valorActual) < 0){
                    intercambiar(posPadre, pos);
                    flotar(posPadre);
                }
            }
        }

        void hundir(int pos){

           if (tengoHijoIzq(pos)){
            // Por defecto mi menor hijo es el izquierdo
            int posHijoMenor = posHijoIzq(pos);
            // Si tengo hijo derecho, y es menor que el izquierdo, entonces lo cambio.
            if (tengoHijoDer(pos) && fnComparacion(arr[posHijoDer(pos)],arr [posHijoIzq(pos)]) > 0){
                posHijoMenor = posHijoDer(pos);
            }
            // Si necesito hundirme...
            if(fnComparacion(arr[pos],arr[posHijoMenor]) < 0){
                intercambiar (pos, posHijoMenor);
                hundir (posHijoMenor);
            }
           }
        }
    
    public:
        MinHeap(int capacidad, bool (*fComparacion)(T,T)){
            largo = capacidad + 1;
            proximoLibre = 1;
            arr = new T[largo]();
            fnComparacion = fComparacion;
        }

        void insertar (T elemento){
            assert(!estaLleno);
            arr[proximoLibre] = elemento;
            proximoLibre++;
            flotar(proximoLibre - 1);
        }
        void eliminarMin(){
            assert(!esVacio());
            // Reemplazo la raiz por el ultimo elemento del heap.
            arr[1] = arr[proximoLibre - 1];
            proximoLibre--;
            hundir(1);
        }
        T getMin(){
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

int comparacionPersona(Persona p1, Persona p2){
    return p2.getEdad() - p1.getEdad();
}

int comparacionPersona2(Persona p1, Persona p2){
    if(p1.getNombre()>p2.getNombre()){
        return -1;
    } else if(p1.getNombre() < p2.getNombre()){
        return 1;
    }
    return 0;
}

int main(){
    MinHeap<Persona> * heap = new MinHeap<Persona>(30);
    Persona p("per 1", "ap1", 29);
    Persona p2("per 2", "ap2", 30);
    Persona p3("per 3", "ap2", 33);
    Persona p4("per 4", "ap2", 22);
    Persona p5("per 4", "ap2", 44);

    if(p4 ==p){
        cout << "Son la misma persona" << endl;
    }

    heap->insertar(p);
    heap->insertar(p2);
    heap->insertar(p3);
    heap->insertar(p4);

    while(!heap->esVacio()){
        Persona menor = heap->getMin();
        cout << menor.getNombre() << endl;
        heap->eliminarMin();
    }

    return 0;
    
}