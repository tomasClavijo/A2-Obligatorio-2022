#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

bool esCreciente(int* arr, int inicio, int fin){
    if(inicio == fin){
        return true;
    }

    int mitad = (inicio + fin) / 2;

    bool esCrecienteIzq = esCreciente(arr, inicio, mitad);
    bool esCrecienteDer = esCreciente(arr, mitad+1, fin);

    return esCrecienteIzq && esCrecienteDer && arr[mitad] <= arr[mitad+1];
}

int main(){
    int N;
    cin >> N;
    int* arr = new int[N]();
    int aux;
    for (int i = 0; i < N; i++){
        cin >> aux;
        arr[i] = aux;
    }

    cout << (esCreciente(arr, 0, N-1) ? "True" : "False") << endl;
    return 0;
}