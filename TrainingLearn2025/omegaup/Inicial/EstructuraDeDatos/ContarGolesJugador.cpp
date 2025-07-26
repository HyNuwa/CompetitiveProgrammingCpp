#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> jugadores;
    string nombre;
    int goles;
    for (int i = 0; i < n; i++)
    {
        cin >> nombre;
        cin >> goles;
        jugadores[nombre] = jugadores[nombre] + goles;
    }
    // Mostrar los datos del pair
    map<string, int>::iterator it;
    for (it = jugadores.begin(); it != jugadores.end(); it++)
    {
        //cout << (*it).first << ' ';
        cout << it->first << endl;
        cout << it->second << endl;
    }
}