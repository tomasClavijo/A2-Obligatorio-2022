#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

int min(int a, int b){
    return a > b ? b : a;
}

int minimo(int* arr, int i, int f){
    if(i == f){
        return arr[i];
    }

    int mitad = (f + 1) / 2;

    int minIzq = minimo(arr, i, mitad);
    int minDer = minimo(arr, mitad + 1, f);

    return min(minIzq, minDer);
}

int main(){
    int * test = new int[5];
    test[0] = 5;
    test[1] = 55;
    test[2] = 500;
    test[3] = 2;
    test[4] = 23;

    cout << minimo(test, 0, 4) << endl;
    return 0;
}