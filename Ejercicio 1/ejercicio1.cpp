#include "iostream"
#include <math.h>
using namespace std;

class NodoHash{
    public:
        string dato;
        bool hayDato;
        bool huboDato;
        NodoHash(){}
        NodoHash(string dato, bool hayDato, bool huboDato) : dato(dato), hayDato(hayDato), huboDato(huboDato) {}
};

class Hash {

    private:

        NodoHash* vec;
        int cantElementos; 
        int largo; // Largo del vector

        bool esPrimo(int num){ 

            if (num < 2){
                return false;
            } else {
                for (int i = 2; i < num/2; i++){
                    if (num % i == 0){
                        return false;
                    }
                }
                return true;
            }
        }

        int primoSup(int num){ 

            while (!esPrimo(++num));
            return num;
        }

        int funcionHash(string s){ 
            int total = 0;
            for (int i = 0; i < 5 ; i++){ // Fijarnos si el 5 es adecuado. 
                total = (total + int(s[i]) * (int)pow(37, i)) % largo;
            }
            return total;
        }

    public:

        Hash(int esperados){
            this->largo = primoSup(esperados);
            this->vec = new NodoHash[largo]; 
            this->cantElementos = 0;
            for(int i = 0; i < largo; i++){
                vec[i].dato = "";
                vec[i].hayDato = false;
                vec[i].huboDato = false;
            }

        }

        ~Hash(){
                delete[] this ->vec;
        }

        void insertar (string s){
            int posicion = funcionHash(s);
            if (vec[posicion].hayDato == false){
                vec[posicion].dato = s;
                vec[posicion].hayDato = true;
                vec[posicion].huboDato = true;
                cantElementos++;
            } else {
                while (posicion < largo && vec[posicion].hayDato == true){
                    if (s == vec[posicion].dato){
                        return;
                    }
                    posicion++;
                }
                if (posicion == largo){
                    posicion = 0;
                    while (posicion < funcionHash(s) && vec[posicion].hayDato == true){
                        if (s == vec[posicion].dato){
                            return;
                        }
                        posicion++;

                    }
                    vec[posicion].dato = s;
                    vec[posicion].hayDato = true;
                    cantElementos++;
                } else {
                    vec[posicion].dato = s;
                    vec[posicion].hayDato = true;
                    cantElementos++;
                }
            }

        }

        int cantidadElementos (){
            return cantElementos;
        }

};

int main () {

    int cantLineas; // Variable que tendrá cuantas líneas se esperan.
    cin >> cantLineas;
    string s; // Variable para cada correo.
    Hash *h = new Hash(cantLineas);
    for (int i = 0; i < cantLineas; i++){
        cin >> s;
        h->insertar(s);
    }
    int cantidadElementos = h->cantidadElementos();
    delete h;
    cout << cantidadElementos << endl;
}