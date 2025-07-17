#include <iostream>

using namespace std;

int main(){
	//int array[] = {25, 30, 22, }; // Inicializa con 3 valores
	int n;
	cout << "Ingrese la cantidad de elementos: ";
	cin>>n;
	
	int array[n];
	cout << "Ingreso elementos:";
	for(int i=0; i<n;i++){
		cin >> array[i];
	}
	
	int best = 0, sum = 0;
	for (int k = 0; k < n; k++) {
		sum = max(array[k],sum+array[k]);
		best = max(best,sum);
	}
	cout << best << "\n";
	
	//ALL TEST WRONG
	return 0;
}