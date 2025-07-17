#include<iostream>
using namespace std;

int main(){
	int largo, contador;
	string cadena;
	cin>>cadena;
	largo= cadena.length();
	
	for(int i=1; i<largo-1; ++i){
		if(cadena[i-1] == cadena[i+1] && cadena[i] != cadena[i-1]){
			contador++;
		}
	}	
	
	cout<<contador;
	
	return 0;
}