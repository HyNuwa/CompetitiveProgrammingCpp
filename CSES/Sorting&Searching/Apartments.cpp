#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int v = 0; v < n; v++) {
        cin >> applicants[v];
    }

    for (int v = 0; v < m; v++) {
        cin >> apartments[v];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i=0;
    int j=0;
    int count =0;
    while (i < n && j <m ){
        if (apartments[j] < applicants[i]-k){
            j++;
        }
        else if (apartments[j] > applicants[i]+k){
            i++;
        }
        else {
            count++;
            i++;
            j++;
        }
    }

    cout << count << '\n';
}