#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float x, y, z;
    cin >> x >> y;

    float numerador1 = pow(x, 3) + pow(x, 2); // x^3 + x^2
    float denominador1 = pow(y, 2) - y;       // y^2 - y
    float fraccion1 = numerador1 / denominador1; // (x^3 + x^2) / (y^2 - y)
    
    float fraccion2 = x / y;                  // x / y

    z = (fraccion1 - fraccion2 + 5) / (2 * x);

    cout << z << endl;

    return 0;
}
