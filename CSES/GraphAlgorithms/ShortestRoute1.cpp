#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Función modular de Dijkstra
vector<long long> dijkstra(int src, int n, const vector<vector<pair<int, long long>>>& adj) {
    vector<long long> dist(n + 1, INF);
    // Min-heap: {distancia_acumulada, nodo}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Si ya encontramos un camino mejor antes, descartamos esta entrada obsoleta
        if (d > dist[u]) continue;

        for (const auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    // Optimización de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Solo en una dirección (one-way flight)
    }

    // Calculamos distancias desde la ciudad 1 (Syrjälä)
    vector<long long> dist = dijkstra(1, n, adj);

    // Imprimimos la distancia mínima a cada ciudad de 1 a n
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}