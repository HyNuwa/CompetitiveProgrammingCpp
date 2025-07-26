#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int auxiliar(int N, int K, vector<int> &dp){
    if (N == 0)
        return 1;
    if (N < 0)
        return 0;
    if (dp[N] != -1)
        return dp[N];  // Usar valor memorizado

    int respuesta = 0;
    for (int i = 1; i <= K; i++){
        respuesta = (respuesta + auxiliar(N - i, K, dp)) % mod;
    }

    return dp[N] = respuesta;  // Guardar en dp
}

int resolver(int N, int K){
    vector<int> dp(N + 1, -1);
    return auxiliar(N, K, dp);
}

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;
    cout << resolver(N, K) << '\n';
    return 0;
        
}
