#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << n;
    int n1=n-1;
    int min=1000000000;
    vector<int> dp(n1);

    for (int v = 0; v < n1; v++) {
        cin >> dp[v];
        if(dp[v]>min){
            min=dp[v];
        }
    }

    int result=n*(n+min)/2 - n1*(min+n1)/2;
    cout << result;
    return 0;
}