#include <iostream>
using namespace std;
int d[1001];

int max(int n){
	int max = 0;
	for (int i=1;i<=n;i++) if (d[i]>max) max = d[i];
	return max;
}

int main(){
	int n, s[1001];
	cin >> n;
	for (int i=1;i<=n;i++) cin >> s[i];
	for (int i=n;i>=1;i--){
		d[i] = 1;
		for (int j=n;j>i;j--){
			if (s[j] < s[i] && d[j]+1 > d[i]) d[i] = d[j] + 1;
		}
	}
	cout << max(n);
}