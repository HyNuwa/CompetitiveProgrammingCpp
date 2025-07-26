#include <iostream> 

using namespace std;
int main() { 
    // Aquí va tu código
    int w;
    cin >> w;

    if (w <= 2 || w % 2 != 0) {
        cout << "NO" << endl; // No se puede dividir en dos partes iguales
    } else {
        cout << "YES" << endl; // Se puede dividir en dos partes iguales
    }
    return 0; 
}