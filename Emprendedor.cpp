#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int N; int Q;
    if(!(cin >> N >> Q)) return 0;
    vector<ll> precio(N);


    
    short accion;
    int cantidad;
    int precio_cambiado;
    int tipo;
    int acumulador = 0;

    for(int i=0;i<N;i++) cin >> precio[i];
            
    for(int i=0;i<Q;i++) {
        cin >> accion;
        if (accion ==1){
            
            cin >> tipo;
            cin >> cantidad; 

            acumulador += precio[tipo-1] * cantidad;
            
        }else if(accion==2){
            cin >> tipo;
            cin >> precio_cambiado;
            precio[tipo-1] = precio_cambiado;
        }
    
    }

    cout << acumulador << endl;
    return 0;
}