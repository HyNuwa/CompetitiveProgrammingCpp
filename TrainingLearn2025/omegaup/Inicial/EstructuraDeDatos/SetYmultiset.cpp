#include <bits/stdc++.h>

using namespace std;
int main()
{

    
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int valor;
        cin >> valor;
        s.insert(valor);
    }
    // Mostrar los datos del set
    set<int>::iterator it = s.begin();
    for (; it != s.end(); it++)
    {
        cout << *it << " ";
    }

    /*
    Multiset: Permite elementos duplicados
    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int valor;
        cin >> valor;
        ms.insert(valor);
    }
    // Mostrar los datos del multiset
    multiset<int>::iterator it = ms.begin();
    for (; it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Tamaño del set: " << s.size() << endl; 
    cout << "La cantidad es: " << ms.size(2) << endl;
    */
}