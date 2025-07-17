#include <iostream>
using namespace std;

// Función que determina si un número es par (0) o impar (1)
int esImpar(int m) {
    return m % 2; // Retorna 1 si es impar, 0 si es par
}

// Función que calcula la suma de números impares en el rango [a, b]
long long sumaImpares(int a, int b) {
    long long suma = 0;
    for (int i = a; i <= b; i++) {
        if (esImpar(i)) {
            suma += i;
        }
    }
    return suma;
}

int main() {
    int a, b;
    cin >> a >> b;
    
    long long resultado = sumaImpares(a, b);
    cout << resultado << endl;
    
    return 0;
}