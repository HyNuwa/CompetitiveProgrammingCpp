#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 1e6;
const int M = 1e9 + 7;
ll dp[mxN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    dp[0] = 1;
    // Inicializamos dp[i] = 0 antes de cada cálculo
    for (int i = 1; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 1; j <= 6 && j <= i; ++j) {
            dp[i] = (dp[i] + dp[i - j]) % M;
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
