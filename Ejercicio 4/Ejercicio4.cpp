#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

class Grafo{
    private:
        struct Arista{bool existe; int peso;Arista():existe(false){}};

        Arista*** matAdy;
        int largoVec;
        int cant;

    public:
        Grafo(int cantVertices){
            cant = cantVertices;
            largoVec = cantVertices+1;
            matAdy = new Arista**[largoVec];
            for(int i = 0; i < largoVec; i++){
                matAdy[i] = new Arista*[largoVec];
                for(int j = 0; j < largoVec; j++)
                    matAdy[i][j] = new Arista();
            }
        }

    	~Grafo(){
           for (int i = 0; i < largoVec; i++){
                for (int j = 0; j < largoVec; j++)
                    delete matAdy[i][j];
                delete []matAdy[i];
            }
            delete []matAdy;
        }

        void insertarArista(int o, int d){
            matAdy[o][d]->existe = true;
            matAdy[o][d]->peso = 0;
            //Por letra es no dirigido, entonces agregamos ambas aristas
            matAdy[d][o]->existe = true;
            matAdy[d][o]->peso = 0;
        }

        void DFS(int origen, bool* visitado){
            visitado[origen] = true;

            for (int i = 1; i < largoVec; i++){
                if(!visitado[i] && matAdy[origen][i]->existe)
                    DFS(i,visitado);
            }
        }

        //TODO: Hacer que sea TRIconexo y no solo conexo

        bool esTriconexo(int ignorar1, int ignorar2){
            bool* visitado = new bool[largoVec];

            visitado[ignorar1] = true;
            visitado[ignorar2] = true;

            DFS(1, visitado);

            int cont = 0;
            for (int i = 1; i < largoVec; i++)
                if(visitado[i])
                    cont++;

            return cont == cant;
        }

};

int main(){
    int cantV;
    cin >> cantV;

    Grafo *g = new Grafo(cantV);

    int cantA;
    cin >> cantA;

    for(int i = 0; i < cantA; i++){
        int v1;
        cin >> v1;

        int v2;
        cin >> v2;

        g->insertarArista(v1,v2);
    }

    for(int i = 1; i < cantV+1; i++)
        for(int j = 1; j < cantV+1; j++)
            if(!g->esTriconexo(i,j)){
                cout << 0 << endl;
                delete g;
                return 0;
            }

    cout << 1 << endl;

    delete g;
    return 0;
}