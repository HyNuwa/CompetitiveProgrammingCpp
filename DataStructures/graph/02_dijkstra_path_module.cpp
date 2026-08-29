#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Estructura para almacenar el resultado de Dijkstra
struct DijkstraResult {
    vector<long long> dist;
    vector<int> parent;

    // Función auxiliar para reconstruir el camino a cualquier destino
    vector<int> get_path(int dest) const {
        if (dist[dest] == INF) return {}; // Inalcanzable
        vector<int> path;
        for (int cur = dest; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

// Función modular de Dijkstra
DijkstraResult dijkstra(int src, int n, const vector<vector<pair<int, long long>>>& adj) {
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    
    // Min-heap: {distancia, nodo}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // Descarta distancias obsoletas

        for (const auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return {dist, parent};
}

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
        // Si el grafo es no dirigido, descomentar:
        // adj[v].push_back({u, w});
    }

    int src = 1;
    DijkstraResult res = dijkstra(src, n, adj);

    // Caso 1: Obtener distancia a un nodo específico (ej. n)
    int dest = n;
    if (res.dist[dest] == INF) {
        cout << -1 << "\n";
    } else {
        cout << "Distancia minima: " << res.dist[dest] << "\n";
        
        // Caso 2: Reconstruir e imprimir el camino
        vector<int> path = res.get_path(dest);
        cout << "Camino: ";
        for (int node : path) cout << node << " ";
        cout << "\n";
    }

    return 0;
}