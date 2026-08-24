#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include<iomanip>
using namespace std;

int main() {
    double e,c, n;
    cin >> e >> c >> n;

    if((n*30)+e<c){
        cout <<-1;
    }else {
        float intermedio = float(-(e-c)/30);
        double result = ceil(abs(intermedio)); 
        if( result == -1) result = 0;
        cout << double(result);
    }
    
    
    
    return 0;
}