#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;
   // Defición de un vector:
   vector<int> v(n);
   // Ingreso de datos al vector:
   for(int i = 0; i < n; i++)
   {
       cin >> v[i];
   }
   // Mostrar los elementos del vector:
   for(int i = 0; i < n; i++)
   {
       cout  <<  v[i] << " " ;
   }
   cout << endl;
   // Ahora con iteradores
   vector<int> :: iterator it;

   for(it = v.begin() ; it != v.end(); it++)
   {
       cout << (*it) << " ";
   }

}