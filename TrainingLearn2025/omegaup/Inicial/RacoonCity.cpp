#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://omegaup.com/course/TallerNivel_Intermedio_2025/assignment/TP3-Repetitivas#problems/Claire-y-el-Arsenal
int main() {
    int N;
    cin >> N;
    
    vector<int> armas(N);
    for (int i = 0; i < N; i++) {
        cin >> armas[i];
    }
    
    // Encontrar el arma más poderosa (valor máximo)
    int arma_mas_poderosa = *max_element(armas.begin(), armas.end());
    
    // Encontrar el índice del arma más poderosa
    int indice = 0;
    for (int i = 0; i < N; i++) {
        if (armas[i] == arma_mas_poderosa) {
            indice = i + 1; // +1 porque las armas están numeradas desde 1
            break;
        }
    }
    
    cout << arma_mas_poderosa << " " << indice << endl;
    
    return 0;
}