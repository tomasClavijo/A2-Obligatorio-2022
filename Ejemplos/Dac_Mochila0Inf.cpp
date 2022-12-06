#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

// A, B, C, D , E
int valores[] = {4, 2, 10, 1, 2};
int pesos[] = {12, 1, 4, 1, 2};

int max(int a, int b){
    return a > b ? a : b;
}

int mochila0INF(int objetoHasta, int capacidadRestante){
	// Problema trivial
	// Si me quedé sin capacidad o sin objetos para elegir
	if(capacidadRestante == 0 || objetoHasta < 0){
		return 0;
	}

    int valorDelObjeto = valores[objetoHasta];
    int pesoDelObjeto = pesos[objetoHasta];

    // No puedo poner el objeto
    if (pesoDelObjeto > capacidadRestante){
        //Ignoro el objeto
        return mochila0INF(objetoHasta-1, capacidadRestante);
    }

    // Puedo poner el objeto
    // Calculo el valor de la mochila si pusiera el objeto en consideracion
    int valorDePoner = valorDelObjeto + mochila0INF(objetoHasta, capacidadRestante - pesoDelObjeto);
    // Calculo el valor de la mochila si ignoro el objeto
    int valorDeNoPoner = mochila0INF(objetoHasta - 1, capacidadRestante) ;

    return max(valorDePoner, valorDeNoPoner);
}

int main(){
	int capacidadMochila = 15;
    cout << mochila0INF(4, capacidadMochila) << endl;
	return 0;
}