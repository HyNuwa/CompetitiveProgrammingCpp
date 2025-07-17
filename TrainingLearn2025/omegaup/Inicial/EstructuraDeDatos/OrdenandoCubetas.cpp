#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    multiset<int> ms;
    // Cargar de los valores al set
    for(int i=0; i < n; i++){
        int valor;
        cin>>valor;
        ms.insert(valor);
    }
    
    for(int i=1; i <= m; i++){
        cout << i << ": " << ms.count(i)<< endl;
    }
    
    return 0;
}