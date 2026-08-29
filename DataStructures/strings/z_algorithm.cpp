#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Construcción estándar de la Función Z en O(N)
vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// String Matching en O(|T| + |P|) usando P + '#' + T
int string_matching_z(const string& T, const string& P) {
    string combined = P + "#" + T;
    vector<int> z = z_function(combined);
    int matches = 0;
    for (int i = P.size() + 1; i < combined.size(); ++i) {
        if (z[i] == P.size()) matches++;
    }
    return matches;
}

// Finding Periods: Retorna longitudes de prefijos que son periodos válidos
vector<int> periodos(const string& s) {
    int n = s.size();
    vector<int> z = z_function(s);
    vector<int> res;
    for (int k = 1; k <= n; ++k) {
        if (k == n || z[k] == n - k) {
            res.push_back(k);
        }
    }
    return res;
}

// Password: Substring más largo que sea prefijo, sufijo y aparezca en el medio
string password(const string& s) {
    int n = s.size();
    vector<int> z = z_function(s);
    int max_mid = 0, best_len = 0;

    for (int i = 1; i < n; ++i) {
        // Chequea si es prefijo y sufijo, y si ya apareció en el medio
        if (i + z[i] == n && max_mid >= z[i]) {
            best_len = max(best_len, z[i]);
        }
        max_mid = max(max_mid, z[i]);
    }

    return (best_len == 0) ? "Just a legend" : s.substr(0, best_len);
}

int main() {
    string s = "fixprefixsuffix";
    cout << "Periodos de 'abaabaa': ";
    for (int p : periodos("abaabaa")) cout << p << " "; // 6 7
    cout << "\nPassword para '" << s << "': " << password(s) << "\n"; // "fix"
    return 0;
}