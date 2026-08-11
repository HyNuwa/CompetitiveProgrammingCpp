#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //double precision is used to avoid overflow in large calculations
    
    int n;
    cin >> n;
    
    vector<pair<string,int>> peliculas;
    for(int i = 0; i < n; i++)
    {
        cin >> peliculas[i].first;
        int p;
        cin >> p;
        if(p == 1){
            peliculas[i].second = 3;
        }else if(p==2){
            peliculas[i].second = 1;
        }else{
            peliculas[i].second = -1;
        }
    }

    for (int i = 0; i<n; i++){
        if(peliculas_sin_repetir.){

        }
    }

    
    return 0;
}