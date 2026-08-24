#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include<map>
#include<utility>
using namespace std;

int main() {
    int n ; cin >> n;
    map<string, int> pelis;   
    int nmax = 3;

    pair<string, int> maximos;
    maximos[0].first = "";
    maximos[0].second = 0;
    maximos[1].first = "";
    maximos[1].second = 0;
    maximos[2].first = "";
    maximos[2].second = 0;
    pair<string, int> min;
    min.first = ""; min.second = 100000000;

    for(int i = 0; i < n; i++){
        string nombre;
        int puntaje;
        cin >> nombre >> puntaje;

        if(pelis.find("nombre") != pelis.end()){
            pelis.insert({nombre, puntaje});

        }else{
            pelis[nombre] += puntaje;
        }
    }

    for (const auto& par : pelis) {
        for(int i = 0; i<3 ; i++){
            max
        }
        par.first
        
        cout << par.first << " -> " << par.second << '\n';
}
  
cout << min.first;
    return 0;
}