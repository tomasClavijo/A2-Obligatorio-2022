#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

int min(int a, int b){
    return a > b ? b : a;
}

string prefixStr(string s1, string s2){
    string resultado = "";
    int maxL = min(s1.size(), s2.size());
    for(int i = 0; i < maxL; i++)
    {
        if (s1[i] == s2[i]){
            resultado += s1[i];
        } else {
            break;
        }
    }  
    return resultado;
}

string prefix(string* arr, int i, int f){
    if (i == f){
        return arr[i];
    }

    int mitad = (f + i) / 2;

    string s1 = prefix(arr, i , mitad);
    string s2 = prefix(arr, mitad + 1, f);

    return prefixStr(s1, s2);
}

// Input: "ABC", "ABBB", "ABA", "AAN"
// Output: "AB"

int main(){
    string * arr = new string[4]();
    arr[0] = "ABC";
    arr[1] = "ABBB";
    arr[2] = "ABA";
    arr[3] = "EcNAB";
    cout << prefix(arr, 0, 3) << endl;
    return 0;
}