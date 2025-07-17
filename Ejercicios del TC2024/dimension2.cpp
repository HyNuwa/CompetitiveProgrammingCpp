#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> secuencia;

    secuencia.push_back(n);

    for (int i = 1; i < m; ++i) {
        if (n == 1) {
            break;
        }
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        secuencia.push_back(n);
    }

    if (secuencia.back() == 1 && secuencia.size() < m) {
        cout << 1 << endl;
    } else {
        for (int i = 0; i < secuencia.size(); ++i) {
            if (i > 0) cout << " ";
            cout << secuencia[i];
        }
        cout << endl;
    }

    return 0;
}
