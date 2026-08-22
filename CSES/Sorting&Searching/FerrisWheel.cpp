#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
    vector<int> weights(n);

    for (int v = 0; v < n; v++) {
        cin >> weights[v];
    }
    sort(weights.begin(), weights.end());

    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left <= right) {
        if (weights[left] + weights[right] <= m) {
            // Van juntos
            left++;
            right--;
        } else {
            // El más pesado va solo
            right--;
        }

        count++;
    }
    cout << count << "\n";
    /* Idea principal
                        más pesado
                        ↓
            [ 2  3  7  9 ]
            ↑          ↑
            liviano    pesado
    ¿Por qué? Porque si el más liviano + el más pesado 
    no caben, entonces ningún otro niño puede acompañar 
    al más pesado, porque todos los demás pesan igual 
    o más que el liviano. Por eso el greedy funciona.
    */
}
