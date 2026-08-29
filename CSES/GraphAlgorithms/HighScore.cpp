/**
 * CSES 1673 - High Score
 * Algoritmo: Bellman-Ford con chequeo de alcanzabilidad
 * Complejidad: O(N * M)
 */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17;

struct Edge {
    int u, v;
    long long w;
};

// DFS para marcar alcanzabilidad
void dfs(int u, const vector<vector<int>>& gr, vector<bool>& vis) {
    vis[u] = true;
    for (int v : gr[u]) {
        if (!vis[v]) dfs(v, gr, vis);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    vector<vector<int>> adj(n + 1), radj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        // Multiplicamos por -1 para buscar distancia mínima
        edges.push_back({u, v, -w});
        adj[u].push_back(v);
        radj[v].push_back(u); // Grafo reverso para saber si llega a n
    }

    // 1. Preprocesar qué nodos están en el camino entre 1 y n
    vector<bool> from_1(n + 1, false), to_n(n + 1, false);
    dfs(1, adj, from_1);
    dfs(n, radj, to_n);

    // 2. Bellman-Ford
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    // Relajamos n - 1 veces
    for (int i = 1; i <= n - 1; ++i) {
        for (const auto& e : edges) {
            if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // 3. Iteración N: Si relaja un nodo que está entre 1 y n, el score es infinito
    bool ciclo_infinito = false;
    for (const auto& e : edges) {
        if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v]) {
            if (from_1[e.u] && to_n[e.v]) {
                ciclo_infinito = true;
                break;
            }
        }
    }

    if (ciclo_infinito) {
        cout << -1 << "\n";
    } else {
        // Volvemos a invertir el signo para obtener el score máximo real
        cout << -dist[n] << "\n";
    }

    return 0;
}