#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> arreglo(N);
    for (int i = 0; i < N; i++) {
        cin >> arreglo[i];
    }
    
    int P;
    cin >> P;
    
    bool primero = true;
    
    for (int i = 0; i < N; i++) {
        bool esPar = (arreglo[i] % 2 == 0);
        
        // Si P = 0, imprimir pares; si P = 1, imprimir impares
        if ((P == 0 && esPar) || (P == 1 && !esPar)) {
            if (!primero) {
                cout << " ";
            }
            cout << arreglo[i];
            primero = false;
        }
    }
    
    cout << endl;
    
    return 0;
}