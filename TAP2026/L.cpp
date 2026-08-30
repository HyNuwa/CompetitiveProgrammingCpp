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

struct NODO{
    char c;
    NODO *prev = NULL;
    NODO *next = NULL;
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
    NODO lista;
    cin >> lista.c;
    
    

    int n= 0;
    while(true){
        n++;
        NODO temp;
        
        cin >> temp.c;

        
        
        if(cin.peek() == '\n') break;
    }


    NODO rec = lista;
    while(rec.next != NULL){
        cout << rec.c;

        rec = *rec.next;
    }

    

    



}