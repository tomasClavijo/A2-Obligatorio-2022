#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

// Intercambio dos caracteres de posicion
void intercambiar(string input, int pos1, int pos2){
    char aux = input[pos1];
    input[pos1] = input[pos2];
    input[pos2] = aux;
}

// Busca el indice del primer parentesis abierto desde una posicion dada
int buscarAbiertoDesde(string input, int hasta){
    int tam = input.size();
    for(int i = tam - 1; i >= hasta; i--){
        if(input[i] == '['){
            return i;
        }
    }
    // Deberiamos encontrar el parentesis antes de terminar el for
    assert(false);
}

int calcularIntercambios(string input){
    int tam = input.size();
    int balance = 0;
    int intercambios = 0;
    for(int i = 0; i < tam; i++){
        char actual = input[i];
        if(actual == '['){
            balance++;
        } else { // ]
            balance--;
        }
        // Existe parentesis cerrados sin abrir
        if (balance < 0){
            // Voy a buscar el proximo parentesis abierto
            int proxAbierto = buscarAbiertoDesde(input, i + 1);
            intercambiar(input, i, proxAbierto);
            intercambios++;
            balance = 1;
        }
    }
    // Chequeamos de que quedo balanceado
    assert(balance == 0);
    return intercambios;
}

int main(){
    string input;
    cin >> input;
    int cantIntercambios = calcularIntercambios(input);
    if(cantIntercambios == 0){
        cout << "No es necesario realizar intercambios";
    }else{
        cout << "Se tienen que realizar como minimo " << cantIntercambios << "intercambios" << endl;
    }
    return 0;
}