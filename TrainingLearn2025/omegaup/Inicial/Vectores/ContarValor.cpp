#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> v(n);

  for(int i=0; i<n; i++){
    cin >> v[i];
  }

  int k;
  cin >>k;
  //Busqueda del valor K
  int contarK;
  for(int i=0; i<n; i++){
    if(v[i]==k){
      contarK+=1;
    }
  }
  cout<<contarK;

  return 0;
}