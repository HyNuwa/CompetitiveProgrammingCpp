#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
    vector<int> applicants(n);
    vector<int> apartments(m);
    /*
    Si SÍ sabes el tamaño y 
    quieres código corto (ej. programación competitiva): 
    Usa tu método vector<int> v(n); y accede con v[i]. 
    Es rapidísimo y toma menos líneas de código.
    
    */
    for (int v = 0; v < n; v++) {
        cin >> applicants[v];
    }

    for (int v = 0; v < m; v++) {
        cin >> apartments[v];
    }
}