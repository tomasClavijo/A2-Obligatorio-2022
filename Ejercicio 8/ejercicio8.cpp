#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

bool ** initMatriz(int cantidad, int cota)
{
    int **m = new int* [cantidad + 1]();
    for (int i = 0; i <= cantidad; i++){
        m[i] = new int[cota+1]();
    }
    return m;
};

bool ** resolucion(int cantidad, int cota, int* objetos, int* pruebas)
{
    bool** tab = initMatriz(cantidad, cota);
    for (int i = 0; i <= cantidad; i++){
        tab[i][0] = false;
    }
    for(int j = 1; j <= cota; j++){
        if(j % objetos[0] == 0){
            tab[0][j] = true;
        }else{
            tab[0][j] = false;
        }
    }
    for(int i = 1; i<= cantidad; i++){
        for (int j = 1; j <= cota; j++){
            if (j < objetos[i]){
                tab[i][j] = tab[i-1][j];
            } else if (j == objetos[i]){
                tab[i][j] = true;
            } else
            {
                tab[i][j] = tab[i-1][j] || tab[i][j-objetos[i]];
            }
        }
    }
}

int main()
{
    // Cargo todos los objetos del conjunto
    int N;
    cin >> N;
    int* objetos = new int [N + 1];
    objetos[0] = 0;
    int elemento;
    for (int i = 1; i < N + 1; i++){
        cin >> elemento;
        objetos[i] = elemento;
    }

    // Cargo la cota
    int cota;
    cin >> cota;

    // Cargo las pruebas
    int P;
    cin >> P;
    int* pruebas = new int [P + 1];
    pruebas[0] = 0;
    int prueba;
    for (int i = 1; i < P + 1; i ++){
        cin >> prueba;
        pruebas[i] = prueba;
    }

    bool 

    return 0;
}