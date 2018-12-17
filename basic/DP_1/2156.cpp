#include <iostream>
#define max(a,b) (((a)>(b))?(a):(b))  
using namespace std;

int main(){
	int n, d[10001], s[10001];
	cin >> n;
	for (int i=1;i<=n;i++) cin >> s[i];
	d[1] = s[1];
	d[2] = s[1] + s[2];
	d[3] = max(max(s[1]+s[2],s[1]+s[3]),s[2]+s[3]);
	for (int i=4;i<=n;i++) d[i] = max(max(d[i-1],d[i-2]+s[i]),d[i-3]+s[i-1]+s[i]);
	cout << d[n];
}