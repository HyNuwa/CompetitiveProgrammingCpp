#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> M = {
        {10, "diez"},
        {20, "veinte"},
        {30, "treinta"},
        {40, "cuarenta"}
    };

    int clave = 25;
    // ------------------------------
    // 1) Encontrar el siguiente (menor > clave)
    // ------------------------------
    auto it_siguiente = M.upper_bound(clave);
    if (it_siguiente != M.end()) {
        std::cout << "Siguiente a " << clave
                  << " es (" << it_siguiente->first
                  << ", " << it_siguiente->second << ")\n";
    } else {
        std::cout << "No hay elemento siguiente a " << clave << "\n";
    }

    // ------------------------------
    // 2) Encontrar el anterior (mayor < clave)
    // ------------------------------
    // lower_bound devuelve el primer elemento >= clave
    auto it_lb = M.lower_bound(clave);
    if (it_lb == M.begin()) {
        std::cout << "No hay elemento anterior a " << clave << "\n";
    } else {
        // retrocedemos un paso para tener < clave
        --it_lb;
        std::cout << "Anterior a " << clave
                  << " es (" << it_lb->first
                  << ", " << it_lb->second << ")\n";
    }
    
    return 0;
}
