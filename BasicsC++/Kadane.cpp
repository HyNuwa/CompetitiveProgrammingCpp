#include <bits/stdc++.h>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {-1, -2, 3, 5, -1};
    int n=5;
    int best = 0;
    //Brute force solution
    // O(n^2) time complexity
    for (int a = 0; a < n; a++) {
        int sum = 0;                     // (1) reiniciamos la suma para cada nuevo a
        for (int b = a; b < n; b++) {
            sum += v[b];             // (2) vamos añadiendo elemento tras elemento
            best = std::max(best, sum);       // (3) comprobamos si esta suma parcial es la mejor
        }
    }
    std::cout << best << "\n";

    return 0;
}