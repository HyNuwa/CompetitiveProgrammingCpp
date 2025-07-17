#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arreglo(n);
    
    // Leer el arreglo
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }
    
    // Sumar elementos opuestos
    vector<int> resultado;
    for (int i = 0; i < n / 2; i++) {
        int suma = arreglo[i] + arreglo[n - 1 - i];
        resultado.push_back(suma);
    }
    
    // Mostrar resultado
    for (int i = 0; i < resultado.size(); i++) {
        cout << resultado[i];
        if (i < resultado.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}