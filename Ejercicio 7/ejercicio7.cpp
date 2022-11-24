#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

struct Nodo{
    int dato;
    Nodo * sig;
};

struct PilaInt{
     Nodo* contenido;
     Nodo* fin;
     int numeroDeElementos;
};
       
PilaInt* crearPila(){
    PilaInt* pila = new PilaInt;
    pila->numeroDeElementos = 0;
    pila->contenido = NULL;
    pila->fin = NULL;
    return pila;
}        

bool esVacia(PilaInt* pila){
    return pila->numeroDeElementos == 0;
}
void push(PilaInt*& pila, int elemento){
    Nodo * nodo = new Nodo();
    nodo->dato = elemento;
    nodo->sig = NULL;
    if (esVacia(pila)){
        pila->contenido = nodo;
        pila->fin = pila->contenido;
    } else {
        pila->fin->sig = nodo;
        pila->fin = pila->fin->sig;
    }
    pila->numeroDeElementos++;
}
int top(PilaInt* pila){
    return pila->contenido->dato;
}
void pop(PilaInt*& pila){
    Nodo* aBorrar = new Nodo();
    aBorrar = pila->contenido;
    pila->contenido = pila->contenido->sig;
    delete aBorrar;
    pila->numeroDeElementos--;
}

void eliminarPrincipio(Nodo*& lista) {
	if (lista != NULL) {
		Nodo* aBorrar = lista;
		lista = lista->sig;
		delete aBorrar;
	}
}

void destruir(PilaInt*& pila) {
	while (pila->contenido != NULL) {
		eliminarPrincipio(pila->contenido);
	}
	delete pila;
	pila == NULL;
}

int maximaSumatoria(PilaInt* pilaUno, PilaInt* pilaDos, PilaInt* pilaTres, int sumaPilaUno, int sumaPilaDos, int sumaPilaTres){
    while(!esVacia(pilaUno) || !esVacia(pilaDos) || !esVacia(pilaTres)){
        if(esVacia(pilaUno) || esVacia(pilaDos) || esVacia(pilaTres)){
            return 0;
        }
        if(sumaPilaUno == sumaPilaDos && sumaPilaDos == sumaPilaTres){
            return sumaPilaUno;
        }
        if(sumaPilaUno >= sumaPilaDos && sumaPilaUno >= sumaPilaTres){
            sumaPilaUno -= top(pilaUno);
            pop(pilaUno);
        }else if(sumaPilaDos >= sumaPilaUno && sumaPilaDos >= sumaPilaTres){
            sumaPilaDos -= top(pilaDos);
            pop(pilaDos);
        }else if(sumaPilaTres >= sumaPilaUno && sumaPilaTres >= sumaPilaDos){
            sumaPilaTres -= top(pilaTres);
            pop(pilaTres);
        }
    }
}

int main(){
    int proxAInsertar;

    // PILA 1
    int cantPilaUno;
    cin >> cantPilaUno;
    int sumaPilaUno = 0;
    PilaInt* pilaUno = crearPila();
    for (int i = 0; i < cantPilaUno; i++){
        cin >> proxAInsertar;
        sumaPilaUno = sumaPilaUno + proxAInsertar;
        push(pilaUno, proxAInsertar);
    }

    // PILA 2
    int cantPilaDos;
    cin >> cantPilaDos;
    int sumaPilaDos = 0;
    PilaInt* pilaDos = crearPila();
    for (int i = 0; i < cantPilaDos; i++){
        cin >> proxAInsertar;
        sumaPilaDos = sumaPilaDos + proxAInsertar;
        push(pilaDos, proxAInsertar);
    }

    // PILA 3
    int cantPilaTres;
    cin >> cantPilaTres;
    int sumaPilaTres = 0;
    PilaInt* pilaTres = crearPila();
    for (int i = 0; i < cantPilaTres; i++){
        cin >> proxAInsertar;
        sumaPilaTres = sumaPilaTres + proxAInsertar;
        push(pilaTres, proxAInsertar);
    }

    int resultado = maximaSumatoria(pilaUno, pilaDos, pilaTres, sumaPilaUno, sumaPilaDos, sumaPilaTres);
    cout << resultado << endl;

    destruir(pilaUno);
    destruir(pilaDos);
    destruir(pilaTres);

}