#include<bits/stdc++.h>
using namespace std;

void eliminarEspacios(string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            s.erase(s.begin()+i);
            i--;
        }
    }
}

bool isPalindrome(string s){
    string aux = s;
    reverse(s.begin(), s.end());
    return aux == s;
}

int main(){
    string f1, f2, f3, f4;
    getline(cin, f1);
    fflush(stdin);
    getline(cin, f2);
    fflush(stdin);
    getline(cin, f3);
    fflush(stdin);
    getline(cin, f4);
    
    string anio1 = f1.substr(0, 4);
    
    int anio11 = stoi(anio1);
    
    string anio2 = f2.substr(0, 4);
    int anio12 = stoi(anio2);
    
    string anio3 = f3.substr(0, 4);
    int anio13 = stoi(anio3);
    
    string anio4 = f4.substr(0, 4);
    int anio14 = stoi(anio4);
    
    f1 = f1.substr(6, f1.size()-6);
    f2 = f2.substr(6, f2.size()-6);
    f3 = f3.substr(6, f3.size()-6);
    f4 = f4.substr(6, f4.size()-6);
    
    cout << "Anio 1: " << anio11 << endl;
    cout << "Pais: " << f1 << endl;
    cout << "Anio 2: " << anio12 << endl;
    cout << "Pais: " << f2 << endl;
    cout << "Anio 3: " << anio13 << endl;
    cout << "Pais: " << f3 << endl;
    cout << "Anio 4: " << anio14 << endl;
    cout << "Pais: " << f4 << endl;
    
    
    
    ///////////////////////////////
    
    
    
    string s;
    getline(cin, s);
    eliminarEspacios(s);
    if(isPalindrome(s)) cout << "Es palindromo " << endl;
    else cout << "No lo es" << endl;
}