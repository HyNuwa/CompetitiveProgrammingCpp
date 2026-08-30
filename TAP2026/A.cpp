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
    int h, m, s;

    cin >> h >> m >> s;

    int sumaS = h*3600 + m*60 + s;
    if(sumaS == 9000){
        cout << "=";
    }else if(sumaS < 9000){
        cout << "-";
    }else 
    cout << "+";
    
}