#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> histograma(n);
    
    // Leer el histograma
    for (int i = 0; i < n; i++) {
        cin >> histograma[i];
    }
    
    // Contar la altura de cada columna (cuántos '1' hay en cada columna)
    vector<int> alturas;
    for (int j = 0; j < m; j++) {
        int altura = 0;
        for (int i = 0; i < n; i++) {
            if (histograma[i][j] == '1') {
                altura++;
            }
        }
        alturas.push_back(altura);
    }
    
    // Mostrar resultado
    for (int i = 0; i < alturas.size(); i++) {
        cout << alturas[i];
        if (i < alturas.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}