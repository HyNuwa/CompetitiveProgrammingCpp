#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include<iomanip>

using namespace std;

int main() {
    short n;
    cin >> n;

    if(n>=6){
        cout << "aprobado";
    }else{
        cout << 6-n;
    }
    
    
    return 0;
}