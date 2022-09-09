#include <iostream>

using namespace std;



class Heap{

    public:

        Heap(int cantAproxElem){
            vec = new int[cantAproxElem];
            for (int i = 0; i < cantAproxElem; i++){
                vec[i] = 0;
            }
            cantElem = 0;
        }

        ~Heap(){
            delete[] vec;
        }

        void push(int e){
            int pos = cantElem+1;
            vec[pos] = e;
            while(padre(vec[pos]) > e){
                flotar(vec[pos]);
                pos = padre(vec[pos]);
            }
            cantElem ++;
        }

        int pop(){
            
        }

        int top(){
            return vec[0];
        }

        bool estaVacio(){
            return vec[0] == 0;
        }



    private:

        int* vec;
        
        int cantElem;
        
        int hijoIzq(int n){
            return 2*n+1;
        }

        int hijoDer(int n){
            return 2*n+2;
        }

        int padre(int n){
            return (n-1)/2;
        }

        void flotar(int n){

        }

        void hundir(int n){

        }

        void swap(int a, int b){
            
        }

};



int main(){

    Heap *myHeap = new Heap(50);

    for (int i = 0; i < 10; myHeap->push(i++));

    myHeap->push(-1);

    myHeap->push(-20);

    myHeap->push(-40);



    while(!myHeap->estaVacio()){

        cout << myHeap->pop() << endl;

    }



    delete myHeap;

    return 0;

}