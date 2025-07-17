#include <bits/stdc++.h>
using namespace std;

bool es_primo(int n)
{
    if (n <= 1) return false;
    for (int i=2; i*i<=n; i++)
    {
        if (n%i == 0) return false;
    }
    return true;

}

int main()
{

 int n = 1000000;
 for(int i=1; i<=n; i++)
 {
     if(es_primo(i) == true)
     {
         cout << i;
     }
 }

}