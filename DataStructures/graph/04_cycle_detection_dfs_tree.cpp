/**
 * TEMA: DFS Tree & Detección de ciclos en grafo no dirigido (Diapos 11, 15 y 34)
 * COMPLEJIDAD: O(N + M)
 * 
 * PROBLEMAS RESOLUBLES CON ESTE CÓDIGO:
 * - CSES 1669: Round Trip (Encontrar cualquier ciclo simple de longitud >= 3)
 * - Detección de puentes y puntos de articulación (Tarjan usa este mismo principio de DFS Tree)
 * - Identificación de componentes 2-conexas.
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int vis[MAXN]; // 0: no visitado, 1: en recursión activa, 2: completado
int parent_node[MAXN];
int cycle_start = -1, cycle_end = -1;

bool dfs_find_cycle(int u, int p) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue; // Arista hacia el padre inmediato
        if (vis[v] == 1) {    // Back-edge: cierra un ciclo
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        if (vis[v] == 0) {
            parent_node[v] = u;
            if (dfs_find_cycle(v, u)) return true;
        }
    }
    vis[u] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0 && dfs_find_cycle(i, 0)) break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int cur = cycle_end; cur != cycle_start; cur = parent_node[cur]) {
            cycle.push_back(cur);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int node : cycle) cout << node << " ";
        cout << "\n";
    }

    return 0;
}