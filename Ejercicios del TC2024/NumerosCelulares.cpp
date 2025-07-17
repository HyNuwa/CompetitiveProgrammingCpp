#Código visto en clase de números de celulares (Clase 24/07/24):
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, cantidad=0;
    cin >> n;
    // vector para guardar todos los num de celulares
    vector<int> numeros(n);
    //Vector que contendrá los num de celulares convertidos a string
    vector<string> snumeros(n);
    //Vector para almacenar las caracteristicas
    vector<string> caracteristicas(n);

    // Ingresamos los num de celulares
    for(int i=0; i < n; i++)
    {
        cin >> numeros[i];
        //Convierto a string:
        snumeros[i] = to_string(numeros[i]);
        caracteristicas[i] = snumeros[i].substr(0,3);
    }
    for (int i =0; i <n; i++)
    {
        if (caracteristicas[i] == "388")
        {
            cantidad++;
        }
    }
    cout << cantidad;
}