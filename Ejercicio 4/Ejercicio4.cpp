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

            for (int i = 0; i < largoVec; i++){
                if(!visitado[i] && matAdy[origen][i]->existe)
                    DFS(i,visitado);
            }
        }

        //TODO: Hacer que sea TRIconexo y no solo conexo

        bool esConexo(){
            bool* visitado = new bool[largoVec];

            DFS(1, visitado);

            int cont = 0;
            for (int i = 0; i < largoVec; i++)
                if(visitado[i])
                    cont++;

            if(cont == cant){
                return true;
            }else{
                return false;
            }
        }

};

int main(){

    Grafo *g = new Grafo(5);

    g->insertarArista(0,1);
    g->insertarArista(1,3);
    g->insertarArista(3,2);

    if(g->esConexo()){
        cout << "1" << endl;
    }else{
        cout << "0" << endl;
    }

    g->insertarArista(3,4);

    if(g->esConexo()){
        cout << "1" << endl;
    }else{
        cout << "0" << endl;
    }

    delete g;
    return 0;
}