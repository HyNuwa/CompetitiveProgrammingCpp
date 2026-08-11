#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    long long moves = 0; // Usar long long porque la suma de diferencias puede superar 2*10^9

    for (int i = 1; i < n; i++) {
        if (x[i] < x[i - 1]) {
            moves += (x[i - 1] - x[i]);
            x[i] = x[i - 1]; // El número actual sube al valor del anterior
        }
    }

    cout << moves << "\n";
    return 0;
}