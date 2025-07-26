#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    cin >> A >> B;

    // M = número de pasos desde B hasta A
    long M = B - A;
    // m = M/2 floored
    long m = M / 2;

    // Calculamos S0 = Σ_{i=0..M} (-1)^i
    //          S1 = Σ_{i=0..M} i * (-1)^i
    //          S2 = Σ_{i=0..M} i^2 * (-1)^i
    long S0, S1, S2;
    if (M % 2 == 0) {
        // M = 2m
        S0 = 1;
        S1 = m;
        S2 = 2*m*m + m;
    } else {
        // M = 2m+1
        S0 = 0;
        S1 = -m - 1;
        S2 = -2*m*m - 3*m - 1;
    }

    // La suma Δ = Σ_{i=0..M} (-1)^i * (B - i)^2
    //         = B^2 * S0 - 2*B * S1 + S2
    long result = B*B * S0 - 2*B * S1 + S2;

    cout << result << "\n";
    return 0;
}
