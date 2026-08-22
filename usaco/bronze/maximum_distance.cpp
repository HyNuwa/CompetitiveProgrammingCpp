#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/gym/102951/problem/A
// maximum distance between two points (euclidean distance )
	int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);

	for (int &t : x) { cin >> t; }
	for (int &t : y) { cin >> t; }

	double max_dist = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			int square = dx * dx + dy * dy;
            /*
			 * if the square of the distance between the two points is
			 * greater than our current maximum, then update the maximum
			 */
			max_dist = max(max_dist, sqrt(square));
		}
	}

	cout << (int)pow(max_dist, 2) << endl;
}