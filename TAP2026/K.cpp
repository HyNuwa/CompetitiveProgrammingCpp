#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n = 1;
    cin >> n;
    vector<int> comb(n);
    vector<int> ent = {0, 5, 1, 6, 2, 7, 3, 8, 4};

    for (int i = 0; i < n; i++) {
        cin >> comb[i];
    }

    for(int elem: comb){
        cout << ent[elem] << " ";
    }
}