#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        sz.assign(n + 1, 1);
    }
    int find(int x) {
        return (p[x] == x) ? x : (p[x] = find(p[x]));
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

struct KruskalResult {
    long long total_weight;
    bool is_connected;
    vector<Edge> mst_edges; // Lista de aristas seleccionadas
};

// Función modular que ejecuta Kruskal
KruskalResult run_kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    
    long long total_weight = 0;
    vector<Edge> mst_edges;

    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total_weight += e.w;
            mst_edges.push_back(e);
        }
    }

    bool is_connected = ((int)mst_edges.size() == n - 1);
    return {total_weight, is_connected, mst_edges};
}

/// EJEMPLO DE MAIN PARA CSES 1675 Road Reparation
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    KruskalResult res = run_kruskal(n, edges);

    if (!res.is_connected) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << res.total_weight << "\n";
    }

    return 0;
}
