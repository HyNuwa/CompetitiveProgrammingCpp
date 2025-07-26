#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int fil, col;
    int valor;
    cin >> fil >> col;    
    
    // Contar la altura de cada columna (cuántos '1' hay en cada columna)
    vector<int> alturas(col);
    for (int i = 0; i < fil; i++) {

        for (int j = 0; j < col; j++) {
            cin >> valor;
            if (valor == 1) {
                alturas[j]+=1;
            }
        }
    }
    
    // Mostrar resultado
    for (int i = 0; i < col; i++) {
        cout << alturas[i] << " ";
    }
    
    return 0;
}