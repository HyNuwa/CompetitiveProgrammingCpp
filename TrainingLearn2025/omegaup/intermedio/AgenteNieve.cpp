#include <bits/stdc++.h>

using namespace std;
int main()
{

    
    int n;
    cin >> n;
    deque<int> tubo;

    for (int i = 0; i < n; i++)
    {
        int chocolate;
        cin >> chocolate;
        tubo.push_back(chocolate);

    }

  
    int acumulador = 0;
    int dias = 1;
    while(n != 0){
        int inicio = tubo.front();
        int final = tubo.back();
        if(inicio < final){
            acumulador += inicio*dias;
            tubo.pop_front();
        } else {
            acumulador += final*dias
            ;
            tubo.pop_back();
        }
        n--;
        dias++;
    }

    cout << acumulador << endl;
    return 0;
}