#include <iostream>
using namespace std;

class MFSet{
    int *parent, n;

    public:
    MFSet(int n){
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet(){
        for (int i = 0; i < n; i++){
            parent[i] = -1;
        }
    }

    int find(int x){
        if(parent[x] != -1){
            return find(parent[x]);
        }
        return x;
    }

    void merge(int x, int y){
        int xset = find(x);
        int yset = find(y);

        if(xset != yset){
            parent[yset] = xset;
        }
    }
};