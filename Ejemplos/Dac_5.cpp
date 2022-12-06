#include <cassert>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

int cambio(int monedaHasta, int cambioRestante, int* valoresMonedas){
    // Caso base = problema sencillo 
    if (monedaHasta <0 && cambioRestante >0){
        return INT_MAX;
    }
    if(cambioRestante == 0){
        return 0;
    }

    int valorDeLaMoneda = valoresMonedas[monedaHasta];
    // No podemos usar la moneda
    if(cambioRestante < valorDeLaMoneda){
        return cambio(monedaHasta-1, cambioRestante, valoresMonedas);
    }

    // Si la podemos usar vemos que nos conviene

    // La cantidad de monedas que tengo que usar SI usara la moneda actual
    int cantidadUsandoLaMoneda = 1 + cambio(monedaHasta, cambioRestante - valorDeLaMoneda, valoresMonedas);
    // La cantidad de monedas que tengo que usar si NO usara la moneda actual.
    int cantidadNOUsandoLaMoneda = cambio(monedaHasta - 1, cambioRestante, valoresMonedas);

    return min(cantidadNOUsandoLaMoneda, cantidadUsandoLaMoneda);
}

int main(){
    int M; // La cantidad de tipos de monedas
    cin >> M;
    int* valoresMonedas = new int[M]();
    int aux;

    // Leemos los valores de las monedas
    for (int i = 0; i < M; i++){
        cin >> aux;
        valoresMonedas[i] = aux;
    }

    int C; // La cantidad de casos que tenemos.
    cin >> C;
    int vueltoADar;
    for(int i=0; i < C; i++){
        cin >> vueltoADar;
        // Proceso cada uno de los casos
        int cantidadDeMonedas = cambio(M - 1, vueltoADar, valoresMonedas);
        // No pude dar el cambio
        if (cantidadDeMonedas == INT_MAX){
            cout << "No hay solucion" << endl;
        } else {
            cout << cantidadDeMonedas << endl;
        }
        cout << cambio(M - 1, vueltoADar, valoresMonedas) << endl;
    }

}