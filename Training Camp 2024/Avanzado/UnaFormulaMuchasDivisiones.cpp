#include <iostream>
#include <cmath>
using namespace std;

int main(){

	float x, y, z;
	cin>>x>>y;
	
	z=( (((pow(x,3) + pow(x,2))/(pow(y,2)-y)) - ((x/y)+5)) /(2*x) );
	
	cout<<z;
	
	return 0;
}