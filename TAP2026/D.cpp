#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



string resta(string n) {
    string salida;
    for(char c: n){
        if()

        salida = salida + to_string(int(c)-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string n;
    cin >> n;
    


    int n, cont = 0;
    ll suma ;
    cin >> n;

    int decimal = to_string(n).length();

    int a = 0;
    
        
    while(n != 0)
    {
        suma =(1 - pow(10, decimal)) / -9;
        
        a = n-suma;
        if(a < 0){
            decimal -= 1;
        }else{
            n = a;
            cont++;
        }
    }

    cout << cont;
    
}