#include<iostream>
#include<string>
#include<cctype>

using namespace std;

bool longitud = false, vocal = false, num = false, charConsecutivos = true;

bool isVocal(char a){
    char b = tolower(a);
    return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u';
}

int main (){
    int n; cin >> n;

    char con[n];

    if(n >= 12) longitud = true;

    for(int i = 0; i < n; i++){
        cin >> con[i];
        
        if(longitud){
            
            if(vocal == false && isVocal(con[i])) vocal = true;
            if(num == false && isdigit(con[i])) num = true;

            if(i != 0 && charConsecutivos && con[i-1] == con[i]) charConsecutivos = false;

        }
    }

    cout << ((longitud && vocal && num && charConsecutivos)? "FUERTE": "DEBIL");
    return 0;
}