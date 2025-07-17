#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;
    // Usamos la fórmula: N*(N+1)*(N+2)/6
    long long ans = N * (N + 1) * (N + 2) / 6;
    cout << ans << "\n";

    return 0;
}
