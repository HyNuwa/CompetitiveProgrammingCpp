/**
 * TEMA: BFS sobre Grillas / Tableros Implícitos (Problema "Calles", Diapo 16)
 * COMPLEJIDAD: O(K) donde K es la cantidad de celdas válidas
 * 
 * PROBLEMAS RESOLUBLES CON ESTE CÓDIGO:
 * - Codeforces 242C: King's Path (Grilla de 10^9 x 10^9 con K celdas válidas)
 * - CSES 1193: Labyrinth (BFS en grilla de caracteres '#' y '.' con camino 'U,D,L,R')
 * - CSES 1194: Monsters (BFS multisource / simultáneo en grilla)
 */

#include <bits/stdc++.h>
using namespace std;

// 8 direcciones posibles (movimiento rey: lados y diagonales)
const int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r0, c0, r1, c1;
    if (!(cin >> r0 >> c0 >> r1 >> c1)) return 0;

    int n; // Cantidad de segmentos de casillas permitidas
    cin >> n;

    set<pair<int, int>> validas;
    for (int i = 0; i < n; ++i) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int c = a; c <= b; ++c) {
            validas.insert({r, c});
        }
    }

    // Mapa para distancias mínimas en coordenadas dispersas
    map<pair<int, int>, int> dist;
    queue<pair<int, int>> q;

    q.push({r0, c0});
    dist[{r0, c0}] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        int d = dist[{r, c}];
        if (r == r1 && c == c1) {
            cout << d << "\n";
            return 0;
        }

        for (int i = 0; i < 8; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            pair<int, int> next_pos = {nr, nc};

            // Solo avanzamos si es una casilla válida y no ha sido visitada
            if (validas.count(next_pos) && !dist.count(next_pos)) {
                dist[next_pos] = d + 1;
                q.push(next_pos);
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}