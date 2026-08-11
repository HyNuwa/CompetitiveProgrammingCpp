#include <bits/stdc++.h>
using namespace std;

// Function to count frequency of each element in the array using unordered_map
void Frequency(int arr[], int n) {
    // Create an unordered_map to store frequency of each element
    unordered_map<int, int> map;

    // Traverse the array and count frequencies
    for (int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    // Traverse through the unordered_map and print frequencies
    for (auto x : map) {
        cout << x.first << " " << x.second << endl;
    }
}

int main() {
    // Input array
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function to count frequencies
    Frequency(arr, n);
    return 0;
}
