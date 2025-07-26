#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<string, int> precios;
    string nombre;
    int precio;

    // Leer lista de precios
    for (int i = 0; i < K; ++i) {
        cin >> nombre >> precio;
        precios[nombre] = precio;
    }

    // Leer lista de compras y sumar el total
    int total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> nombre;
        total += precios[nombre];
    }

    cout << total << endl;
    return 0;
}