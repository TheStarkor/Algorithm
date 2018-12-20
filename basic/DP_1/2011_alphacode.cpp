#include <iostream>
using namespace std;
int mod = 1000000;
int d[5001] = {1,};

int main(){
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	for (int i=1;i<=n;i++){
		int num = s[i] - '0';
		if (num >= 1 && num <= 9) d[i] += d[i-1];
		d[i] %= mod;
		if (i == 1) continue;
		num = (s[i-1]-'0') * 10 + (s[i] - '0');
		if (num >= 10 && num <= 26) d[i] += d[i-2];
		d[i] %= mod;
	}
	cout << d[n];
}