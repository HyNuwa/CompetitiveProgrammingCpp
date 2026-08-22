#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll modpow(ll b, ll e, ll m){
    b%=m; if(b<0) b+=m;
    ll r=1;
    while(e>0){
        if(e&1) r = r*b % m;
        b = b*b % m;
        e >>= 1;
    }
    return r;
}

int main(){
    int N; ll K;
    if(!(cin >> N >> K)) return 0;
    vector<ll> r(N), p(N);
    for(int i=0;i<N;i++) cin >> r[i];
    for(int i=0;i<N;i++) cin >> p[i];

    vector<ll> sr = r;
    sort(sr.begin(), sr.end(), greater<ll>());
    ll T = sr[K-1]; // K-th largest (1-indexed)

    ll inv1000 = modpow(1000, MOD-2, MOD);

    ll prodA = 1, prodC = 1;
    int c = 0;
    vector<ll> Bq; // probabilities (mod) for elements with r_i == T

    for(int i=0;i<N;i++){
        ll qi = (p[i] % MOD) * inv1000 % MOD;
        if(r[i] > T){
            prodA = prodA * qi % MOD;
            c++;
        } else if(r[i] == T){
            Bq.push_back(qi);
        } else {
            ll fi = (1 - qi % MOD + MOD) % MOD;
            prodC = prodC * fi % MOD;
        }
    }

    int m = (int)Bq.size();
    ll t = K - c; // need exactly t successes among B

    // DP for exact number of successes among B
    vector<ll> dp(m+1, 0);
    dp[0] = 1;
    int idx = 0;
    for(int k=0;k<m;k++){
        ll qi = Bq[k];
        ll fi = (1 - qi + MOD) % MOD;
        for(int j = idx; j >= 0; j--){
            dp[j+1] = (dp[j+1] + dp[j]*qi) % MOD;
            dp[j] = dp[j]*fi % MOD;
        }
        idx++;
    }

    ll probB = 0;
    if(t >= 0 && t <= m) probB = dp[t];

    ll ans = prodA * prodC % MOD;
    ans = ans * probB % MOD;

    cout << ans << endl;
    return 0;
}