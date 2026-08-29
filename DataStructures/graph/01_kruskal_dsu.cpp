/**
 * TEMA: Minimum Spanning Tree (MST) + Disjoint Set Union (DSU) (Diapos 30-32)
 * COMPLEJIDAD: O(M log M)
 * 
 * PROBLEMAS RESOLUBLES CON ESTE CÓDIGO:
 * - CSES 1675: Road Reparation (Cálculo directo de MST)
 * - CSES 1676: Road Construction (Seguimiento del tamaño de componentes conexas)
 * - Codeforces 25D: Road Construction (Detectar aristas redundantes y reconectar)
 * - Problemas de conectividad dinámica sin eliminación de aristas.
 */

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    int num_sets;

    DSU(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        sz.assign(n + 1, 1);
        num_sets = n;
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]); // Path compression
    }

    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b); // Union by size
        p[b] = a;
        sz[a] += sz[b];
        num_sets--;
        return true;
    }

    int size_of(int x) {
        return sz[find(x)];
    }
};

struct Edge {
    long long w;
    int u, v;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long mst_cost = 0;
    int edges_used = 0;

    for (const auto& e : edges) {
        if (dsu.join(e.u, e.v)) {
            mst_cost += e.w;
            edges_used++;
        }
    }

    if (edges_used != n - 1) {
        cout << "IMPOSSIBLE\n"; // El grafo no era conexo
    } else {
        cout << mst_cost << "\n";
    }

    return 0;
}