Código del Problema Area de un Triangulo (Operaciones Básicas)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    float base, altura, area = 0;
    cin >> base >> altura;
    area = (base * altura) / 2;
    cout << fixed << setprecision(2) << area;

}