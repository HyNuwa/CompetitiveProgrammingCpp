#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo = {
    {1, 2},
    {0, 2, 3},
    {0, 1, 3, 4},
    {1, 2, 4},
    {2, 3}
};

vector<bool> vis(5, false);

void dfs(int v) {
    vis[v] = true;
    cout << "visito " << v << "\n";

    for (int x : grafo[v]) {
        if (!vis[x]) {
            cout << "desde " << v << " voy a " << x << "\n";
            dfs(x);
        }
    }
}

void bfs(int inicio) {
    queue<int> q;
    q.push(inicio);
    vector<bool> visto(grafo.size(), false);
    visto[inicio] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << "visito " << v << "\n";

        for (int x : grafo[v]) {
            if (!visto[x]) {
                visto[x] = true;
                q.push(x);
                cout << "encolo " << x << " desde " << v << "\n";
            }
        }
    }
}

int main() {
    cout << "DFS:\n";
    dfs(0);

    cout << "\nBFS:\n";
    bfs(0);

    return 0;
}
