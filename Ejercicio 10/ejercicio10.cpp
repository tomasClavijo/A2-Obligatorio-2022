#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

string concatenarIntInt(int a, int b){
    string s1 = to_string(a);
    string s2 = to_string(b);
 
    string s = s1 + s2;

    return s;
}

string concatenarStringInt(string a, int b){
    string s2 = to_string(b);
 
    string s = a + s2;

    return s;
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (concatenarIntInt(arr[j], arr[j + 1]).compare(concatenarIntInt(arr[j + 1], arr[j])) < 0)
                swap(&arr[j], &arr[j + 1]);
}

int main(){
    int cantE;
    cin >> cantE;

    int* arr = new int[cantE];

    for (int i = 0; i < cantE; i++){
        int n;
        cin >> n;
        arr[i] = n;
    }

    sort(arr, cantE);
   
    string sol = to_string(arr[0]);

    for (int i = 1; i < cantE; i++)
    {
        sol = concatenarStringInt(sol, arr[i]);
    }
    
    cout << sol << endl;
    
    delete[] arr;

    return 0;
}