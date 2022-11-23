#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

int problemaDelCambioImp(int cambioRestante, int monedas[], int cantMonedas){
    int cantidad = 0;
    int monedaMayorValorIndex = cantMonedas - 1;
    // Mientras tenga cambio para dar y aun tenga tipos de monedas disponibles..
    while(cambioRestante && monedaMayorValorIndex >= 0){
        int valorMoneda = monedas[monedaMayorValorIndex];
        // Si puedo dar la mayor moneda.
        if(cambioRestante >= valorMoneda){
            cout << "Di una moneda de" << valorMoneda << endl;
            cantidad++;
            cambioRestante-=valorMoneda;
        }else{
            monedaMayorValorIndex --;
        }

    }
    // Chequear que haya dado todo el cambio
    assert(cambioRestante == 0);
    return cantidad;
};

// Pre: Monedas estan ordenadas por valor (creciente)
int problemaDelCambioRec(int cambioRestante, int monedas[], int cantMonedas){
    assert(cantMonedas > 0); // En caso de quedarnos sin monedas entonces, damos un error.
    if(cambioRestante == 0){
        return 0;
    } else{
        // Puedo usar la moneda de mayor valor
        if(monedas[cantMonedas-1] <= cambioRestante){
            cout << "Di una moneda de " << monedas[cantMonedas - 1] << endl;
            return 1 + problemaDelCambioRec(cambioRestante - monedas[cantMonedas-1], monedas, cantMonedas);
        } else{ 
            return problemaDelCambioRec(cambioRestante, monedas, cantMonedas - 1);
        }
    }
}

int main(){
    int cambio;
    cin >> cambio;
    int monedas[] = {1, 2, 5, 10, 50};
    cout << "Recu" << endl;
    int cantidadDeMonedasUsadas = problemaDelCambioRec(cambio, monedas, 5);
    cout << cantidadDeMonedasUsadas << endl;
    return 0;
}