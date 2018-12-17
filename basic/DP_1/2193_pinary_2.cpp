#include <iostream>
using namespace std;
long long d[91] = {0,1,1,2,};

long long pinary(int n){
	if (d[n] > 0) return d[n];
	d[n] = pinary(n-1) + pinary(n-2);
	return d[n];
}

int main(){
	int n;	
	cin >> n;
	cout << pinary(n);
}