#include <iostream>
using namespace std;
int d[1000001];

int count(int n){
	int tmp;
	if (n==1) return 0;
	if (d[n] > 0) return d[n];
	d[n] = count(n-1) + 1;
	if (n%2 == 0){
		tmp = count(n/2) + 1;
		if (d[n] > tmp) d[n] = tmp;
	}
	if (n%3 == 0){
		tmp = count(n/3) + 1;
		if (d[n] > tmp) d[n] = tmp;
	}
	return d[n];
}

int main(){
	int n;
	cin >> n;
	cout << count(n);
	return 0;
}