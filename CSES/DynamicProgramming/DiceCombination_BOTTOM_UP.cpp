#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // caso base: hay 1 forma de sumar 0 (no lanzar el dado)

    for (int i = 1; i <= n; i++) {
        for (int dado = 1; dado <= 6; dado++) {
            if (i - dado >= 0) {
                dp[i] = (dp[i] + dp[i - dado]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}