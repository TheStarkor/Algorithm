#include <iostream>
using namespace std;

int main(){
	int n, d[100001];
	cin >> n;
	for (int i=1;i<=n;i++){
		d[i]=i;
		for (int j=1;j*j<=i;j++){
			if ((1+d[i-j*j])<d[i]) d[i] = 1 + d[i-j*j];
		}
	}
	cout << d[n];
}