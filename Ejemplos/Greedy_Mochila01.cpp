#include <cassert>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

int pesos[] = {5, 3, 8, 4};
int valores[] = {10, 20, 25, 8};
int cantObjetos = 4;
float* ratios;

bool* initUsados(){
    bool* usados = new bool[cantObjetos]();
    for (int i = 0; i < cantObjetos; i++)
    {
        usados[i] = false;
    }
    return usados;
}

int mayorValor(int capacidad, bool * usados){
    int index = -1;
    // Asumimos de que todos los objetos tienen valor >= 0
    int maxValor = -1;
    for (int i = 0; i < cantObjetos; i++)
    {
        // Si:
        // 1) No use antes el objeto
        // 2) El objeto entra dentro de la capacidad restante
        // 3) Es el nuevo valor maximo dentro de los recorridos
        if(!usados[i] && pesos[i] <= capacidad && valores[i] >= maxValor){
            index = i;
            maxValor = valores[i];  
        }
    }
    return index;
}

int mochilav1(int capacidadRestante, bool* usados)
{
    int indiceAUsar = mayorValor(capacidadRestante, usados);
    // No tenemos mas objetos que pueden entrar en la mochila (o se terminaron)
    if(indiceAUsar == -1){
        return 0;
    } else{
        // Lo marco como usado
        usados[indiceAUsar] = true;
        int valorDelObjetoAUsar = valores[indiceAUsar];
        int pesoDelObjetoAUsar = pesos[indiceAUsar];
        return valorDelObjetoAUsar + mochilav1(capacidadRestante - pesoDelObjetoAUsar, usados);
    }
}

int menorPeso(int capacidad, bool* usados){
    int index = -1;
    // Asumimos que todos los objetos tiene valor >= 0
    int menorValor = INT_MAX;
    for(int i=0; i < cantObjetos; i++)
    {
        //Si:
        // 1) No use antes el objeto
        // 2) El objeto entra dentro de la capacidad restante
        // 3) Es el nuevo valor maximo dentro de los corridos
        if(!usados[i] && pesos[i] <= capacidad && pesos[i] < menorValor){
            index = i;
            menorValor = pesos[i];
        }
    }
    return index;
}

int mochilav2(int capacidadRestante, bool* usados){
    int indiceAUsar = menorPeso(capacidadRestante, usados);
    // No tenemos mas objetos que puedan entrar en la mochila (o se terminaron)
    if(indiceAUsar == -1){
        return 0;
    } else{
        // Lo marco como usado
        usados[indiceAUsar] = true;
        int valorDelObjetoAUsar = valores[indiceAUsar];
        int pesoDelObjetoAUsar = pesos[indiceAUsar];
        return valorDelObjetoAUsar + mochilav2(capacidadRestante - pesoDelObjetoAUsar, usados);
    }
}

int mejorRatio(int capacidad, bool * usados){
    int index = -1;
    // Asumimos de que todos los objetos tienen valor >= 0
    float maxValor = -1;
    for (int i = 0; i < cantObjetos; i++)
    {
        // Si:
        // 1) No use antes el objeto
        // 2) El objeto entra dentro de la capacidad restante
        // 3) Es el nuevo mejor ratio dentro de los recorridos
        if(!usados[i] && pesos[i] <= capacidad && ratios[i] >= maxValor){
            index = i;
            maxValor = ratios[i];  
        }
    }
    return index;
}

int mochilav3(int capacidadRestante, bool* usados){
    int indiceAUsar = mejorRatio(capacidadRestante, usados);
    // No tenemos mas objetos que puedan entrar en la mochila (o se terminaron)
    if(indiceAUsar == -1){
        return 0;
    } else{
        // Lo marco como usado
        usados[indiceAUsar] = true;
        int valorDelObjetoAUsar = valores[indiceAUsar];
        int pesoDelObjetoAUsar = pesos[indiceAUsar];
        return valorDelObjetoAUsar + mochilav2(capacidadRestante - pesoDelObjetoAUsar, usados);
    }
}

void imprimirUsados(bool* usados){
    for (int i = 0; i < cantObjetos; i++)
    {
        if(usados[i]){
            cout << "Use el objeto " << (i+1) << "con peso" << pesos[i] << "y valor" << valores[i] << endl;
        }
    }
    
}

int main(){

    int capacidad = 13;
    int valorMochila;
    bool* usados;


    // Mayor valor primero (v1)
    usados = initUsados();
    valorMochila = mochilav1(capacidad, usados);
    cout << "El valor de la mochila (mayor valor primero) " << valorMochila << endl;
    imprimirUsados(usados);

    // Menor peso primero (v2)
    usados = initUsados();
    valorMochila = mochilav2(capacidad, usados);
    cout << "El valor de la mochila (v2) " << valorMochila << endl;
    imprimirUsados(usados);

    // Mejor ratio (v3)
    usados = initUsados();
    ratios = new float[cantObjetos]();
    for (int i = 0; i < cantObjetos; i++){
        float valorObjeto = valores[i];
        float pesoObjeto = pesos[i];
        ratios[i] = valorObjeto / pesoObjeto;
        cout << ratios[i] << endl;
    }
    valorMochila = mochilav3(capacidad, usados);
    cout << "El valor de la mochila (v3) " << valorMochila << endl;
    imprimirUsados(usados);

    return 0;
}