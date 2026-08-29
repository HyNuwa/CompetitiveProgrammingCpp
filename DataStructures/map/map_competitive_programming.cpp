/**
 * ==============================================================================
 * GUÍA COMPLETA Y REFACTORIZADA DE std::map PARA PROGRAMACIÓN COMPETITIVA (CP)
 * ==============================================================================
 * Contenido:
 * 1. Inicialización y asignación segura.
 * 2. Trampa clásica: operator[] vs find/contains.
 * 3. Búsqueda de cotas: >=, >, <=, < con lower_bound / upper_bound + prev().
 * 4. Extremos (Mínimos y Mayores) y uso como Priority Queue con actualización.
 * 5. Borrado seguro durante iteración.
 * 6. Map con orden descendente (greater<T>).
 * 7. Patrón competitivo: Compresión de coordenadas (Coordinate Compression).
 * ==============================================================================
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. INICIALIZACIÓN BÁSICA Y RECORRIDOS
void demo_inicializacion() {
    cout << "=== 1. INICIALIZACION Y RECORRIDO ===" << '\n';

    // Inicialización por lista
    map<int, string> m = {
        {10, "Diez"},
        {5, "Cinco"},
        {20, "Veinte"}
    };

    // Inserción eficiente in-place
    m.emplace(15, "Quince");

    // Recorrido ascendente (C++17 structured binding)
    for (const auto& [clave, valor] : m) {
        cout << "[" << clave << ": " << valor << "] ";
    }
    cout << "\n\n";
}

// 2. EVITAR LA CREACIÓN ACCIDENTAL CON operator[]
void demo_trampa_operator_bracket() {
    cout << "=== 2. EVITAR CREACION ACCIDENTAL (operator[]) ===" << '\n';

    map<string, int> inventario;
    inventario["manzanas"] = 50;

    // ❌ ERROR COMÚN:
    // if (inventario["peras"] == 10) { ... } -> Crea "peras" con valor 0 y aumenta el tamaño!

    // ✅ FORMA SEGURA 1: find()
    auto it = inventario.find("peras");
    if (it != inventario.end()) {
        cout << "Stock de peras: " << it->second << '\n';
    } else {
        cout << "La clave 'peras' no existe (map no modificado, size = " << inventario.size() << ")\n";
    }

    // ✅ FORMA SEGURA 2: count() o contains() (C++20)
    if (inventario.count("manzanas")) {
        cout << "Stock de manzanas: " << inventario["manzanas"] << '\n';
    }
    cout << "\n";
}

// 3. BÚSQUEDAS DE COTAS (>=, >, <=, <)
void demo_busquedas_cotas() {
    cout << "=== 3. BUSQUEDAS DE COTAS (LOWER/UPPER BOUND) ===" << '\n';

    map<int, string> m = {
        {10, "Diez"},
        {20, "Veinte"},
        {30, "Treinta"},
        {40, "Cuarenta"}
    };

    int x = 25;

    // Cota >= x (lower_bound)
    auto it_ge = m.lower_bound(x);
    if (it_ge != m.end()) {
        cout << "Primer elemento >= " << x << " -> " << it_ge->first << " (" << it_ge->second << ")\n";
    }

    // Cota > x (upper_bound)
    auto it_gt = m.upper_bound(x);
    if (it_gt != m.end()) {
        cout << "Primer elemento > " << x << "  -> " << it_gt->first << " (" << it_gt->second << ")\n";
    }

    // Cota <= x (upper_bound + prev)
    auto it_le = m.upper_bound(x);
    if (it_le != m.begin()) {
        it_le = prev(it_le);
        cout << "Mayor elemento <= " << x << "  -> " << it_le->first << " (" << it_le->second << ")\n";
    }

    // Cota < x (lower_bound + prev)
    auto it_lt = m.lower_bound(x);
    if (it_lt != m.begin()) {
        it_lt = prev(it_lt);
        cout << "Mayor elemento < " << x << "   -> " << it_lt->first << " (" << it_lt->second << ")\n";
    }
    cout << "\n";
}

// 4. EXTREMOS (MÍNIMO Y MÁXIMO) / SIMULAR PRIORITY QUEUE
void demo_extremos() {
    cout << "=== 4. OBTENER EXTREMOS (MIN / MAX) ===" << '\n';

    map<int, int> m = {{50, 500}, {10, 100}, {90, 900}, {30, 300}};

    // Mínimo (primer elemento)
    auto [min_k, min_v] = *m.begin();
    cout << "Minimo: Clave = " << min_k << ", Valor = " << min_v << '\n';

    // Máximo (último elemento usando rbegin o prev(end()))
    auto [max_k, max_v] = *m.rbegin();
    cout << "Maximo: Clave = " << max_k << ", Valor = " << max_v << '\n';

    // Eliminar mínimo y máximo en O(1) amortizado con iterador
    m.erase(m.begin());
    m.erase(prev(m.end()));
    cout << "Despues de borrar min y max, nuevo min = " << m.begin()->first 
         << ", nuevo max = " << m.rbegin()->first << "\n\n";
}

// 5. BORRADO CORRECTO DENTRO DE UN BUCLE
void demo_borrado_seguro() {
    cout << "=== 5. BORRADO SEGURO EN ITERACION ===" << '\n';

    map<int, int> m = {{1, 0}, {2, 5}, {3, 0}, {4, 8}, {5, 0}};

    // Queremos borrar todas las entradas con valor == 0
    for (auto it = m.begin(); it != m.end(); ) {
        if (it->second == 0) {
            // erase(it) devuelve el iterador al siguiente elemento valido
            it = m.erase(it);
        } else {
            ++it;
        }
    }

    cout << "Elementos restantes con valor != 0:\n";
    for (const auto& [k, v] : m) {
        cout << "[" << k << ": " << v << "] ";
    }
    cout << "\n\n";
}

// 6. MAP DESCENDENTE (greater<Key>)
void demo_map_descendente() {
    cout << "=== 6. MAP ORDENADO EN DESCENDENTE ===" << '\n';

    map<int, string, greater<int>> m_desc = {
        {10, "Diez"},
        {50, "Cincuenta"},
        {20, "Veinte"}
    };

    cout << "Elementos ordenados de mayor a menor:\n";
    for (const auto& [k, v] : m_desc) {
        cout << "[" << k << ": " << v << "] ";
    }
    cout << "\n\n";
}

// 7. PATRÓN CP: COMPRESIÓN DE COORDENADAS
void demo_compresion_coordenadas() {
    cout << "=== 7. COMPRESION DE COORDENADAS ===" << '\n';

    vector<int> coordenadas = {1000000000, 5, 300, 5, 1000000000, 42};
    map<int, int> comp;

    for (int x : coordenadas) {
        comp[x] = 0; // Registramos las claves únicas
    }

    int nuevo_id = 0;
    for (auto& [valor, id] : comp) {
        id = nuevo_id++;
    }

    cout << "Mapeo comprimido:\n";
    for (const auto& [orig, id] : comp) {
        cout << orig << " -> ID " << id << '\n';
    }
}

int main() {
    // Optimizacion de I/O para Programacion Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    demo_inicializacion();
    demo_trampa_operator_bracket();
    demo_busquedas_cotas();
    demo_extremos();
    demo_borrado_seguro();
    demo_map_descendente();
    demo_compresion_coordenadas();

    return 0;
}
