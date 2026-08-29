/**
 * TEMA: Breadth First Search (BFS) & Distancia Mínima en Aristas no Ponderadas (Diapo 17)
 * COMPLEJIDAD: O(N + M)
 * 
 * PROBLEMAS RESOLUBLES CON ESTE CÓDIGO:
 * - CSES 1667: Message Route (Menor cantidad de computadoras/saltos e imprimir ruta)
 * - Codeforces 520B: Two Buttons (BFS sobre transiciones numéricas directas)
 * - Codeforces 242C: King's Path (BFS en tablero con casillas restringidas)
 * - Distancia mínima paso a paso desde un origen hacia todos los demás nodos.
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> grafo(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    int src = 1;
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : grafo[u]) {
            if (dist[v] == INF) { // Nodo aún no visitado
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    int dest = n;
    if (dist[dest] == INF) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> path;
        for (int cur = dest; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (int node : path) cout << node << " ";
        cout << "\n";
    }

    return 0;
}