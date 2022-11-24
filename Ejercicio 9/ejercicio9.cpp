#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#define INF 99999
using namespace std;

void subconjuntoBacktracking(int* elementos, int cantElementos, int posActual, int prueba, int sumatoria, int solucionActual, int& solucionOptima){
    if (posActual == cantElementos){
        if (sumatoria > prueba){
            return;
        } else if (sumatoria == prueba && solucionActual < solucionOptima){
            solucionOptima = solucionActual;
        }
    } else {
        if (elementos[posActual] <= prueba - sumatoria){
            subconjuntoBacktracking(elementos, cantElementos, posActual, prueba, sumatoria+elementos[posActual], solucionActual+1, solucionOptima);
        } 
        if(posActual + 1 == cantElementos){
            if(sumatoria == prueba && solucionActual < solucionOptima){
                solucionOptima = solucionActual;
            }
        } else {
            subconjuntoBacktracking(elementos, cantElementos, posActual + 1, prueba, sumatoria, solucionActual, solucionOptima);
        }
    }
}

int main(){
    int cantElementos;
    cin >> cantElementos;
    int *elementos = new int [cantElementos];
    for(int i = 0; i < cantElementos; i++){
        int elemento;
        cin >> elemento;
        elementos[i] = elemento;
    }

    int cantPruebas;
    cin >> cantPruebas;
    int *pruebas = new int [cantPruebas];
    for(int i = 0; i < cantPruebas; i++){
        int elemento;
        cin >> elemento;
        pruebas[i] = elemento;
    }

    int solucionOptima = INF;
    int solucionActual = 0;
    int posActual = 0;
    int sumatoria = 0;

    for(int i = 0; i < cantPruebas; i++){
        solucionOptima = INF;
        subconjuntoBacktracking(elementos, cantElementos, posActual, pruebas[i], sumatoria, solucionActual, solucionOptima);
        if (solucionOptima == INF){
            cout << "0" << endl;
        } else {
            cout << solucionOptima << endl;
        }
    }
}