#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// La misma función modular que usamos antes
vector<long long> dijkstra(int src, int n, const vector<vector<pair<int, long long>>>& adj) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        // El problema dice que son caminos de doble mano (two-way):
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Matriz para guardar las distancias mínimas entre todos los pares (i, j)
    // dist_all[i] guardará el vector retornado por dijkstra desde el nodo i
    vector<vector<long long>> dist_all(n + 1);

    // Precomputamos Dijkstra desde cada nodo 1..n
    for (int i = 1; i <= n; ++i) {
        dist_all[i] = dijkstra(i, n, adj);
    }

    // Respondemos las Q consultas en O(1)
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dist_all[u][v] == INF) {
            cout << -1 << "\n";
        } else {
            cout << dist_all[u][v] << "\n";
        }
    }

    return 0;
}