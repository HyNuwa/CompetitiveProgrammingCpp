#include <bits/stdc++.h>

using namespace std;
int main(){
    string contraseña;
    cin >> contraseña;

    if(contraseña.length() >= 8 && contraseña.length() <= 16){
        for(int i=0; i<contraseña.length(); i++){
            cout << '*';
        }
    }else if(contraseña.length() < 8){
        cout << "CORTA";
    }else{
        cout << "LARGA";
    }

    return 0;
}