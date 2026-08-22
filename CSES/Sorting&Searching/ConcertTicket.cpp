#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<long long> tickets;
    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;
        tickets.insert(h);
    }


    for (int i = 0; i < m; i++) {
        long long t;
        cin >> t;

        // Find the largest ticket price <= t
        auto it = tickets.upper_bound(t); // first element > t
        if (it == tickets.begin()) {
            cout << -1 << "\n";   // <-- llamada a cout en cada iteración
        } else {
            --it; // now points to largest element <= t
            cout << *it << "\n";  // <-- llamada a cout en cada iteración
            tickets.erase(it);
        }
    }

    return 0;
}