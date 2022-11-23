#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

struct Nodo{
    int dato;
    Nodo * sig;
};

class Pila{
    private:
        Nodo* contenido;
        int numeroDeElementos;
    public:
        Pila(){
            numeroDeElementos = 0;
            contenido = NULL;
        }
        void push(int elemento){
            Nodo * nodo = new Nodo();
            nodo->dato = elemento;
            nodo->sig = contenido;
            contenido = nodo;
            numeroDeElementos++;
        }
        int top(){
            return contenido->dato;
        }
        void pop(){
            Nodo* aBorrar = new Nodo();
            aBorrar = contenido;
            contenido = contenido->sig;
            delete aBorrar;
            numeroDeElementos--;
        }
        bool esVacia(){
            return numeroDeElementos == 0;
        }
};

int mayor (int a, int b, int c){
    if (a >= b && a >= c){
        return a;
    } else if (b >= a && b >= c){
        return b;
    } else {
        return c;
    }
}

int maximaSumatoria(Pila* pilaUno, Pila* pilaDos, Pila* pilaTres, int sumaPilaUno, int sumaPilaDos, int sumaPilaTres){
    // Iterativo se tranca al momento de utilizar el ejecutable.
    while (!(sumaPilaUno == sumaPilaDos && sumaPilaDos == sumaPilaTres)){
        int mayorSumatoria = mayor(sumaPilaUno, sumaPilaDos, sumaPilaTres);
        if (mayorSumatoria == sumaPilaUno && !pilaUno->esVacia()){
            int elemento = pilaUno->top();
            pilaUno->pop();
            sumaPilaUno = sumaPilaUno - elemento;
        } else if (mayorSumatoria == sumaPilaDos && !pilaDos->esVacia()){
            int elemento = pilaDos->top();
            pilaDos->pop();
            sumaPilaDos = sumaPilaDos - elemento;
        } else if (mayorSumatoria == sumaPilaTres && !pilaTres->esVacia()){
            int elemento = pilaTres->top();
            pilaTres->pop();
            sumaPilaTres = sumaPilaTres - elemento;
        }
    }
    return sumaPilaUno;

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
};

int main(){
    int proxAInsertar;

    // PILA 1
    int cantPilaUno;
    cin >> cantPilaUno;
    int sumaPilaUno = 0;
    // Inserto todos los numeros en un vector
    int* arrUno = new int[cantPilaUno];
    for (int i = 0; i < cantPilaUno; i++){
        cin >> proxAInsertar;
        sumaPilaUno += proxAInsertar;
        arrUno[i] = proxAInsertar;
    }
    // Creo la Pila 1
    Pila* pilaUno = new Pila();
    // Inserto los elementos en la pila
    for (int i = cantPilaUno - 1; i <= 0; i--){
        pilaUno->push(arrUno[i]);
    }

    // PILA 2
    int cantPilaDos;
    cin >> cantPilaDos;
    int sumaPilaDos = 0;
    // Inserto todos los numeros en un vector
    int* arrDos = new int[cantPilaDos];
    for (int i = 0; i < cantPilaDos; i++){
        cin >> proxAInsertar;
        sumaPilaDos += proxAInsertar;
        arrDos[i] = proxAInsertar;
    }
    // Creo la Pila 2
    Pila* pilaDos = new Pila();
    // Inserto los elementos en la pila
    for (int i = cantPilaDos - 1; i <= 0; i--){
        pilaDos->push(arrDos[i]);
    }

    // PILA 3
    int cantPilaTres;
    cin >> cantPilaTres;
    int sumaPilaTres = 0;
    // Inserto todos los numeros en un vector
    int* arrTres = new int[cantPilaTres];
    for (int i = 0; i < cantPilaTres; i++){
        cin >> proxAInsertar;
        sumaPilaTres += proxAInsertar;
        arrTres[i] = proxAInsertar;
    }
    // Creo la Pila 3
    Pila* pilaTres = new Pila();
    // Inserto los elementos en la pila
    for (int i = cantPilaTres - 1; i <= 0; i--){
        pilaTres->push(arrTres[i]);
    }

    int resultado = maximaSumatoria(pilaUno, pilaDos, pilaTres, sumaPilaUno, sumaPilaDos, sumaPilaTres);
    cout << resultado << endl;

}