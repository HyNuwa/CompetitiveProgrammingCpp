#include <iostream>

using namespace std;

int main() {
    bool apto = false;
    int a,b,c;
    int cont=0;
    cin >> a >> b >> c;

    if((a+b)==c){
        cont++;
    }

    cin >> a >> b >> c;

    if((a-b) == c){
        cont++;
    }

    cin >> a >> b >> c;

    if((a*b) == c){
        cont++;
    }

    if(cont==3){
        cout<< "APTO";
    }else if(cont==2){
        cout << "TRAUMA";
    }else{
        cout<< "NO APTO";
    }
    return 0;
}