/**
 * ============================================================================
 * GUÍA E IMPLEMENTACIÓN: ALGORITMO DE DIJKSTRA
 * ============================================================================
 * 
 * ¿QUÉ HACE?
 * Calcula la distancia mínima desde un nodo origen (src) hacia todos los demás 
 * nodos en un grafo ponderado con pesos NO negativos (w >= 0).
 * 
 * COMPLEJIDAD:
 * - Tiempo:  O(M log N) usando un min-heap (priority_queue con greater<>).
 * - Memoria: O(N + M) para la lista de adyacencia y vectores auxiliares.
 * 
 * REGLAS DE USO PRÁCTICAS:
 * 1. Pesos grandes: Si w <= 10^9, la distancia acumulada desborda un int de 32 bits.
 *    Usar siempre 'long long' para las distancias y definir INF = 1e18.
 * 2. Grafo Dirigido vs No Dirigido:
 *    - Dirigido (one-way): adj[u].push_back({v, w});
 *    - No dirigido (two-way): adj[u].push_back({v, w}); adj[v].push_back({u, w});
 * 3. ¿Solo distancias o reconstruir camino?
 *    - Solo distancias: Esta plantilla retorna el vector dist[] directamente.
 *    - Si piden el camino: Guardar un vector parent[] y actualizar parent[v] = u
 *      en la relajación para reconstruir desde el destino hacia atrás.
 * 
 * PROBLEMAS CLÁSICOS RESOLUBLES DIRECTAMENTE CON ESTA PLANTILLA:
 * - CSES 1671: Shortest Routes I (Aplicación directa, grafo dirigido)
 * - CSES 1195: Flight Discount (Dijkstra sobre grafo en capas)
 * - Codeforces 20C: Dijkstra? (Distancia mínima y camino)
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

// Constante para representar infinito (distancia inalcanzable)
const long long INF = 1e18;

/**
 * Función modular de Dijkstra
 * @param src Nodo inicial / origen (1-indexed)
 * @param n Cantidad total de nodos
 * @param adj Lista de adyacencia donde adj[u] tiene pares {nodo_destino, peso_arista}
 * @return vector<long long> con las distancias mínimas dist[1..n] desde src
 */
vector<long long> dijkstra(int src, int n, const vector<vector<pair<int, long long>>>& adj) {
    // 1. Inicialización: todas las distancias en infinito y el origen en 0
    vector<long long> dist(n + 1, INF);
    dist[src] = 0;

    // 2. Min-Heap ordenado por menor distancia acumulada: pair<distancia, nodo>
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, src});

    // 3. Proceso de relajación voraz
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Optimización clave: descartar pares obsoletos que quedaron en la cola
        if (d > dist[u]) continue;

        // Recorrer todos los vecinos de u
        for (const auto& [v, w] : adj[u]) {
            // Relajación: ¿podemos mejorar la distancia hacia v pasando por u?
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    // Optimización de entrada / salida estándar para ICPC
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Lista de adyacencia indexada en 1..n
    vector<vector<pair<int, long long>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Arista dirigida u -> v con costo w
        
        // Si el problema requiere caminos bidireccionales, descomentar:
        // adj[v].push_back({u, w});
    }

    // Ejecutar Dijkstra desde el nodo origen (ejemplo: nodo 1)
    int src = 1;
    vector<long long> dist = dijkstra(src, n, adj);

    // Salida: imprimir distancias mínimas a todos los nodos del 1 al n
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}