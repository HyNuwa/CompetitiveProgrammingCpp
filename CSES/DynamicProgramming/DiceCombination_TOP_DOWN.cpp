#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<long long> memo;
vector<bool> visitado;

long long resolver(int i) {
    if (i == 0) return 1;      // caso base
    if (i < 0) return 0;       // no válido
    if (visitado[i]) return memo[i]; // ya calculado

    visitado[i] = true;
    long long resultado = 0;
    for (int dado = 1; dado <= 6; dado++) {
        resultado = (resultado + resolver(i - dado)) % MOD;
    }

    memo[i] = resultado;
    return resultado;
}

int main() {
    int n;
    cin >> n;

    memo.assign(n + 1, 0);
    visitado.assign(n + 1, false);

    cout << resolver(n) << endl;
    return 0;
}