#include <cmath>
#include <iostream>
#include <assert.h>
using namespace std;

// Codigo dado en clase por el docente Agustin Marsico. 
class MFset{
    public:
        MFset(int V){
            this->V = V;
            parent = new int[V];
            for (int i = 0; i < V; i++){
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
        int V;
};
// Fin de codigo brindado por el docente Agustin Marsico. 

struct AristaH {
    int origen;
    int destino;
    int peso;
};

// Ejercicio 2 con modificaciones
class Heap {
public:

    Heap(int cantAproxElem) 
    {
        arr = new AristaH[cantAproxElem];
        cantElementos = 0;
    }

    ~Heap() 
    {
        delete[] arr;
    }

    AristaH* getArista(int pos) 
    {
        AristaH* arista = new AristaH;
        arista->origen = arr[pos].origen;
        arista->destino = arr[pos].destino;
        arista->peso = arr[pos].peso;
        return arista;
    }

    int cantidadDeElementos() 
    {
        return cantElementos;
    }

    void insertar(int origen, int destino, int peso) 
    {
        arr[cantElementos].origen = origen;
        arr[cantElementos].destino = destino;
        arr[cantElementos].peso = peso;
        flotar(cantElementos);
        cantElementos++;
    }

    AristaH* eliminarMin() 
    {
        AristaH* aBorrar = new AristaH;
        aBorrar->origen = arr[0].origen;
        aBorrar->destino = arr[0].destino;
        aBorrar->peso = arr[0].peso;
        cantElementos--;
        intercambiar(0, cantElementos);
        hundir(0);
        return aBorrar;
    }

    AristaH* top() 
    {
        return getArista(0);
    }

    bool esVacio() 
    {
        return cantElementos == 0;
    }

private:
    AristaH *arr;
    int cantElementos;

    int posPadre(int pos) 
    {
        return ((pos - 1) / 2);
    }

    int posHijoIzq(int pos) 
    {
        return 2 * pos + 1;
    }

    int posHijoDer(int pos) 
    {
        return 2 * pos + 2;
    }

    AristaH obtenerPadre(int pos) 
    {
        return arr[(pos - 1) / 2];
    }

    AristaH obtenerHijoIzq(int pos) 
    {
        return arr[2 * pos + 1];
    }

    AristaH obtenerHijoDer(int pos) 
    {
        return arr[2 * pos + 2];
    }

    bool tengoHijoIzq(int pos) 
    {
        return cantElementos > (2 * pos + 1);
    }

    bool tengoHijoDer(int pos) 
    {
        return cantElementos > (2 * pos + 2);
    }

    bool izquierdaMenor(int pos) 
    {
        return (getArista(posHijoIzq(pos))->peso < getArista(posHijoDer(pos))->peso);
    }

    void flotar(int pos)
    {
        if (pos == 0){
            return;
        } else {
            int posPadre = this->posPadre(pos);
            int valorPadre = getArista(posPadre)->peso;
            int valorActual = getArista(pos)->peso;
            if (valorPadre > valorActual){
                intercambiar(posPadre, pos);
                flotar(posPadre);
            }
        }
    }

    void hundir(int pos) 
    {
        if (tengoHijoDer(pos)) 
        {
            if (izquierdaMenor(pos) && (obtenerHijoIzq(pos).peso < getArista(pos)->peso)) 
            {
                intercambiar(pos, posHijoIzq(pos));
                hundir(posHijoIzq(pos));
            }
            else if (obtenerHijoDer(pos).peso <= getArista(pos)->peso) 
            {
                intercambiar(pos, posHijoDer(pos));
                hundir(posHijoDer(pos));
            }
        }
        else if (tengoHijoIzq(pos) && (obtenerHijoIzq(pos).peso < getArista(pos)->peso)) 
        {
            intercambiar(pos, posHijoIzq(pos));
            hundir(posHijoIzq(pos));
        }
        return;
    }
    
    void intercambiar(int posUno, int posicionDestinoos) 
    {
        AristaH ret = arr[posUno];
        arr[posUno] = arr[posicionDestinoos];
        arr[posicionDestinoos] = ret;
    }
};

// Fin ejercicio 2 con modificaciones

class Grafo {
    private:
        struct Arista 
        {
            bool existe;
            int peso;
            Arista() : existe(false),sig(NULL) {}
            Arista* sig;
            int destino;
        };
        int *vertices;
        bool* verticesAIgnorar;
        Heap* heap;
        Arista **listaAdy;
        int cant;
        int V;
    public:

        Grafo(int _V) 
        {
            V = _V;
            cant = 0;
            vertices = new int [V];
            verticesAIgnorar = new bool [V+1];
            for (int i = 0; i < V; i++) {
                vertices[i] = -1;
            }
            heap = new Heap(V*V);
            listaAdy = new Arista *[V];
            for (int i = 0; i < V; i++) {
                listaAdy[i] = NULL;
            }
            for (int i = 0; i <= V; i++) {
                verticesAIgnorar[i] = false;
            }
        }

        ~Grafo() 
        {
            for (int i = 0; i < V; i++) {
                delete listaAdy[i];
            }
            delete[] vertices;
            delete[] listaAdy;
            delete[] verticesAIgnorar;
            delete heap;
        }

        void insertarVertice(int v) 
        {
            int pos = -1;
            for (int i = 0; i < V; i++) {
                if (vertices[i] == -1) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                return;
            } else {
                vertices[pos] = v;
                cant++; 
            }
        }

        void aniadirArista(int origen, int destino, int peso) 
        {
            agregarArista(origen-1, destino, peso);
            heap->insertar(origen-1, destino-1, pesoArista(origen, destino));
        }

        void ignorarXVertice(int v)
        {
            verticesAIgnorar[v] = true;
        }

        void agregarArista(int _posOrigen, int _posDestino, int peso)
        {
            Arista* nuevo = new Arista();
            nuevo->existe = true;
            nuevo->peso = peso;
            nuevo->destino = _posDestino;
            nuevo->sig = listaAdy[_posOrigen];
            listaAdy[_posOrigen] = nuevo;
        }
        
        bool existeArista(int origen, int destino)
        {
            Arista* ret = listaAdy[origen-1];
            while (ret != NULL) {
                if(ret->destino == destino){
                    return true;
                }
                ret = ret->sig;
            }
            return false;
        }

        int pesoArista(int origen, int destino)
        {
            // Aplica la misma idea de busqueda que en existeArista, pero devolviendo el peso.
            Arista* ret = listaAdy[origen-1];
            while (ret != NULL) {
                if(ret->destino == destino){
                    return ret->peso;
                }
                ret = ret->sig;
            }
        }
        
        bool verticeIgnorado(int v)
        {
            bool res = false;
            if(verticesAIgnorar[v]){
                res = true;
            }
            return res;
        }

        void kruskal()
        {
            MFset* conexo = new MFset(V);
            int cant = 0;
            int capacidadMaxima = V*V;
            AristaH** aristas = new AristaH*[capacidadMaxima];
            for(int i = 0; i < capacidadMaxima; i++){
                aristas[i] = new AristaH;
            }
            while(!heap->esVacio() && cant < V){
                AristaH *a = heap->eliminarMin();
                int posicionOrigen = a->origen, posicionDestino = a->destino, peso = a->peso;
                delete a;
                if(!verticeIgnorado(posicionOrigen+1) && !verticeIgnorado(posicionDestino+1)){
                    if(conexo->merge(posicionOrigen,posicionDestino)){
                        if(posicionOrigen <= posicionDestino){
                            aristas[cant]->origen = posicionOrigen+1;
                            aristas[cant]->destino = posicionDestino+1;
                            aristas[cant]->peso = peso;
                        }else{
                            aristas[cant]->origen = posicionDestino+1;
                            aristas[cant]->destino = posicionOrigen+1;
                            aristas[cant]->peso = peso;
                        }
                        cant++;
                    }
                }
            }
            delete conexo;
            resultado(aristas, cant);
        }

        void resultado(AristaH** aristas, int cant)
        {
            sort(aristas, 0, cant-1);
            cout << cant << endl;
            for(int i = 0; i < cant; i++){
                cout << aristas[i]->origen << " " << aristas[i]->destino << " " << aristas[i]->peso << endl;
            }
        }
// Otra opcion podia ser realizar un nuevo minHeap y organizar todo alli.

        void merge(AristaH** &array, int izquierda, int medio, int derecha) 
        {
            int izq = medio - izquierda + 1;
            int der = derecha - medio;
            AristaH** arrayIzquierdo = new AristaH*[izq];
            AristaH** arrayDerecho = new AristaH*[der];
            int pos = izquierda;
            int posUno = 0;
            int posDos = 0;
            for (int i = 0; i < izq; i++) {
                arrayIzquierdo[i] = array[izquierda + i];
            }
            for (int i = 0; i < der; i++) {
                arrayDerecho[i] = array[medio + 1 + i];
            }
            while (posUno < izq && posDos < der) {
                if (arrayIzquierdo[posUno]->origen < arrayDerecho[posDos]->origen) {
                    array[pos] = arrayIzquierdo[posUno];
                    posUno++;
                } else if(arrayIzquierdo[posUno]->origen == arrayDerecho[posDos]->origen){ 
                    
                    if (arrayIzquierdo[posUno]->destino < arrayDerecho[posDos]->destino) {
                        array[pos] = arrayIzquierdo[posUno];
                        posUno++;
                    } else if(arrayIzquierdo[posUno]->destino == arrayDerecho[posDos]->destino){
                        
                        if (arrayIzquierdo[posUno]->peso < arrayDerecho[posDos]->peso) {
                            array[pos] = arrayIzquierdo[posUno];
                            posUno++;
                        } else{ 
                            array[pos] = arrayIzquierdo[posUno];
                            posUno++;
                        }
                    } else{
                        array[pos] = arrayDerecho[posDos];
                        posDos++;
                    }
                }
                else {
                    array[pos] = arrayDerecho[posDos];
                    posDos++;
                }
                pos++;
            }
            while (posUno < izq) {
                array[pos] = arrayIzquierdo[posUno];
                posUno++;
                pos++;
            }
            while (posDos < der) {
                array[pos] = arrayDerecho[posDos];
                posDos++;
                pos++;
            }
        }

        void sort(AristaH** &vector, int inicio, int final) 
        {
            if (final > inicio) {
                int medio = inicio + (final - inicio) / 2;
                sort(vector, inicio, medio);
                sort(vector, medio + 1, final);
                merge(vector, inicio, medio, final);
            }
        }
};

int main() 
{
    int cantVertices;
    cin >> cantVertices;
    int cantAristas;
    cin >> cantAristas;
    Grafo *g = new Grafo(cantVertices);
    for (int i = 1; i <= cantVertices; i++) {
        g->insertarVertice(i);
    }
    int origen;
    int destino;
    int peso;
    for (int i = 0; i < cantAristas; i++) {
        cin >> origen;
        cin >> destino;
        cin >> peso;
        g->aniadirArista(origen, destino, peso);
    }
    int cantV;
    cin >> cantV;
    int v;
    for(int i = 0; i < cantV; i++){
        cin >> v;
        g->ignorarXVertice(v);
    }
    g->kruskal();
    delete g;
    return 0;
}