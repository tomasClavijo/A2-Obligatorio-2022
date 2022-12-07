#include <cassert>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

int proximo(string caso, char aBuscar, int desde){
    int index = -1;
    for (int i = desde; i < caso.size(); i++){
        if(caso[i] == aBuscar){
            return i;
        }
    }
    return index;
}

int calcularCapturados(string caso, int K){
    int capturados = 0;
    int indexPolicia = proximo(caso, 'P', 0);
    int indexLadron = proximo(caso, 'L', 0);
    while(indexPolicia != -1 && indexLadron != -1){
        // 1) Caso 1: El policia puede capturar al ladron
        if(abs(indexPolicia-indexLadron) <= K){
            capturados++;
            indexPolicia = proximo(caso, 'P', indexPolicia + 1);
            indexLadron = proximo(caso, 'L', indexLadron + 1);
        } else { //2 No puede
            // Tengo que avanzar con el menor indice
            if (indexPolicia < indexLadron){
                indexPolicia = proximo(caso, 'P', indexPolicia + 1);
            } else {
                indexLadron = proximo(caso, 'L', indexLadron + 1);
            }
        }
        
    }
    return capturados;

}

int main(){
    string input;
    int K;
    cin >> input;
    cin >> K;
    int capturados = calcularCapturados(input, K);
    cout << "Cantidad de capturados " << capturados << endl;
    return 0;
}