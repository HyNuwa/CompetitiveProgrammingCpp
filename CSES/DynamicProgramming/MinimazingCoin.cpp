#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // dp[i] = mínimo número de monedas para formar i
    vector<int> dp(x + 1, x + 1);

    // Para formar 0 necesitamos 0 monedas
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {

        for (int coin : coins) {

            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[x] == x + 1) {
        cout << -1 << '\n';
    } else {
        cout << dp[x] << '\n';
    }

    return 0;
}