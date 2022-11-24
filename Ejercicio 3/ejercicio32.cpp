#include <cmath>
#include <iostream>
#include <assert.h>
using namespace std;

struct AristaHeap {
    int o;
    int d;
    int peso;
};
class Heap {
public:
    Heap(int cantAproxElem) {
        listaHeap = new AristaHeap[cantAproxElem];
        cantElementos = 0;
    }
    ~Heap() {
        delete[] listaHeap;
    }
    AristaHeap* Get(int n) {
        AristaHeap* ret = new AristaHeap;
        ret->o = listaHeap[n].o;
        ret->d = listaHeap[n].d;
        ret->peso = listaHeap[n].peso;
        return ret;
    }
    int GetCantElem() {
        return cantElementos;
    }
    void push(int o, int d, int peso) {
        listaHeap[cantElementos].o = o;
        listaHeap[cantElementos].d = d;
        listaHeap[cantElementos].peso = peso;
        flotar(cantElementos);
        cantElementos++;
    }
    AristaHeap* pop() {
        AristaHeap* ret = new AristaHeap;
        ret->o = listaHeap[0].o;
        ret->d = listaHeap[0].d;
        ret->peso = listaHeap[0].peso;
        cantElementos--;
        swap(0, cantElementos);
        hundir(0);
        return ret;
    }
    AristaHeap* top() {
        return Get(0);
    }
    bool estaVacio() {
        return cantElementos == 0;
    }
private:
    AristaHeap *listaHeap;
    int cantElementos;
    AristaHeap hijoIzq(int n) {
        return listaHeap[2 * n + 1];
    }
    int indexOfHijoIzq(int n) {
        return (2 * n + 1);
    }
    AristaHeap hijoDer(int n) {
        return listaHeap[2 * n + 2];
    }
    int indexOfHijoDer(int n) {
        return (2 * n + 2);
    }
    AristaHeap padre(int n) {
        return listaHeap[(n - 1) / 2];
    }
    int indexOfPadre(int n) {
        return ((n - 1) / 2);
    };
    void flotar(int n) {
        if (n == 0)
            return;
        if (Get(n)->peso < Get(indexOfPadre(n))->peso ) {
            swap(n, indexOfPadre(n));
            flotar(indexOfPadre(n));
        }
    }
    bool tieneHijoIzq(int n) {
        return cantElementos > (2 * n + 1);
    }
    bool tieneHijoDer(int n) {
        return cantElementos > (2 * n + 2);
    }
    bool hijoIzqMenorQueDerecho(int n) {
        return (Get(indexOfHijoIzq(n))->peso < Get(indexOfHijoDer(n))->peso);
    }
    bool hijosValenLoMismo(int n) {
        return (Get(indexOfHijoIzq(n))->peso < Get(indexOfHijoDer(n))->peso);
    }
    void hundir(int n) {
        if (tieneHijoDer(n)) {
            if (hijoIzqMenorQueDerecho(n) && (hijoIzq(n).peso < Get(n)->peso)) {
                swap(n, indexOfHijoIzq(n));
                hundir(indexOfHijoIzq(n));
            }
            else if (hijoDer(n).peso <= Get(n)->peso) {
                swap(n, indexOfHijoDer(n));
                hundir(indexOfHijoDer(n));
            }
        }
        else if (tieneHijoIzq(n) && (hijoIzq(n).peso < Get(n)->peso)) {
            swap(n, indexOfHijoIzq(n));
            hundir(indexOfHijoIzq(n));
        }
        return;
    }
    void swap(int a, int b) {
        AristaHeap aux = listaHeap[a];
        listaHeap[a] = listaHeap[b];
        listaHeap[b] = aux;
    }
};

// Codigo dado en clase por el docente Agustin Marsico. 
class MFset{
    public:
        MFset(int largo){
            this->largo = largo;
            parent = new int[largo];
            for (int i = 0; i < largo; i++){
                parent[i] = i;
            }
        }
        ~MFset(){
            delete[] parent;
        }
        int find(int e){
            if(parent[e] != e)
                return find(parent[e]);
            return parent[e];
        }
        bool merge(int x, int y){
            int setX = find(x);
            int setY = find(y);
            if(setX == setY) return false;
            parent[setY] = setX;
            return true;
        }
    private:
        int* parent;
        int largo;
};
// Fin de codigo brindado por el docente Agustin Marsico. 

class Grafo {
public:
    Grafo(int cantElementos) {
        largoVec = cantElementos;
        nombresInternos = new int [largoVec];
        verticesAIgnorar = new bool [largoVec+1];
        for (int i = 0; i < largoVec; i++) {
            nombresInternos[i] = -1;
        }
        heap = new Heap(largoVec*largoVec);
        listaAdy = new Arista *[largoVec];
        for (int i = 0; i < largoVec; i++) {
            listaAdy[i] = NULL;
        }
        for (int i = 0; i <= largoVec; i++) {
            verticesAIgnorar[i] = false;
        }
        cant = 0;
    }
    ~Grafo() {
        delete[] nombresInternos;
        for (int i = 0; i < largoVec; i++) {
            delete listaAdy[i];
        }
        delete heap;
        delete[] nombresInternos;
        delete[] listaAdy;
        delete[] verticesAIgnorar;
    }
    void insertaVertice(int v) {
        int pos = -1;
        for (int i = 0; i < largoVec; i++) {
            if (nombresInternos[i] == -1) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << "no hay lugares libres" << endl;
            return;
        }
        nombresInternos[pos] = v;
        cant++; 
    }
    void insertarArista(int origen, int destino, int peso) {
        agregarArista(origen-1, destino, peso);
        heap->push(origen-1, destino-1, pesoArista(origen, destino));
    }
    void ignorarVertice(int v){
        verticesAIgnorar[v] = true;
    }
    void agregarArista(int posOrigen, int posDestino, int peso){
        Arista* nuevo = new Arista();
        nuevo->existe = true;
        nuevo->peso = peso;
        nuevo->conexion = posDestino;
        nuevo->sig = listaAdy[posOrigen];
        listaAdy[posOrigen] = nuevo;
        return;
    }
    bool existeArista(int origen, int destino){
        Arista* aux = listaAdy[origen-1];
        while (aux != NULL) {
            if(aux->conexion == destino){
                return true;
            }
            aux = aux->sig;
        }
        return false;
    }
    bool verticeIgnorado(int v){
        if(verticesAIgnorar[v]){
            return true;
        }
        return false;
    }
    int pesoArista(int origen, int destino){
        Arista* aux = listaAdy[origen-1];
        while (aux != NULL) {
            if(aux->conexion == destino){
                return aux->peso;
            }
            aux = aux->sig;
        }
    }
    void kruskal(){
        MFset* compConexas = new MFset(largoVec);
        int cant = 0;
        int cantMax = largoVec*largoVec;
        AristaHeap** listaAristas = new AristaHeap*[cantMax];
        for(int i = 0; i < cantMax; i++){
            listaAristas[i] = new AristaHeap;
        }
        while(!heap->estaVacio() && cant < largoVec){//E*Log2(V)
            AristaHeap *edge = heap->pop();//(Log2(E)) = (Log2(V^2)) = (2*Log2(V)) = (Log2(V))
            int posO = edge->o, posD = edge->d,peso = edge->peso;
            delete edge;
            if(!verticeIgnorado(posO+1) && !verticeIgnorado(posD+1)){
                if(compConexas->merge(posO,posD)){
                    if(posO <= posD){
                        listaAristas[cant]->o = posO+1;
                        listaAristas[cant]->d = posD+1;
                        listaAristas[cant]->peso = peso;
                    }else{
                        listaAristas[cant]->o = posD+1;
                        listaAristas[cant]->d = posO+1;
                        listaAristas[cant]->peso = peso;
                    }
                    cant++;
                }
            }
        }
        delete compConexas;
        imprimirResultado(listaAristas, cant);
    }

    void imprimirResultado(AristaHeap** listaAristas, int cant){
        mergeSort(listaAristas, 0, cant-1);
        cout << cant << endl;
        for(int i = 0; i < cant; i++){
            cout << listaAristas[i]->o << " " << listaAristas[i]->d << " " << listaAristas[i]->peso << endl;
        }
    }

    void mezclar(AristaHeap** &array, int izquierda, int medio, int derecha) {
        //Divido el array original en 2, obtengo sus largos para recorrerlos y poblarlos
        int largoArrayIzquierdo = medio - izquierda + 1;
        int largoArrayDerecho = derecha - medio;
        AristaHeap** arrayIzquierdo = new AristaHeap*[largoArrayIzquierdo];
        AristaHeap** arrayDerecho = new AristaHeap*[largoArrayDerecho];
        int posArrayOriginal = izquierda;
        int pos1 = 0;
        int pos2 = 0;
        for (int i = 0; i < largoArrayIzquierdo; i++) {
            arrayIzquierdo[i] = array[izquierda + i];
        }
        for (int i = 0; i < largoArrayDerecho; i++) {
            arrayDerecho[i] = array[medio + 1 + i];
        }

        while (pos1 < largoArrayIzquierdo && pos2 < largoArrayDerecho) {
            if (arrayIzquierdo[pos1]->o < arrayDerecho[pos2]->o) {
                array[posArrayOriginal] = arrayIzquierdo[pos1];
                pos1++;
            } else if(arrayIzquierdo[pos1]->o == arrayDerecho[pos2]->o){ 
                //Chequeo por destino
                if (arrayIzquierdo[pos1]->d < arrayDerecho[pos2]->d) {
                    array[posArrayOriginal] = arrayIzquierdo[pos1];
                    pos1++;
                } else if(arrayIzquierdo[pos1]->d == arrayDerecho[pos2]->d){
                    //Chequeo por peso
                    if (arrayIzquierdo[pos1]->peso < arrayDerecho[pos2]->peso) {
                        array[posArrayOriginal] = arrayIzquierdo[pos1];
                        pos1++;
                    } else{ //Si los pesos son iguales no importa el orden
                        array[posArrayOriginal] = arrayIzquierdo[pos1];
                        pos1++;
                    }
                } else{
                    array[posArrayOriginal] = arrayDerecho[pos2];
                    pos2++;
                }
            }
            else {
                array[posArrayOriginal] = arrayDerecho[pos2];
                pos2++;
            }
            posArrayOriginal++;
        }
        while (pos1 < largoArrayIzquierdo) {
            array[posArrayOriginal] = arrayIzquierdo[pos1];
            pos1++;
            posArrayOriginal++;
        }
        while (pos2 < largoArrayDerecho) {
            array[posArrayOriginal] = arrayDerecho[pos2];
            pos2++;
            posArrayOriginal++;
        }
    }

    void mergeSort(AristaHeap** &vector, int inicio, int final) {
        if (final > inicio) {
            int medio = inicio + (final - inicio) / 2;
            mergeSort(vector, inicio, medio);
            mergeSort(vector, medio + 1, final);
            mezclar(vector, inicio, medio, final);
        }
    }
private:
    struct Arista {
        bool existe;
        int peso;
        Arista() : existe(false),sig(NULL) {}
        Arista* sig;
        int conexion;
    };
    int *nombresInternos;
    bool* verticesAIgnorar;
    Heap* heap;
    Arista **listaAdy;
    int cant;
    int largoVec;
};
void insertarAristarNuevas(Grafo *g){
    int cantAristas;
    cin >> cantAristas;
    for (int i = 0; i < cantAristas; i++) {
        int origen;
        int destino;
        int peso;
        cin >> origen;
        cin >> destino;
        cin >> peso;
        g->insertarArista(origen, destino, peso);
    }
    return;
}
void ignorarVertices(Grafo* g){
    int cantVertices;
    cin >> cantVertices;
    for(int i = 0; i < cantVertices; i++){
        int v;
        cin >> v;
        g->ignorarVertice(v);
    }
}
void imprimirArbol(Grafo *g){
    g->kruskal();
}
int main() {
    int cantVertices;
    cin >> cantVertices;
    Grafo *g = new Grafo(cantVertices);
    for (int i = 1; i <= cantVertices; i++) {
        g->insertaVertice(i);
    }
    insertarAristarNuevas(g);
    ignorarVertices(g);
    imprimirArbol(g);
    delete g;
    return 0;
}