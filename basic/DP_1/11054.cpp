#include <iostream>
using namespace std;
int d[1001][2], res[1001];

int max(int n){
	int max = 0;
	for (int i=1;i<=n;i++) if (res[i]>max) max = res[i];
	return max;
}

int main(){
	int n, s[1001];
	cin >> n;
	for (int i=1;i<=n;i++) cin >> s[i];
	for (int i=1;i<=n;i++){
		d[i][0] = 1;
		d[n-i+1][1] = 1;
		for (int j=1;j<i;j++){
			if (s[j] < s[i] && d[j][0] + 1 > d[i][0]) d[i][0] = d[j][0] + 1;
		}
		for (int j=n;j>n-i+1;j--){
			if (s[j] < s[n-i+1] && d[j][1] + 1 > d[n-i+1][1]) d[n-i+1][1] = d[j][1] + 1;
		}
	}
	for (int i=1;i<=n;i++) res[i] = d[i][0] + d[i][1] - 1;
	cout << max(n);
}