#include <iostream>
using namespace std;

int main(){
	int n;
	long long ans = 0, d[101][10] = {0}, mod = 1000000000;
	cin >> n;
	for (int i=1;i<=9;i++) d[1][i] = 1;
	for (int i=2;i<=n;i++){
		for (int j=1;j<9;j++){
			d[i][j] = 0;
			d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % mod;
		} 
		d[i][0] += d[i-1][1] % mod;
		d[i][9] += d[i-1][8] % mod;
	}
	for (int i=0;i<=9;i++) ans += d[n][i];
	ans %= mod;
	cout << ans;
}