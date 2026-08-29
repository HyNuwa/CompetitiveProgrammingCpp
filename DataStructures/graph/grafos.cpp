#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MAXN = 2e5 + 100;

vector<vector<int>> grafo(MAXN);
ll costo[MAXN];
bool vis[MAXN];

ll dfs(int v){
    ll m = costo[v];

    vis[v] = true;

    for (auto x : grafo[v]){
        if (not vis[x]){
            m = min(m, dfs(x));
        }
    }
    return m;
}

void dfs2(int v){
    vis[v] = true;
    // aca podemos procesar cada nodo antes que a sus vecinos.
    // sugerencia: probar que pasa si aca hacemos:
    cout << v << "\n";
    for (auto x : grafo[v]){ // recorremos los vecinos de v
        if (not vis[x]){ // pero solo los que aun no visitamos
            dfs(x);
        }
    }
    // aca podemos procesar cada nodo despues que a sus vecinos.
}

void bfs(int inicio){
    queue<int> q;
    q.push(inicio);
    vis[inicio] = true;

    while (!q.empty()){
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int x : grafo[v]){
            if (!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
    cout << "\n";
}

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> costo[i];
    }

    // Para ingresa1r los valores a un grafo
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--; // Para sincronizar junto a los indices

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    } /*  */
    ll ans = 0;

    for (int i = 0; i < n; i++){
        if (not vis[i])

            ans += dfs(i);
    }
    cout << ans << "\n";

    return 0;
}