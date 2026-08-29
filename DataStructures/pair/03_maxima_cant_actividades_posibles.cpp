#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // {hora_fin, hora_inicio}
    std::vector<std::pair<int, int>> actividades = {
        {2, 1}, {4, 3}, {6, 0}, {7, 5}, {9, 8}, {9, 5}
    };

    std::sort(actividades.begin(), actividades.end());

    int count = 0;
    int ultimo_fin = -1;

    for (auto act : actividades) {
        int fin = act.first;
        int inicio = act.second;
        if (inicio >= ultimo_fin) {
            count++;
            ultimo_fin = fin;
        }
    }

    std::cout << "Maximo de actividades posibles: " << count << "\n";
}