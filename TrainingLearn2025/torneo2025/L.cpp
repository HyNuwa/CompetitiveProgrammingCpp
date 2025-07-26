#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;

    cin >> n;
    long long acumulador = 0;
    int menor = -1;
    for(int i=0; i<n - 1; i++){
        int numero;
        cin >> numero;
        acumulador += numero;
        if(i==0){
            menor = numero;
        }else if(menor > numero){
            menor = numero;
        }
    }
    long long sumatoria = ((menor+(menor+n-1))/2)*n;


    cout<< sumatoria - acumulador;
    return 0;
}