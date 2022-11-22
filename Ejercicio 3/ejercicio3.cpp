// Se implementa con Heap para cumplir el orden.
#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

class MFSet{
    int *parent, n;

    public:
    MFSet(int n){
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet(){
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != -1){
            return find(parent[x]);
        }
        return x;
    }

    void merge(int x, int y){
        int xset = find(x);
        int yset = find(y);

        if(xset != yset){
            parent[yset] = xset;
        }
    }
};

class Arista {
    private:
        int origen;
        int destino;
        int peso;
    public:
        Arista(int _origen, int _destino, int _peso = 1){
            origen = _origen;
            destino = _destino;
            peso = _peso;
        }
        int getOrigen(){
            return origen;
        }
        int getDestino(){
            return destino;
        }
        int getPeso(){
            return peso;
        }

};

class MinHeap{
    private:
        Arista** arr;
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
            Arista* aux = arr[pos1];
            arr[pos1] = arr[pos2];
            arr[pos2] = aux;
        }

        void flotar(int pos){
            if (pos == 1){
                return;
            } else {
                int posPadre = this->posPadre(pos);
                int valorPadre = arr[posPadre]->getPeso();
                int valorActual = arr[pos]->getPeso();
                if (valorPadre > valorActual){
                    intercambiar(posPadre, pos);
                    flotar(posPadre);
                }
            }
        }

        void hundir(int pos){
           if (tengoHijoIzq(pos)){
            int posHijoMenor = posHijoIzq(pos);
            if (tengoHijoDer(pos) && (arr[posHijoDer(pos)]->getPeso() < arr [posHijoIzq(pos)]->getPeso())){
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
            arr = new Arista*[largo]();
        }
        ~MinHeap(){
            delete [] arr;
        }
        void insertar (Arista* elemento){
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
        Arista* getMin(){
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

struct NodoLista{
    Arista* arista;
    NodoLista* sig;
    NodoLista(){}
    NodoLista(Arista* _arista, NodoLista* _sig){
        arista = _arista; 
        sig = _sig;
    }
};

class GrafoLA {
    private:
        NodoLista** listaAdy;
        int V;
        int A;
        int* gradoDeEntrada;
        MinHeap* heap; 
        bool* verticesIgnorados;
        Arista** resultado;

        void eliminarRecursiva(NodoLista* listaAdy){
            if (listaAdy != NULL){
                eliminarRecursiva(listaAdy->sig);
                delete listaAdy;
            }
        }
    public:
        GrafoLA(int _V){
            V = _V;
            listaAdy = new NodoLista*[V + 1];
            A = 0;
            gradoDeEntrada = new int[V+1]();
            for(int i = 0; i <= V; i++)
            {
                listaAdy[i] = NULL;
                gradoDeEntrada[i] = 0;
            }
            heap = new MinHeap(V*V);
            verticesIgnorados = new bool[V + 1];
            for(int i = 1; i < V + 1; i++){
                verticesIgnorados[i] = false;
            }
        }
        ~GrafoLA(){
            delete heap;
            for (int i = 1; i < V + 1; i++){
                eliminarRecursiva(listaAdy[i]);
            }
            delete [] listaAdy;
            delete [] verticesIgnorados;

        }
        void aniadirArista(int origen, int destino, int peso = 1) {
            Arista* a = new Arista(origen, destino, peso);
            NodoLista * newNodo = new NodoLista(a, listaAdy[origen]);
            listaAdy[origen] = newNodo;
            A++;
            gradoDeEntrada[destino]++;
            Arista* aDos = new Arista(destino, origen, peso);
            NodoLista * newNodoDos = new NodoLista(a, listaAdy[destino]);
            listaAdy[destino] = newNodoDos;
            A++;
            gradoDeEntrada[origen]++;
            if (origen > destino){
                heap->insertar(aDos);
            } else {
                heap->insertar(a);
            }
        }
        int getV(){
            return V;
        }
        int getA(){
            return A;
        }
        NodoLista* getAdyacentes(int origen){
            // O (1) pc;
            return listaAdy[origen];
        }
        void ignorarXVertice(int V){
            verticesIgnorados[V] = true;
        }
        Arista** Kruskall(){
            resultado = new Arista*[V-1];
            MFSet* m = new MFSet(V + 1);
            while(!heap->esVacio()){
                Arista* a = heap->getMin();
                heap->eliminarMin();
                if (!verticesIgnorados[a->getOrigen()] && !verticesIgnorados[a->getDestino()]){
                    if (m->find(a->getOrigen()) != m->find(a->getDestino())){
                        cout << a->getOrigen() << " " << a->getDestino() << endl;
                        m->merge(a->getOrigen(), a->getDestino());
                    }
                }
                delete a;
            }
        }
};

int main (){
    int cantVertices;
    cin >> cantVertices;
    int cantAristas;
    cin >> cantAristas;
    GrafoLA *g = new GrafoLA(cantVertices);
    int origen;
    int destino;
    int peso;
    for (int i = 0; i < cantAristas; i++){
        cin >> origen;
        cin >> destino;
        cin >> peso;
        g->aniadirArista(origen, destino, peso);
    }
    int verticesAIgnorar;
    cin >> verticesAIgnorar;
    int vIgnorado;
    for (int i = 0; i < verticesAIgnorar; i++){
        cin >> vIgnorado;
        g->ignorarXVertice(vIgnorado);
    }
    g->Kruskall();
    g->~GrafoLA();
};