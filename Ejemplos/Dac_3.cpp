#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

int max(int a, int b, int c){
    if (a > b){
        return a > c ? a : c;
    }
    return b > c ? b : c;
}

int maxSecMedio(int *arr, int inicio, int fin, int mitad){
    int sumaParcial = arr[mitad];
    int max = arr[mitad];
    // Arranco en la mitad y voy hacia la izquierda (hasta el inicio del array)
    for (int i =mitad - 1; i >= inicio; i--){
        sumaParcial += arr[i];
        if (sumaParcial > max){
            max = sumaParcial;
        }
    }

    // Reseteo la suma parcial 
    sumaParcial = max;

    // Arranco en la mitad y voy hacia la derecha (hasta el final del array)
    for (int i = mitad + 1; i<= fin; i ++){
        sumaParcial += arr[i];
        if (sumaParcial > max){
            max = sumaParcial;
        }
    }

    return max;
}

int maxSec(int * arr, int i, int f){
    if (i == f){
        return arr[i];
    }

    int mitad = (f + i) / 2;

    int maxSecIzq = maxSec(arr, i, mitad);
    int maxSecDer = maxSec(arr, mitad + 1, f);

    int maxSecConMedio = maxSecMedio(arr, i, f, mitad);

    return max(maxSecIzq, maxSecDer, maxSecConMedio);
}

int main(){
    int arr[] = { -2, -5, 4, -2, -3, 1, -5, -6};
    cout << maxSec(arr, 0, 7) << endl;
    return 0;
}