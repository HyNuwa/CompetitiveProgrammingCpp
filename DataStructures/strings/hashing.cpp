#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct DoubleHash {
    const long long B1 = 313, M1 = 1e9 + 7;
    const long long B2 = 317, M2 = 1e9 + 9;
    vector<long long> h1, h2, p1, p2;

    DoubleHash(const string& s) {
        int n = s.size();
        h1.assign(n + 1, 0); h2.assign(n + 1, 0);
        p1.assign(n + 1, 1); p2.assign(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * B1) % M1;
            p2[i + 1] = (p2[i] * B2) % M2;
            h1[i + 1] = (h1[i] * B1 + s[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + s[i]) % M2;
        }
    }

    // Retorna hash del subrango [l, r] (0-indexed, inclusive)
    pair<long long, long long> get_hash(int l, int r) {
        long long res1 = (h1[r + 1] - (h1[l] * p1[r - l + 1]) % M1 + M1) % M1;
        long long res2 = (h2[r + 1] - (h2[l] * p2[r - l + 1]) % M2 + M2) % M2;
        return {res1, res2};
    }
};

// String Matching: busca cantidad de apariciones de P en T
int string_matching(const string& T, const string& P) {
    if (P.size() > T.size()) return 0;
    DoubleHash ht(T), hp(P);
    auto target = hp.get_hash(0, P.size() - 1);
    int matches = 0;

    for (int i = 0; i + P.size() <= T.size(); ++i) {
        if (ht.get_hash(i, i + P.size() - 1) == target) {
            matches++;
        }
    }
    return matches;
}

// Comparación lexicográfica de dos substrings en O(log N) usando LCP
bool es_menor_lexicografico(const string& S, int l1, int r1, const string& T, int l2, int r2, DoubleHash& hs, DoubleHash& ht) {
    int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
    int low = 0, high = min(len1, len2), lcp = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid == 0 || hs.get_hash(l1, l1 + mid - 1) == ht.get_hash(l2, l2 + mid - 1)) {
            lcp = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (lcp == min(len1, len2)) return len1 < len2;
    return S[l1 + lcp] < T[l2 + lcp];
}

int main() {
    string T = "abracadabra", P = "abra";
    cout << "Ocurrencias de '" << P << "': " << string_matching(T, P) << "\n"; // 2
    return 0;
}