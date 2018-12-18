#include <iostream>
using namespace std;
long long d[100001];

long long max(int n){
	long long max = d[1]; // max value..
	for (int i=1;i<=n;i++) if (d[i]>max) max = d[i];
	return max;
}

int main(){
	int n, s[100001];
	cin >> n;
	for (int i=1;i<=n;i++) cin >> s[i];
	for (int i=1;i<=n;i++){
		d[i] = s[i];
		if (d[i-1] + s[i] >= s[i]) d[i] = d[i-1] + s[i];
	}
	cout << max(n);
}