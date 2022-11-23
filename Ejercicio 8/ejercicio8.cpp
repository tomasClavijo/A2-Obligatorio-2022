#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

int ** initMatriz(int cantidad, int cota)
{
    int **m = new int* [cantidad + 1]();
    for (int i = 0; i <= cantidad; i++){
        m[i] = new int[cota+1]();
    }
    return m;
}