#include <iostream>
#include <map>

using namespace std;
// https://usaco.guide/bronze/intro-sets in the end of section of map
int main() {
	int query_num;
	cin >> query_num;
	map<long long, long long> a;  // Map to store only assigned indices
	for (int q = 0; q < query_num; q++) {
		int t;
		cin >> t;
		if (t == 0) {
			long long k, v;
			cin >> k >> v;
			a[k] = v;
		} else if (t == 1) {
			long long k;
			cin >> k;
			// If k is not in the map, operator[] returns 0 by default
			cout << a[k] << '\n';
		}
	}
}