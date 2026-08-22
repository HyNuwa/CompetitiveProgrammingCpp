#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<long long, int> seen; // valor -> posición (1-indexada)

    for (int i = 0; i < n; i++) {
        long long need = x - a[i];

        auto it = seen.find(need);
        if (it != seen.end()) {
            cout << it->second << " " << (i + 1) << "\n";
            return 0;
        }

        seen[a[i]] = i + 1; // guardamos posición 1-indexada
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}