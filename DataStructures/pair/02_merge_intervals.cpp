#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Intervalos desordenados: [1, 3], [2, 6], [8, 10], [15, 18]
    std::vector<std::pair<int, int>> intervalos = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};

    // 1. Ordenar por punto de inicio (.first)
    std::sort(intervalos.begin(), intervalos.end());

    std::vector<std::pair<int, int>> fusionados;
    fusionados.push_back(intervalos[0]);

    for (size_t i = 1; i < intervalos.size(); ++i) {
        auto& ultimo = fusionados.back();
        // Si el intervalo actual se solapa con el anterior
        if (intervalos[i].first <= ultimo.second) {
            ultimo.second = std::max(ultimo.second, intervalos[i].second);
        } else {
            fusionados.push_back(intervalos[i]);
        }
    }

    // Resultado: [1, 6], [8, 10], [15, 18]
    for (auto p : fusionados) {
        std::cout << "[" << p.first << ", " << p.second << "] ";
    }
}