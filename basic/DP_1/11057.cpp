#include <iostream>
using namespace std;

int main(){
	int n, mod = 10007;
	long long ans = 0, d[1001][10];
	cin >> n;
	for (int i=0;i<=9;i++) d[1][i] = 1;
	for (int i=2;i<=n;i++){
		for (int j=0;j<=9;j++){
			d[i][j] = 0;
			for (int k=0;k<=j;k++) d[i][j] += d[i-1][k];
			d[i][j] %= mod;
		}
	}
	for (int i=0;i<=9;i++) ans += d[n][i];
	ans %= mod;
	cout << ans;
}