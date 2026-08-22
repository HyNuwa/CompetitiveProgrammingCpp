#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string patos;
    cin >> patos;

    int cantidadI = 0;
    int cantidadO = 0;

    for (char pato : patos) {
        if (pato == 'I') {
            cantidadI++;
        } else {
            cantidadO++;
        }
    }

    // Para que todos terminen en la posición de un pato
    // del tipo contrario, debe haber la misma cantidad.
    if (cantidadI != cantidadO) {
        cout << "NO\n";
        return 0;
    }

    vector<int> respuesta(N);
    vector<int> pila;

    for (int i = 0; i < N; i++) {
        if (!pila.empty() &&
            patos[pila.back()] != patos[i]) {

            int j = pila.back();
            pila.pop_back();

            // Los patos i y j intercambian sus posiciones.
            respuesta[i] = j + 1;
            respuesta[j] = i + 1;
        } else {
            pila.push_back(i);
        }
    }

    // Si hay la misma cantidad de I y O,
    // la pila debe terminar vacía.
    if (!pila.empty()) {
        cout << "NO\n";
        return 0;
    }

    cout << "SI\n";

    for (int posicion : respuesta) {
        cout << posicion << ' ';
    }

    cout << '\n';

    return 0;
}