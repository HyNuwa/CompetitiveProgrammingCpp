#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //double precision is used to avoid overflow in large calculations
    
    int n, q;
    cin >> n >> q;
    
    vector<int> precios(n);
    for(int i=0; i<n; i++){
        cin >> precios[i];
    }

    int sumatoria = 0;
    for(int i=0; i < q; i++){
        int T, V, C;
        cin >> T >> V >> C;
        if(T == 1){
            sumatoria += C*precios[V-1];
        }else{
            precios[V-1] = C;
        }
    }

    cout << sumatoria;
    return 0;
}