#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#define INF 888888
using namespace std;

void subconjuntoBacktracking(int* elementos, int cantidadElementos, int posActual, int prueba, int sumatoria, int solucionActual, int& solucionOptima){
    if (posActual == cantidadElementos){
        if (sumatoria > prueba){
            return;
        } else if (sumatoria == prueba && solucionActual < solucionOptima){
            solucionOptima = solucionActual;
        }
    } else {
        if (elementos[posActual] <= prueba - sumatoria){
            subconjuntoBacktracking(elementos, cantidadElementos, posActual, prueba, sumatoria+elementos[posActual], solucionActual+1, solucionOptima);
        } 
        if(posActual + 1 == cantidadElementos){
            if(sumatoria == prueba && solucionActual < solucionOptima){
                solucionOptima = solucionActual;
            }
        } else {
            subconjuntoBacktracking(elementos, cantidadElementos, posActual + 1, prueba, sumatoria, solucionActual, solucionOptima);
        }
    }
}

int main(){
    int cantidadElementos;
    cin >> cantidadElementos;
    int *elementos = new int [cantidadElementos];
    int elemento;
    for(int i = 0; i < cantidadElementos; i++){
        cin >> elemento;
        elementos[i] = elemento;
    }

    int cantPruebas;
    cin >> cantPruebas;
    int *pruebas = new int [cantPruebas];
    for(int i = 0; i < cantPruebas; i++){
        cin >> elemento;
        pruebas[i] = elemento;
    }

    int solucionOptima = INF;
    int solucionActual = 0;
    int posActual = 0;
    int sumatoria = 0;

    for(int i = 0; i < cantPruebas; i++){
        solucionOptima = INF;
        subconjuntoBacktracking(elementos, cantidadElementos, posActual, pruebas[i], sumatoria, solucionActual, solucionOptima);
        if (solucionOptima == INF){
            cout << "0" << endl;
        } else {
            cout << solucionOptima << endl;
        }
    }

    delete [] elementos;
    delete [] pruebas;
}