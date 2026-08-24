#include <iostream>

using namespace std;

int main() {
    // Variables para almacenar la cantidad de zombies
    int n, m;
    
    // Leer los datos de entrada
    if (cin >> n >> m) {
        // Calcular el total de balas
        int total_balas = (n * 1) + (m * 3);
        
        // Imprimir el resultado
        cout << total_balas << "\n";
    }
    
    return 0;
}