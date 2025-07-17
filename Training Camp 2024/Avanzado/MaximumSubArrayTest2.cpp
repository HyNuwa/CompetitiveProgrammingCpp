#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	//cout << "Ingrese la cantidad de elementos: ";
	cin>>n;
	
	vector<int> a(n);  // Usar std::vector para almacenamiento dinámico
	//cout << "Ingreso elementos:";
	for(int i=0; i<n;i++){
		cin >> a[i];
	}
	
	long long ans = a[0], sum=0;
	
	for(int i=0; i<n; i++){
		sum = max(sum, 0LL);
		sum += a[i];
		ans = max(ans, sum);
	}
	cout<<ans<<"\n";
	
	return 0;
}