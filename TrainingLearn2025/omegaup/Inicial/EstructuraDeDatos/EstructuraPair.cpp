#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ESTRUCTURA PAIR
    int n;
    cin >> n;
    // Definir el vector de pares
    vector<pair<string, int>> jugadores(n);
    string nombre;
    int goles;
    for(int i = 0; i < n; i++)
    {
        cin >> jugadores[i].first;
        cin >> jugadores[i].second;
    }
    for(int i = 0; i < n; i++)
    {
        cout << jugadores[i].first << ' ';
    }

    /*
    vector<pair<string, int>> jugadores(n);
    string nombre;
    int goles;
    for(int i = 0; i < n; i++)
    {
        cin >> nombre;
        cin >> goles;
        jugadores[i].first = nombre;
        jugadores[i].second = goles;
    }
    for(int i = 0; i < n; i++)
    {
        cout << jugadores[i].first << ' ';
    }
    */

    /*
    vector<pair<string, int>> jugadores(n);
    string nombre;
    int goles;
    for(int i = 0; i < n; i++)
    {
        cin >> nombre;
        cin >> goles;
        // jugadores[i] = make_pair(nombre, goles);
        // jugadores.push_back(make_pair(nombre, goles));
    }
    for(int i = 0; i < n; i++)
    {
        cout << jugadores[i].first << ' ';
    }
    */
    return 0;
}