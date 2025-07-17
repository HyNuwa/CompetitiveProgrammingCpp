// Clase: Tipos de Datos en C++ para Programación Competitiva

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  // Alias para long long (int64_t)
/*
 * 1. TIPOS DE DATOS BÁSICOS
 */

int entero = 42;                 // 32 bits, -2e9 a 2e9 aprox
long long grande = 1e18;         // 64 bits, -9e18 a 9e18
float decimal = 3.14f;           // 32 bits, precisión baja
double dobleDecimal = 3.141592; // 64 bits, precisión media-alta
char letra = 'A';
bool booleano = true;

/*
 * 2. CONSIDERACIONES PARA COMPETENCIAS (ICPC, TAP)
 */

/*
 * a. OVERFLOW
 *    - Cuidado con "int" al hacer operaciones: suma, multiplicación.
 *    - Siempre usar "long long" si hay n > 1e5 o n^2 operaciones.
 */

int a = 1e9, b = 1e9;
// int c = a * b; // ERROR! Overflow (resultado > 2e9)
ll c = 1LL * a * b; // Bien: forzamos promoción a long long

/*
 * b. PRECISIÓN
 *    - Nunca compares floats/doubles con "==".
 *    - Usar fabs(a - b) < EPS como tolerancia.
 */

double x = 0.1 + 0.2; // != 0.3
const double EPS = 1e-9;
if (fabs(x - 0.3) < EPS) {
    cout << "Son iguales con tolerancia." << endl;
}

/*
 * c. TLE (Time Limit Exceeded)
 *    - Evitá usar tipos lentos como "string" innecesariamente.
 *    - Usar "scanf/printf" o "ios::sync_with_stdio(false); cin.tie(NULL);" para entrada/salida rápida.
 */

void inputRapido() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

/*
 * d. TIPOS AVANZADOS
 *    - vector<T>: Arreglos redimensionables.
 *    - pair<T1,T2>: Tuplas de 2 elementos.
 *    - map/set/unordered_map: Estructuras clave-valor o conjuntos (con distintos tiempos).
 */

vector<int> v = {1, 2, 3};
pair<int, string> p = {1, "hola"};
map<string, int> m;

/*
 * e. USO DE typedef / using
 *    - Para ahorrar tiempo y escribir menos.
 */
using pii = pair<int, int>; // par de enteros
using vi = vector<int>;    // vector de enteros

/*
 * f. BUENAS PRÁCTICAS
 *    - Inicializar variables.
 *    - Leer bien los límites del problema.
 *    - Evitar usar "using namespace std;" en contextos grandes, pero en competencias es común.
 *    - Testear con casos extremos: n=0, n=1, n máximo.
 */

int main() {
    inputRapido();
    // Código principal aquí...
    //the usage of std::numbers::pi and std::numbers::e, as <numbers> is not available in most C++ compilers; instead, use acos(-1.0) for pi and exp(1.0) for e.
    // Constantes pi y e:
    // Constantes pi y e:
    cout << "PI = " << acos(-1.0) << "\n";
    cout << "E  = " << exp(1.0)  << "\n";
    return 0;
}
