#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //double precision is used to avoid overflow in large calculations
    
    int n; long m;
    vector<int> ingredientes(n);
    vector<int> tiempos(n);
    vector<long> habitaciones(m, 0);
    for(int i=0; i<n; i++){
        cin >> ingredientes[i];
    }
    int mayor = 0;
    for(int i=0; i<n; i++){
        cin >> tiempos[i];
        habitaciones[ingredientes[i] - 1] += tiempos[i];
        if(mayor < habitaciones[ingredientes[i]-1]){
            mayor = habitaciones[ingredientes[i]-1];
        }
    }

    cout << mayor;

    return 0;
}