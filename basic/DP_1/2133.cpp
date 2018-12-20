#include <iostream>
using namespace std;
long long d[31];
int main(){
	int n;
	cin >> n;
	d[0] = 1;
	for (int i=2;i<=n;i+=2){
		d[i] = d[i-2] * 3;
		for (int j=4;i-j>=0;j+=2) d[i] += d[i-j] * 2;
	}
	cout << d[n];
}