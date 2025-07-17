#include<string>
#include<iostream>

using namespace std;

int main()
{
    int c=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if((s[0+i]+s[1+i]+s[2+i])==242){
            c=c+1;

        cout<<c;
            break;
        }
        if((s[0+i]+s[1+i]+s[2+i])==230){
            c=c+2;

        cout<<c;
            break;
        }
        if((s[0+i]+s[1+i]+s[2+i]+s[3+i])==318){
            c=c+3;

        cout<<c;
            break;
        }
    }

    return 0;
}
/*242
230
318
*/
#include <bits/stdc++.h>
#include <vector>
    using namespace std;

    int main() {
        int suma=0,n;
        vector<int> v1;
        while((cin>>n) ){
            if(n>=10 && n<=100){
                v1.push_back(n);
            }
            if(n<0){
                for(int i=0;i<v1.size();i++){
                    suma=suma+v1[i];
                }

                cout<<suma;
                break;
            }
        }


        return 0;
    }