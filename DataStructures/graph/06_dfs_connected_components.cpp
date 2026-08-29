/**
 * TEMA: Depth First Search (DFS) & Componentes Conexas (Diapos 6-11)
 * COMPLEJIDAD: O(N + M)
 * 
 * PROBLEMAS RESOLUBLES CON ESTE CÓDIGO:
 * - Codeforces 893C: Rumor (Costo mínimo por cada componente conexa)
 * - CSES 1666: Building Roads (Contar componentes conexas y unirlas)
 * - CSES 1192: Counting Rooms (DFS/Flood Fill en grilla)
 * - Conectividad básica y cálculo del tamaño de componentes conexas.
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> grafo[MAXN];
long long costo[MAXN];
bool vis[MAXN];

// DFS que retorna el costo mínimo dentro de la componente conexa
long long dfs(int u) {
    vis[u] = true;
    long long min_cost = costo[u];
    
    for (int v : grafo[u]) {
        if (!vis[v]) {
            min_cost = min(min_cost, dfs(v));
        }
    }
    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; ++i) {
        cin >> costo[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    long long total_cost = 0;
    int num_componentes = 0;

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            total_cost += dfs(i);
            num_componentes++;
        }
    }

    cout << "Componentes: " << num_componentes << "\n";
    cout << "Costo total optimo: " << total_cost << "\n";

    return 0;
}