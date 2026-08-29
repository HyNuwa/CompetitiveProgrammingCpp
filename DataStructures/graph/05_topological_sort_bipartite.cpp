/**
 * TEMA: Grafos Bipartitos (2-coloreable) & Orden Topológico en DAG (Diapo 33)
 * COMPLEJIDAD: O(N + M)
 * 
 * PROBLEMAS RESOLUBLES CON ESTE CÓDIGO:
 * - CSES 1668: Building Teams (Bipartite / 2-coloring)
 * - CSES 1679: Course Schedule (Topological Sort / Kahn Algorithm)
 * - CSES 1680: Longest Flight Route (DP sobre el orden topológico de un DAG)
 * - Codeforces 520B: Two Buttons (BFS sobre grafo implícito)
 */

#include <bits/stdc++.h>
using namespace std;

// --- PARTE A: CHEQUEO BIPARTITO ---
bool is_bipartite(int n, const vector<vector<int>>& adj, vector<int>& color) {
    color.assign(n + 1, 0); // 0: sin color, 1 y 2: colores
    for (int i = 1; i <= n; ++i) {
        if (color[i] != 0) continue;
        queue<int> q;
        color[i] = 1;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == 0) {
                    color[v] = 3 - color[u]; // Alterna 1 <-> 2
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false; // Conflicto: ciclo impar
                }
            }
        }
    }
    return true;
}

// --- PARTE B: ORDEN TOPOLÓGICO (Algoritmo de Kahn) ---
vector<int> topological_sort(int n, const vector<vector<int>>& adj_dir) {
    vector<int> in_degree(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        for (int v : adj_dir[u]) in_degree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) q.push(i);
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);

        for (int v : adj_dir[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)topo_order.size() != n) return {}; // Retorna vacío si el grafo tiene ciclos
    return topo_order;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Plantilla multipropósito lista para enlazar con la lógica requerida
    return 0;
}