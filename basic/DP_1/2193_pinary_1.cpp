#include <iostream>
using namespace std;
long long d[91] = {0,1,1,2,};

void make(int n){
	for (int i=4;i<=n;i++){
		for (int j=1;j<i-1;j++) d[i] = d[i] + d[j];
		d[i]++;
	}
}

int main(){
	int n;
	cin >> n;
	if (n > 3) make(n);
	cout << d[n];
}