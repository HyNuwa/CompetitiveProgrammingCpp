#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;

  for(int caso=0; caso<t; caso++){
    long long n;
    cin>>n;

    if(n >= 10){
        cout<<"00"<<endl;
    } else {
        int f=1;
        for(int i = 1; i <= n; i++){
            f *= i;
        }
        if(f < 10){
            cout<<f<<endl;
        } else {
            f %= 100;
            if(f < 10) cout<<"0";
            cout<<f<<endl;
        }
    }
}
}