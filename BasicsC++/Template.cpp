#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <random>
#include <bits/stdc++.h>
using namespace std;

//macros
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define ENDL '\n'
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define sortall(x) sort(all(x))
#define deb(x) cout << x << ENDL;
#define deb2(x, y) cout << x <<  " == " << y << ENDL;
#define FOR(i,a,n) for(int i = (a); i < (n); i++)
#define RFOR(i,a,n) for(int i = (a); i >= n; i--)
#define ll long long
#define pii pair<int,int>
#define pll pair<lli,lli>
#define FULL(a,num) memset(a,num, sizeof a)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
const ll maxV = 1e14;
//functions
bool isPrime(const int& num);
int gcd(const int& a, const int& b);
int lcm(const int& a, const int& b);

void solve() {
}


int main() {
    ios_base::sync_with_stdio(1); cin.tie(0); cout.tie(0);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}


bool isPrime(const int&  num){
    for(int i = 2; i <= ceil(sqrt(num)); i++) if(num%i == 0) return false;
    return true;
}
int gcd(const int& a, const int& b){
    return b ? gcd(b,a%b) : a;
}

int lcm(const int& a, const int& b){
    return a / (gcd(a,b) * b);
}