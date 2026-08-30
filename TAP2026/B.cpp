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



bool isVocal(char c) {
    return (c == 'A'|| c == 'E'|| c == 'I'|| c == 'O'|| c == 'U');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string cad;
    cin >> cad;
    int cont = 0, ind;
    if(cad.length() < 4){
        cout << "-";
        return 0;
    }

    for(int i = 1; i < cad.length()-3; i++){

        if(cad[i] == 'G' && cad[i+1] == 'A' && cad[i+2] == 'S' && cad[i-1] == cad[i+3] && isVocal(cad[i-1])){
            ind = i;
            i+=4;
            cont++;
        }

    }
    if(cont > 1){
        cout << "+";
    } else if(cont == 0){
        cout << "-";
    }
    else {
        //cout << cad.substr(0, ind);
        for(int i = 0; i < cad.length(); i++){
            if(i > ind-1 && i < ind+4) continue;
            cout << cad[i];
        }
    }

    return 0;
}
