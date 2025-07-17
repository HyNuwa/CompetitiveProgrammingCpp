#include <bits/stdc++.h>
    using namespace std;
    bool es_primo(int n)
{
    if (n <= 1) return false;
    for (int i=2; i*i<=n; i++)
    {
        if (n%i == 0) return false;
    }
    return true;

}


    int main() {
        int a,n,cont=0,series=0;
        cin>>a;
        for(int i=0;i<a;i++){
            cin>>n;
            if(es_primo(n)){
                cont++;
            }
            else{
                cont=0;
            }
            if(cont==2){
                series++;
            }
        }
        cout<<series;
    }