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
     int suma;
};
       
PilaInt* crearPila(){
    PilaInt* pila = new PilaInt;
    pila->numeroDeElementos = 0;
    pila->contenido = NULL;
    pila->fin = NULL;
    pila->suma = 0;
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
    pila->suma += elemento;
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
/*
int mayor (int a, int b, int c){
    if (a >= b && a >= c){
        return a;
    } else if (b >= a && b >= c){
        return b;
    } else {
        return c;
    }
}
*/
int darSuma(PilaInt* p){
    return p->suma;
}

int maximaSumatoria(PilaInt*& pila1, PilaInt*& pila2, PilaInt*& pila3){
    int sumaPila1 = darSuma(pila1);
    int sumaPila2 = darSuma(pila2);
    int sumaPila3 = darSuma(pila3);

    //Mientras que las pilas tengan algo
    while(!esVacia(pila1) || !esVacia(pila2) || !esVacia(pila3)){

        //Si alguna pila se queda sin elementos, no tienen una valor en común
        if(esVacia(pila1) || esVacia(pila2) || esVacia(pila3)){
            return 0;
        }
        if(sumaPila1 == sumaPila2 && sumaPila2 == sumaPila3){
            return sumaPila1;
        }

        if(sumaPila1 >= sumaPila2 && sumaPila1 >= sumaPila3){
            sumaPila1 -= top(pila1);
            pop(pila1);
        }else if(sumaPila2 >= sumaPila1 && sumaPila2 >= sumaPila3){
            sumaPila2 -= top(pila2);
            pop(pila2);
        }else if(sumaPila3 >= sumaPila1 && sumaPila3 >= sumaPila2){
            sumaPila3 -= top(pila3);
            pop(pila3);
        }
    }
    return 0;
}



/*
int maximaSumatoria(PilaInt* pilaUno, PilaInt* pilaDos, PilaInt* pilaTres, int sumaPilaUno, int sumaPilaDos, int sumaPilaTres){
    // Iterativo se tranca al momento de utilizar el ejecutable.
    while (!esVacia(pilaUno) || !esVacia(pilaDos) || !esVacia(pilaTres))
    {
        if (esVacia(pilaUno) || esVacia(pilaDos) || esVacia(pilaTres)){
            return 0;
        }
        if (sumaPilaUno == sumaPilaDos && sumaPilaDos == sumaPilaTres){
            return sumaPilaUno;
        }
        int mayorSumatoria = mayor(sumaPilaUno, sumaPilaDos, sumaPilaTres);
        if (mayorSumatoria == sumaPilaUno){
            int elemento = top(pilaUno);
            pop(pilaUno);
            sumaPilaUno = sumaPilaUno - elemento;
        } else if (mayorSumatoria == sumaPilaDos){
            int elemento = top(pilaDos);
            pop(pilaDos);
            sumaPilaDos = sumaPilaDos - elemento;
        } else if (mayorSumatoria == sumaPilaTres){
            int elemento = top(pilaTres);
            pop(pilaTres);
            sumaPilaTres = sumaPilaTres - elemento;
        }
    }
    */

    // Recursivo devuelve siempre 0
    /*
    if (sumaPilaUno == sumaPilaDos == sumaPilaTres){
        return sumaPilaUno;
    } else {
        int mayorSumatoria = mayor(sumaPilaUno, sumaPilaDos, sumaPilaTres);
        if (mayorSumatoria == sumaPilaUno && !pilaUno->esVacia()){
            int elemento = pilaUno->top();
            pilaUno->pop();
            sumaPilaUno = sumaPilaUno - elemento;
            maximaSumatoria(pilaUno, pilaDos, pilaTres, sumaPilaUno, sumaPilaDos, sumaPilaTres);
        } else if (mayorSumatoria == sumaPilaDos && !pilaDos->esVacia()){
            int elemento = pilaDos->top();
            pilaDos->pop();
            sumaPilaDos = sumaPilaDos - elemento;
            maximaSumatoria(pilaUno, pilaDos, pilaTres, sumaPilaUno, sumaPilaDos, sumaPilaTres);
        } else if (mayorSumatoria == sumaPilaTres && !pilaTres->esVacia()){
            int elemento = pilaTres->top();
            pilaTres->pop();
            sumaPilaTres = sumaPilaTres - elemento;
            maximaSumatoria(pilaUno, pilaDos, pilaTres, sumaPilaUno, sumaPilaDos, sumaPilaTres);
        }
    }
    */

int main(){
    int proxAInsertar;

    // PILA 1
    int cantPilaUno;
    cin >> cantPilaUno;

    PilaInt* pilaUno = crearPila();
    for (int i = 0; i < cantPilaUno; i++){
        cin >> proxAInsertar;
        push(pilaUno, proxAInsertar);
    }

    // PILA 2
    int cantPilaDos;
    cin >> cantPilaDos;
    PilaInt* pilaDos = crearPila();
    for (int i = 0; i < cantPilaDos; i++){
        cin >> proxAInsertar;
        push(pilaDos, proxAInsertar);
    }

    // PILA 3
    int cantPilaTres;
    cin >> cantPilaTres;
    PilaInt* pilaTres = crearPila();
    for (int i = 0; i < cantPilaTres; i++){
        cin >> proxAInsertar;
        push(pilaTres, proxAInsertar);
    }

    int resultado = maximaSumatoria(pilaUno, pilaDos, pilaTres);
    cout << resultado << endl;

}