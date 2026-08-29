/**
 * TEMA: Bellman-Ford con detección y reconstrucción de ciclos negativos (Diapos 25-27)
 * COMPLEJIDAD: O(N * M)
 * 
 * PROBLEMAS RESOLUBLES CON ESTE CÓDIGO:
 * - CSES 1673: High Score (Multiplicando pesos por -1 para buscar el camino más largo)
 * - CSES 1197: Cycle Finding (Encontrar y listar un ciclo de peso negativo)
 * - Detección de oportunidades de arbitraje en conversión de divisas.
 */

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist(n + 1, 0); // dist en 0 si buscamos ciclo negativo en cualquier componente
    vector<int> parent(n + 1, -1);
    int last_relaxed = -1;

    for (int i = 1; i <= n; ++i) {
        last_relaxed = -1;
        for (const auto& e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = max(-INF, dist[e.u] + e.w);
                parent[e.v] = e.u;
                last_relaxed = e.v;
            }
        }
    }

    if (last_relaxed == -1) {
        cout << "NO NEGATIVE CYCLE\n";
    } else {
        cout << "YES\n";
        // Retroceder N veces para garantizar entrar dentro del ciclo
        int cycle_node = last_relaxed;
        for (int i = 0; i < n; ++i) {
            cycle_node = parent[cycle_node];
        }

        vector<int> cycle;
        for (int cur = cycle_node;; cur = parent[cur]) {
            cycle.push_back(cur);
            if (cur == cycle_node && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Ciclo negativo: ";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }

    return 0;
}