#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<long long> tree;

    // Función auxiliar para construir el árbol recursivamente
    // node: índice en el vector 'tree' (1-based)
    // l, r: rango actual del arreglo cubierto por este nodo
    void build(const vector<long long>& arr, int node, int l, int r) {
        if (l == r) {
            // Caso base: hoja del árbol (representa un único elemento)
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        int left_child = 2 * node;
        int right_child = 2 * node + 1;

        // Construir subárbol izquierdo y subárbol derecho
        build(arr, left_child, l, mid);
        build(arr, right_child, mid + 1, r);

        // Combinar los resultados de los hijos (Suma en este caso)
        tree[node] = tree[left_child] + tree[right_child];
    }

    // Actualización puntual: arr[idx] = val
    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            // Llegamos a la hoja correspondiente
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        int left_child = 2 * node;
        int right_child = 2 * node + 1;

        if (idx <= mid) {
            // El índice a modificar está en el hijo izquierdo
            update(left_child, l, mid, idx, val);
        } else {
            // El índice a modificar está en el hijo derecho
            update(right_child, mid + 1, r, idx, val);
        }

        // Recalcular el valor del nodo actual tras el cambio
        tree[node] = tree[left_child] + tree[right_child];
    }

    // Consulta de rango: suma en el intervalo [ql, qr]
    long long query(int node, int l, int r, int ql, int qr) {
        // Caso 1: Rango del nodo completamente fuera del rango de consulta
        if (r < ql || l > qr) {
            return 0; // Elemento neutro para la suma
        }
        // Caso 2: Rango del nodo totalmente contenido en la consulta
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        // Caso 3: Solapamiento parcial -> consultar ambos hijos
        int mid = (l + r) / 2;
        long long left_sum = query(2 * node, l, mid, ql, qr);
        long long right_sum = query(2 * node + 1, mid + 1, r, ql, qr);

        return left_sum + right_sum;
    }

public:
    // Constructor a partir de un arreglo inicial
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        // El árbol necesita a lo sumo 4*n nodos
        tree.assign(4 * n, 0);
        if (n > 0) {
            build(arr, 1, 0, n - 1);
        }
    }

    // Interfaz pública (0-indexed)
    void update(int idx, long long val) {
        update(1, 0, n - 1, idx, val);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    // Ejemplo de uso:
    vector<long long> datos = {1, 3, 5, 7, 9, 11};
    SegmentTree st(datos);

    // Consultar suma en rango [1, 3] -> datos[1] + datos[2] + datos[3] = 3 + 5 + 7 = 15
    cout << "Suma en rango [1, 3]: " << st.query(1, 3) << "\n";

    // Actualizar datos[1] = 10 (el arreglo ahora es {1, 10, 5, 7, 9, 11})
    st.update(1, 10);
    cout << "Suma en rango [1, 3] tras update: " << st.query(1, 3) << "\n"; // 10 + 5 + 7 = 22

    return 0;
}