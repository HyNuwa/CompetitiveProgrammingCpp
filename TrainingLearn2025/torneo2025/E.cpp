#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ingredientes(n);
    map<int, int> habitacion_ingrediente;
    int ingrediente;
    int tiempo;
    for (int i = 0; i < n; i++)
    {
        cin >> ingrediente;
        habitacion_ingrediente.insert({ingrediente, 0});
        ingredientes[i] = ingrediente;

    }
    for (int i = 0; i < n; i++)
    {
        cin >> tiempo;
        if(habitacion_ingrediente.count(ingredientes[i])){
            habitacion_ingrediente[ingredientes[i]] += tiempo;
        }
    }
    // Mostrar los datos del pair
    //auto it = habitacion_ingrediente.end();

    //cout << (*it).second << endl;

       // Mostrar los datos del pair
    map<int, int>::iterator it;
    int mayor = 0;
    for (it = habitacion_ingrediente.begin(); it != habitacion_ingrediente.end(); it++)
    {
        if((*it).second > mayor){
            mayor=(*it).second;
        
        }
    }
    
    cout << mayor << endl;
    return 0;
}