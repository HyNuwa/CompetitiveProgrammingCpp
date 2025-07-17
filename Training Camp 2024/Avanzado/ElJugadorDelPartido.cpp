#include <iostream>
#include <map>
#include <string>

using namespace std;
//NO TERMINADO
int main(){
	vector<int> vectorVotos1, vectorVotos2;
	map<string, int> jugadores;
	int n, valor, votos1tiempo, votos2tiempo;//valor: votos
	int voto,puesto1,puesto2, puesto3, suma=0, contador=0, maxNumeroVotos; 
	string llave;//jugador
	cin>>n;//cant jugadores
	
	// Iterador para recorrer el vector
    for(int i=0; i<n; i++){
    	cin>>llave>>valor;
    	jugadores[llave]=valor;
	}
	
	cin>>votos1tiempo>>votos2tiempo;
    
	for(int i=0; i<votos1tiempo; i++){
		cin>>voto;
		//if(voto>(it_begin->second) && voto<(it_end->second)){}
		vectorVotos1[i]=voto;
		contador++;
		if (vectorVotos1[i] > suma) {
                suma = vectorVotos1[i];
                maxNumeroVotos = votosOrdenados[i];
        }
	}
	
	for(int i=0; i<votos2tiempo; i++){
		cin>>voto;
		//if(voto>(it_begin->second) && voto<(it_end->second)){}
		vectorVotos2[i]=voto;
	}
    
    
	
	return 0;
}