#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, ingreso;
    cin >> n;
    vector<string> codigos(n);
    //Creamos un vector de pares
    // la primer parte para el num de ingreso
    // la segunda parte para todo el codigo
    vector<pair<int,string>> conjunto(n);

    //Ingreso de los codigos completos
    for(int i = 0; i < n; i++)
    {
        cin >> codigos[i];
    }

    // Tomar los ultimos 3 digitos, que corresponden al numero de Ingreso
    string aux;
    for(int i=0; i<n; i++)
    {
        aux = codigos[i].substr(codigos[i].size()-3, n);
        ingreso = stoi(aux);
        conjunto[i].first = ingreso;
        conjunto[i].second = codigos[i];

    }

    //Ordenamos el vector por numero de ingreso, esto el first del vector de pares
    sort(conjunto.begin(),conjunto.end());

    // Mostramos solo el second, osea el codigo completo
    for(int i = 0; i < n; i++)
    {
        cout << conjunto[i].second << " ";
    }
}