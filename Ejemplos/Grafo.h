#ifndef GRAPH_H
#define GRAPH_H

template <class T>
struct NodoLista{
    T el;
    NodoLista* sig;
    NodoLista(T _el, NodoLista* _sig){
        el = _el; 
        sig = _sig;
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

class Grafo{
    public:
        virtual void aniadirArista(int origen, int destino, int peso = 1) = 0;
        virtual int getV() = 0;
        virtual int getA() = 0;
        virtual NodoLista<Arista>* getAdyacentes(int origen) = 0;
        
};

#endif