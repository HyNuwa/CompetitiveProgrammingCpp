#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    
    // Leer el vector a
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Leer el vector b
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    // Calcular el producto punto
    int producto_punto = 0;
    for (int i = 0; i < n; i++) {
        producto_punto += a[i] * b[i];
    }
    
    // Mostrar resultado
    cout << producto_punto << endl;
    
    return 0;
}