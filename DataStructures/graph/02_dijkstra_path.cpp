/**
 * TEMA: Caminos mínimos con pesos no negativos + Reconstrucción de camino (Diapos 22-24)
 * COMPLEJIDAD: O(M log N)
 * 
 * PROBLEMAS RESOLUBLES CON ESTE CÓDIGO:
 * - CSES 1671: Shortest Routes I (Dijkstra estándar de 1 a todos)
 * - CSES 1195: Flight Discount (Dijkstra con grafo de capas / estado extra)
 * - Codeforces 20C: Dijkstra? (Hallar e imprimir el camino exacto 1 -> N)
 * - CSES 1667: Message Route (Si se asume peso 1 en todas las aristas)
 */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // Si no es dirigido, descomentar:
        // adj[v].push_back({u, w});
    }

    int src = 1;
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Ejemplo: Imprimir camino hacia el destino N
    int dest = n;
    if (dist[dest] == INF) {
        cout << -1 << "\n";
    } else {
        vector<int> path;
        for (int cur = dest; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());

        cout << "Distancia: " << dist[dest] << "\nCamino: ";
        for (int node : path) cout << node << " ";
        cout << "\n";
    }

    return 0;
}