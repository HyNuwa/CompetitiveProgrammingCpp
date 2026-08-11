#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //double precision is used to avoid overflow in large calculations
    double x, y;
    cin >> x >> y;
    double formula;

    if(((x*y)+(3*y)) == 0 || 5-x == 0) {
        cout << "IMPOSIBLE" << endl;
    }else{
        formula = ((pow(x,3))-(x*y)+((5-y)/(5-x)))/((x*y)+(3*y));
        cout << fixed << setprecision(3) << formula << endl;
    }

    return 0;
}