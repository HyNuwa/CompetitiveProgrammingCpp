#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {40, 10, 20, 50};
    int n = nums.size();

    // Guardamos {valor, indice_original}
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = {nums[i], i};
    }

    // std::sort ordena automáticamente por .first (valor)
    std::sort(v.begin(), v.end());

    // v ahora es: {{10, 1}, {20, 2}, {40, 0}, {50, 3}}
    for (auto p : v) {
        std::cout << "Valor: " << p.first << " | Indice original: " << p.second << "\n";
    }
}