#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> prefix(n + 1, 0);  // índice 1-based
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << "\n";
    }
    
    return 0;
}

/*
Example
Input:

8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
Output:

11
2
24
4 */