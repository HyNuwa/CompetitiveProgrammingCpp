#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Optimización de la entrada/salida para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int best = 1;
    int cur = 1;

    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            cur++;
        } else {
            cur = 1;
        }
        best = max(best, cur);
    }

    cout << best << "\n";

    return 0;
}