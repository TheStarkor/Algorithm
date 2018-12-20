#include <iostream>
using namespace std;
int mod = 1000000000;
long long d[201][201];

int main(){
	int n, k;
	cin >> n >> k;
	d[0][0] = 1;
	for (int i=1;i<=k;i++){
		for (int j=0;j<=n;j++){
			for (int l=0;l<=j;l++){
				d[j][i] += d[j-l][i-1];
				d[j][i] %= mod;
			}
		}
	}
	cout << d[n][k];
}