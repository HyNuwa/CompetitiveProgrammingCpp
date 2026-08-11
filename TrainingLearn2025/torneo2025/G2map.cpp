#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //double precision is used to avoid overflow in large calculations
    
    int n;
    cin >> n;
    
    map<string,int> mp;
    string nombre;
    int puntuacion;

    for (int i = 0; i < n; i++)
    {
        cin >> nombre;
        cin >> puntuacion;
        if(puntuacion == 1){
            mp.insert({nombre, 3});
        }else if(puntuacion==2){
            mp.insert({nombre, 1});
        }else{
            mp.insert({nombre, -1});
        }
        mp[nombre] = mp[nombre] + puntuacion;
    }

    // Mostrar los datos del pair
    map<string, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        if(mp.count())
    }
    
    return 0;
}