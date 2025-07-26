#include <bits/stdc++.h>
using namespace std;

int main(){
    long long s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    set<long long> st = {s1, s2, s3, s4};
    int cnt = st.size();
    int need = 4 - cnt;

    cout << need << "\n";
    return 0;
}
