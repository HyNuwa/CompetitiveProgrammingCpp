#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    //El juez me tiraba error porque lo tenia en float y no en double
    //El problema es que el resultado era muy grande y no cabia en float
    double x;
    cin >> x;
    
    double y = pow((pow(x-1, 2) + 3*x), 3) + 3*pow(x, 2);
    cout << fixed << setprecision(2) << y;
    
    return 0;
}