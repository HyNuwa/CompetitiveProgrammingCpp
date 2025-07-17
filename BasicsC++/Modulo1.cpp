#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;  // 1000000007

/*
 * ¿QUÉ ES LA ARITMÉTICA MODULAR?
 * 
 * Es como un reloj: después de las 12 horas, vuelves a 1.
 * En matemáticas: después de MOD números, vuelves a 0.
 * 
 * Ejemplo: Si MOD = 5
 * 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2...
 * 
 * 7 % 5 = 2 (porque 7 = 1*5 + 2)
 * 13 % 5 = 3 (porque 13 = 2*5 + 3)
 */

// PROBLEMA 1: Evitar overflow
void ejemplo_overflow() {
    cout << "=== PROBLEMA DE OVERFLOW ===\n";
    
    // Imagina que quieres calcular 999999999 * 999999999
    ll a = 999999999;
    ll b = 999999999;
    
    // MALO: esto causa overflow
    // ll resultado_malo = a * b;  // ¡OVERFLOW!
    
    // BUENO: usando aritmética modular
    ll resultado_bueno = (a % MOD) * (b % MOD) % MOD;
    
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "a * b mod " << MOD << " = " << resultado_bueno << "\n\n";
}

// PROBLEMA 2: Contar formas de hacer algo
void ejemplo_conteo() {
    cout << "=== PROBLEMA DE CONTEO ===\n";
    
    // Problema: ¿De cuántas formas puedes llegar del punto (0,0) al (3,2)
    // solo moviéndote derecha (R) o arriba (U)?
    
    // Respuesta: necesitas 3R y 2U, total 5 movimientos
    // Formas = C(5,3) = 5!/(3!*2!) = 10
    
    // Pero si los números son grandes, necesitas aritmética modular
    
    // Calculemos 10! mod MOD
    ll factorial = 1;
    for (int i = 1; i <= 10; i++) {
        factorial = (factorial * i) % MOD;
    }
    
    cout << "10! mod " << MOD << " = " << factorial << "\n\n";
}

// PROBLEMA 3: Potencias grandes
ll pow_mod(ll base, ll exp, ll m = MOD) {
    ll resultado = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1) {  // Si exp es impar
            resultado = (resultado * base) % m;
        }
        base = (base * base) % m;
        exp >>= 1;  // exp = exp / 2
    }
    return resultado;
}

void ejemplo_potencias() {
    cout << "=== POTENCIAS GRANDES ===\n";
    
    // Problema: calcular 2^1000000 mod MOD
    // Imposible calcular 2^1000000 directamente (demasiado grande)
    
    ll resultado = pow_mod(2, 1000000);
    cout << "2^1000000 mod " << MOD << " = " << resultado << "\n\n";
}

// PROBLEMA 4: Fibonacci con aritmética modular
void ejemplo_fibonacci() {
    cout << "=== FIBONACCI MODULAR ===\n";
    
    // Problema: calcular el Fibonacci número 1000000
    // Los números de Fibonacci crecen exponencialmente
    
    ll fib[100];  // Solo calculamos los primeros 100 para demostrar
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i < 100; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
    
    cout << "Primeros 10 Fibonacci mod " << MOD << ":\n";
    for (int i = 0; i < 10; i++) {
        cout << "F(" << i << ") = " << fib[i] << "\n";
    }
    cout << "\n";
}

// PROBLEMA 5: Inverso modular (división en aritmética modular)
ll inv_mod(ll a, ll m = MOD) {
    // Usando teorema de Fermat: a^(p-1) ≡ 1 (mod p)
    // Entonces: a^(p-2) ≡ a^(-1) (mod p)
    return pow_mod(a, m - 2, m);
}

void ejemplo_division() {
    cout << "=== DIVISIÓN MODULAR ===\n";
    
    // Problema: calcular (a/b) mod MOD
    // En aritmética modular, no existe división directa
    // Pero podemos multiplicar por el inverso modular
    
    ll a = 100;
    ll b = 7;
    
    ll inv_b = inv_mod(b);  // Inverso de b mod MOD
    ll resultado = (a * inv_b) % MOD;
    
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "Inverso de " << b << " mod " << MOD << " = " << inv_b << "\n";
    cout << "a/b mod " << MOD << " = " << resultado << "\n\n";
    
    // Verificación: (b * inv_b) % MOD debería ser 1
    cout << "Verificación: " << b << " * " << inv_b << " mod " << MOD << " = ";
    cout << (b * inv_b) % MOD << "\n\n";
}

// PROBLEMA PRÁCTICO: Combinaciones C(n,r) mod MOD
vector<ll> fact, inv_fact;

void precompute_factorials(int n) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    inv_fact[n] = inv_mod(fact[n]);
    for (int i = n - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

ll combination(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * inv_fact[r] % MOD) * inv_fact[n-r] % MOD;
}

void ejemplo_combinaciones() {
    cout << "=== COMBINACIONES C(n,r) ===\n";
    
    precompute_factorials(1000);
    
    // Problema: ¿De cuántas formas puedes elegir 3 personas de 10?
    int n = 10, r = 3;
    ll resultado = combination(n, r);
    
    cout << "C(" << n << "," << r << ") mod " << MOD << " = " << resultado << "\n";
    
    // Problema más grande: C(1000, 500)
    resultado = combination(1000, 500);
    cout << "C(1000,500) mod " << MOD << " = " << resultado << "\n\n";
}

// OPERACIONES BÁSICAS SEGURAS
inline ll add_mod(ll a, ll b, ll m = MOD) {
    ll r = a + b;
    if (r >= m) r -= m;
    return r;
}

inline ll sub_mod(ll a, ll b, ll m = MOD) {
    ll r = a - b;
    if (r < 0) r += m;
    return r;
}

inline ll mul_mod(ll a, ll b, ll m = MOD) {
    return ((a % m) * (b % m)) % m;
}

void ejemplo_operaciones_basicas() {
    cout << "=== OPERACIONES BÁSICAS SEGURAS ===\n";
    
    ll a = 999999999;
    ll b = 888888888;
    
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "a + b mod " << MOD << " = " << add_mod(a, b) << "\n";
    cout << "a - b mod " << MOD << " = " << sub_mod(a, b) << "\n";
    cout << "a * b mod " << MOD << " = " << mul_mod(a, b) << "\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << "ARITMÉTICA MODULAR - EJEMPLOS PRÁCTICOS\n";
    cout << "MOD = " << MOD << "\n\n";
    
    ejemplo_overflow();
    ejemplo_conteo();
    ejemplo_potencias();
    ejemplo_fibonacci();
    ejemplo_division();
    ejemplo_combinaciones();
    ejemplo_operaciones_basicas();
    
    cout << "=== CUÁNDO USAR ARITMÉTICA MODULAR ===\n";
    cout << "1. Cuando los números pueden ser muy grandes (overflow)\n";
    cout << "2. En problemas de conteo (¿cuántas formas hay de...?)\n";
    cout << "3. Al calcular potencias grandes\n";
    cout << "4. En secuencias que crecen rápido (Fibonacci, factorial)\n";
    cout << "5. Cuando el problema pide resultado 'mod 1e9+7'\n";
    
    return 0;
}