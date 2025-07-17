#include <bits/stdc++.h>
using namespace std;
//O(N^2) Time Complexity
void bubbleSort(vector <int> arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main(){
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) a[i] = rand();

    auto start = clock();
    sort(a.begin(), a.end());
    auto end = clock();
     
    cout << "For n = " << n << "\n";
    cout << "Inbuilt Sort : " << end - start << "\n";

    auto start1 = clock();
    bubbleSort(a, n);
    auto end1 = clock();

    cout << "Bubble Sort : " << end1 - start1 << "\n";
    return 0;
}
