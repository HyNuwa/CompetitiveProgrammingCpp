#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/231/A
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int solved = 0;
    for (int i = 0; i < n; i++) {
        int p, v, t;
        cin >> p >> v >> t;
        if (p + v + t >= 2) {
            solved++;
        }
    }

    cout << solved << "\n";
    return 0;
}
