#Código del Problema Vector Dominante visto en clase
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    // Ingresamos el tamanio de ambos vectores:
    cin >> n;
    vector<int> v1(n);
    vector<int> v2(n);
    // Para Ingresar los valores del primer vector:
    for(int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    //Para Ingresar los valores del segundo vector:
    for(int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }

    // Ver si v1 es dominante
    bool dominante = true;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] <= v2[i] )
        {
            dominante = false;
            break;
        }
    }

    if (dominante == true)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

}